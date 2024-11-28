/*读数据的第一种情况
  1.用户输入 get k
  2.到LRUcache中查找对应的k 未找到
  3.在hashmap中找k 发现v不在内存 找v在大文件的位置
  4.从磁盘读v存读缓存并反序列化
  5.修改hashmap
  6.LRUcache中加入新结点
*/
/*读数据的第二种情况
  1.用户输入 get k
  2.到LRUcache中查找对应的k 未找到
  3.在hashmap中找k 发现v在内存
  4.LRU中尾部增加结点
  5.修改hashmap
  6.读缓存中取v并返回索引层
  7.索引层返回v给用户
*/
/*读数据的第三种情况
  1.用户输入 get k
  2.到LRUcache中查找对应的k 找到
  3.将该结点移动到LRU的尾部
  4.通过v的内存地址到读缓存中取v
  5.取的v返回到索引层
  6.索引层返回给用户
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "global.h"
#include "Intmessage.pb.h"
// get接口的样子是： get key通过用户输入的key读出来对应的val

// 注：之后要考虑边界不成立的报错情况！！
void get(int key, int thread_num) // 返回的是key对应的val
{
  if (ifkeyexist(key) == -1) // 当在LRUcache中未找到对应的k
  {
    if (Hashifexist(key) == 0) // k在hashmap中
    {
      if (mapifdeleted(key) == 1)
      {
        printf("the value of %d you want to get has been deleted!\n", key); // 表示用户要查找的v已经被删除了
        return;
      }
      else if (mapifdeleted(key) == 0) // 此时 要查找的v还没被删除
      {
        if (getaddr(key) == 0) // hashmap中k对应的v不在内存中--》》对应读过程的第一种情况
        {
          unsigned char *read_buf = getv(Filefd, findval(key), getlen(key), thread_num);
          if (read_buf == NULL) // 此时记录所在的缓冲区还没有写到磁盘大文件上
          {
            printf("the key%d and its corresponding value have been inserted in hashmap but haven't been writen to file!\n", key);
            return;
          }
          else // 此时记录已经在磁盘文件上了
          {
            int location = pushrebuf(read_buf, thread_num, getlen(key)); // 这是val在内存（读缓冲）中的地址
            addmem(key, location);                                       // 修改hashmap中结点的信息
            addnode(key, location);                                      // 在LRUcache中新增加结点
            a::voidMessage message;
            message.Clear(); // 返回反序列化之后的数据给用户
            void *dataptr = &readbuf[location];
            message.ParseFromArray(dataptr, static_cast<int>(getlen(key)));
            int type = findtype(key);
            printf("gfdlkgfdlg \n");

            if (type == 0) // val为整形时
            {
              printf("the corresponding value of %d is %d\n", key, message.int_num());
              return;
            }
            else if (type == 1) // val为浮点型时
            {
              printf("the corresponding value of %d is %f\n", key, message.float_num());
              return;
            }
            else if (type == 2) // val为字符串时
            {
              printf("the corresponding value of %d is %s\n", key, message.string_num().c_str());
              return;
            }
          }
        }
        else if (getaddr(key) == 1) // hashmap中k对应的v在内存中--》》对应读过程的第二种情况
        {
          int location = getaddr(key); // 这是val在内存（读缓冲）中的地址
          addnode(key, location);      // cache尾部新增结点
          a::voidMessage message;
          message.Clear(); // 返回反序列化之后的数据给用户
          void *dataptr = &readbuf[location];
          message.ParseFromArray(dataptr, static_cast<int>(getlen(key)));
          int type = findtype(key);
          if (type == 0) // val为整形时
          {
            printf("the corresponding value of %d is %d\n", key, message.int_num());
            return;
          }
          else if (type == 1) // val为浮点型时
          {
            printf("the corresponding value of %d is %f\n", key, message.float_num());
            return;
          }
          else if (type == 2) // val为字符串时
          {
            printf("the corresponding value of %d is %s\n", key, message.string_num().c_str());
            return;
          }
        }
      }
    }
    else
    {
      printf("the key %d you looking for haven't been put yet!\n", key); // key还没有被存储
      return;
    }
  }
  else // 当在LRUcache中找到对应的k--》》对应读过程的第三种情况
  {
    if (LRUifdeleted(key) == 1)
    {
      printf("the value of %d you want to get has been deleted!\n", key);
      return;
    } // 要查的结点已经被删除了
    else
    {
      int location = ifkeyexist(key); // 这是val在内存（读缓冲）中的地址
      movenode(key);                  // 将cache中的新查找结点移动到尾部
      a::voidMessage message;
      message.Clear(); // 返回反序列化之后的数据给用户
      void *dataptr = &readbuf[location];
      message.ParseFromArray(dataptr, static_cast<int>(getlen(key)));
      int type = LRUtype(key); // 这里是直接在LRU中找
      if (type == 0)           // val为整形时
      {
        printf("the corresponding value of %d is %d\n", key, message.int_num());
        return;
      }
      else if (type == 1) // val为浮点型时
      {
        printf("the corresponding value of %d is %f\n", key, message.float_num());
        return;
      }
      else if (type == 2) // val为字符串时
      {
        printf("the corresponding value of %d is %s\n", key, message.string_num().c_str());
        return;
      }
    }
  }
}