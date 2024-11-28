#include <stdio.h>
#include <vector>
#include <time.h>
#include <pthread.h>
#include "global.h"
#include <unordered_map>
#include "Intmessage.pb.h"

#define MAX_KEY 50000000
#define MAX_VALUE 50000000
#define MAX_STRING_LEN 20

std::unordered_map<int, kvmap> mymap; // 建立一个hashmap 无序关联存储

std::array<std::vector<std::byte>, 5> keybuf_Array; // 5个写线程的k缓冲区数组
std::array<std::vector<std::byte>, 5> valbuf_Array;
std::vector<std::byte> readbuf; // 读缓冲 不限长度

int Filefd;
int *kbnum = (int *)calloc(5, sizeof(int)); // k写缓冲的元素数量
int *kboff = (int *)calloc(5, sizeof(int)); // k写缓冲的偏移量
int *vboff = (int *)calloc(5, sizeof(int)); // v写缓冲的偏移量
LNode *head = NULL;
LNode *tail = NULL;                                     // cache双链表的头尾指针
const int voff = 104857600;                             // voff为最近存入的value距大文件开头100MB的偏移量 留给key100MB的空间
int nodenum = 0;                                        // 用来记录cache双向链表中的结点数目
int *write_file_num = (int *)calloc(5, sizeof(int));    // 每个数组元素的值表示对应的写线程向大文件中写入第几次
int *write_readbuf_num = (int *)calloc(5, sizeof(int)); // 每个数组元素的值表示对应的读线程向readbuffer中写入第几次

pthread_mutex_t cacheMutex = PTHREAD_MUTEX_INITIALIZER; // cache操作锁
pthread_mutex_t mapMutex = PTHREAD_MUTEX_INITIALIZER;   // hashmap的锁 用于写线程独立进行map节点插入操作

// 随机生成一个整数
int generate_random_int()
{
  return rand() % MAX_VALUE;
}

// 随机生成一个浮点数
float generate_random_float()
{
  return (float)(rand() % MAX_VALUE) + (rand() % 100) / 100.0;
}

// 随机生成一个字符串
char *generate_random_string()
{

  int len = rand() % MAX_STRING_LEN + 1; // 随机生成字符串长度
  char *str = (char *)malloc(sizeof(char) * (len + 1));
  if (str == NULL)
  {
    return NULL;
  }
  for (int i = 0; i < len; i++)
  {
    str[i] = 'a' + (rand() % 26); // 随机字符
  }
  str[len] = '\0'; // 以空字符结尾
  return str;
}
int main()
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  Filefd = createfile("DAWENJIAN");
  int put_id = 0;
  int get_id = 0;
  // 对两个命令进行编号 并放入相应的命令队列中 del命令无需编号 因为只设置一个del队列
  pQueue p[5];
  gQueue g[5];                  // 队列数组中每个元素直接为一个队列
  dQueue d = (*createdQueue()); // 创建一个del队列
  pthread_t put_thread[5];      // 5个写线程
  pthread_t get_thread[5];      // 5个读线程
  pthread_t del_thread;         // 1个删除线程
  for (int i = 0; i < 5; i++)
  {
    p[i] = (*createpQueue());
  } // 创建五个put命令队列
  for (int j = 0; j < 5; j++)
  {
    g[j] = (*creategQueue());
  } // 创建五个get命令队列
  for (int i = 0; i < 5; i++)
  {
    if (pthread_create(&put_thread[i], NULL, put_thread_function, &p[i]) != 0)
    {
      perror("Failed to start putthread!\n");
    }
  } // 启动五个写线程 不断地从Put队列中取put并执行
  for (int j = 0; j < 5; j++)
  {
    if (pthread_create(&get_thread[j], NULL, get_thread_function, &g[j]) != 0)
    {
      perror("Failed to start getthread!\n");
    }
  } // 启动五个读线程 不断地从get队列中取get并执行
  if (pthread_create(&del_thread, NULL, del_thread_function, &d) != 0)
  {
    perror("Failed to start delthread!\n");
  } // 启动一个唯一的del线程
  // 先用随机发生器产生命令及参数
  while (true) // 每个循环产生一个命令
  {
    int command = rand() % 3;
    switch (command)
    {
    case 0: // put
    {
      // generate the key and value
      put_id++;
      int key = rand() % MAX_KEY;
      int valtype = rand() % 3;
      void *value;
      switch (valtype)
      {
      case 0:
      {
        value = malloc(sizeof(int));
        *(int *)value = generate_random_int(); // val为整形
        break;
      }
      case 1:
      {
        value = malloc(sizeof(float));
        *(float *)value = generate_random_float(); // 浮点型
        break;
      }

      case 2:
      {
        value = generate_random_string(); // 字符串型
        break;
      }
      } // 将put命令放入对应的队列中
      if (put_id % 5 == 0)
      {
        void (*put_function_pointer)(int, void *, int, int) = put;
        penqueue(&p[0], put_function_pointer, key, value, put_id % 5, valtype);
      }
      else if (put_id % 5 == 1)
      {
        void (*put_function_pointer)(int, void *, int, int) = put;
        penqueue(&p[1], put_function_pointer, key, value, put_id % 5, valtype);
      }
      else if (put_id % 5 == 2)
      {
        void (*put_function_pointer)(int, void *, int, int) = put;
        penqueue(&p[2], put_function_pointer, key, value, put_id % 5, valtype);
      }
      else if (put_id % 5 == 3)
      {
        void (*put_function_pointer)(int, void *, int, int) = put;
        penqueue(&p[3], put_function_pointer, key, value, put_id % 5, valtype);
      }
      else if (put_id % 5 == 4)
      {
        void (*put_function_pointer)(int, void *, int, int) = put;
        penqueue(&p[4], put_function_pointer, key, value, put_id % 5, valtype);
      } // 结束放置
      break;
    }
    case 1: // get
    {
      get_id++;
      int key = rand() % MAX_KEY;
      // 将get命令放入对应的队列中
      if (get_id % 5 == 0)
      {
        void (*get_function_pointer)(int, int) = get;
        genqueue(&g[0], get_function_pointer, key, get_id % 5);
      }
      else if (get_id % 5 == 1)
      {
        void (*get_function_pointer)(int, int) = get;
        genqueue(&g[1], get_function_pointer, key, get_id % 5);
      }
      else if (get_id % 5 == 2)
      {
        void (*get_function_pointer)(int, int) = get;
        genqueue(&g[2], get_function_pointer, key, get_id % 5);
      }
      else if (get_id % 5 == 3)
      {
        void (*get_function_pointer)(int, int) = get;
        genqueue(&g[3], get_function_pointer, key, get_id % 5);
      }
      else if (get_id % 5 == 4)
      {
        void (*get_function_pointer)(int, int) = get;
        genqueue(&g[4], get_function_pointer, key, get_id % 5);
      } // 结束放置
      break;
    }
    case 2: // del
    {
      int key = rand() % MAX_KEY;
      void (*del_function_pointer)(int) = del;
      denqueue(&d, del_function_pointer, key); // del命令直接放入del命令队列
      break;
    }
    default:
    {
      printf("Unknown command!\n");
    }
    } // end of switch(command)
  } // while(produce command)
  return 0;
}
