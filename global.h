// 按照数据结构 以及多个结构文件的模式分块整理  待整理
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstddef>
#include "Intmessage.pb.h"

struct valstr
{
    void *num;
    int type; // 0表整形 1表浮点型 2表字符串型
    int soffset;
    int loffset; // 分别是小记录的val放在缓冲和缓冲放在大文件中的偏移 key不需要计算偏移
};
struct kvmap // map中的结点结构体
{
    valstr val;
    int valoffset; // val在大文件中的偏移量
    int location;  // val在readbuf中的位置 并不直接是指针
    int exist;     // 1表示val在内存 0表不在
    int length;    // 这是序列化之后的length（二进制数据的长度）
    int ifdel;     // 0表示没删除 1表示被删除
}; // key值得单独放在外面 因为hashmap需要用int key找kvmap
typedef struct LNode
{
    int key;
    int type;
    int location; // 记录在readbuf中的位置
    int ifdel;    // 0表示没删除 1表示被删除
    int length;   // 设置!!!!!!
    struct LNode *next;
    struct LNode *prior;
} *DLinkList, LNode; // CACHE里面结点的结构体
// 定义put队列节点结构
typedef struct pNode
{
    void (*putfunction)(int, void *, int, int); // 每个队列结点只是存放指向指令函数的指针 并非是函数本身！
    int key;
    void *value;
    int id;
    int valtype;
    struct pNode *next;
} pNode;
// 定义get队列节点结构
typedef struct gNode
{
    void (*getfunction)(int, int);
    int key;
    int id;
    struct gNode *next;
} gNode;
// 定义del队列节点结构
typedef struct dNode
{
    void (*delfunction)(int);
    int key;
    struct dNode *next;
} dNode;
// 定义put队列结构
typedef struct pQueue
{
    pNode *front; // 指向队列头部
    pNode *rear;  // 指向队列尾部
} pQueue;
// 定义get队列结构
typedef struct gQueue
{
    gNode *front; // 指向队列头部
    gNode *rear;  // 指向队列尾部
} gQueue;
// 定义del队列结构
typedef struct dQueue
{
    dNode *front; // 指向队列头部
    dNode *rear;  // 指向队列尾部
} dQueue;

extern std::unordered_map<int, kvmap> mymap; // 建立一个hashmap 无序关联存储

extern std::array<std::vector<std::byte>, 5> keybuf_Array; // 5个写线程的k缓冲区数组
extern std::array<std::vector<std::byte>, 5> valbuf_Array;
extern std::vector<std::byte> readbuf; // 读缓冲 不限长度

extern int *kbnum; // k写缓冲的元素数量
extern int *kboff; // k写缓冲的偏移量
extern int *vboff; // v写缓冲的偏移量
extern LNode *head;
extern LNode *tail;            // cache双链表的头尾指针
extern int Filefd;             // 大文件文件描述符
extern const int voff;         // voff为最近存入的value距大文件开头100MB的偏移量 留给key100MB的空间
extern int nodenum;            // 用来记录cache双向链表中的结点数目
extern int *write_file_num;    // 每个数组元素的值表示对应的写线程向大文件中写入第几次
extern int *write_readbuf_num; // 每个数组元素的值表示对应的读线程向readbuffer中写入第几次

extern pthread_mutex_t cacheMutex; // cache操作锁
extern pthread_mutex_t mapMutex;   // hashmap的锁 用于写线程独立进行map节点插入操作

int createfile(std::string filename);
void writekeyval(int Filefd, int thread_num);
unsigned char *getv(int Filefd, int valoffset, int length, int thread_num); // 存储层接口

void writebuf(int key, valstr *val, int thread_num);
int vallen(valstr *val);                                            // 写缓冲接口
int pushrebuf(unsigned char *read_buf, int thread_num, int length); // 读缓冲接口
// 缓冲层接口

int ifkeyexist(int key);
void addnode(int key, int location);
void movenode(int key);
void changeifdel(int key);
int LRUifdeleted(int key);
int LRUtype(int key); // 以上为cache接口
int findval(int key); // HASHMAP中的接口 输入指定的key返回对应的val的偏移量
bool insertmap(int key, kvmap notemap);
void addmem(int key, int location);
int getaddr(int key);
int getlen(int key);
void setdel(int key);
int mapifdeleted(int key);
int findtype(int key);
int Hashifexist(int key);
void addlen(int key, int length);
void addsoff(int key, int soff);
void addloff(int key, int loff);
void addvaloff(int key, int soff, int loff); // 以上为hashmap接口
// 索引层接口

void put(int key, void *val, int thread_num, int type);
void get(int key, int thread_num);
void del(int key);
// 接口层（用户层）接口

pQueue *createpQueue();
gQueue *creategQueue();
dQueue *createdQueue();
bool ispEmpty(pQueue *queue);
bool isgEmpty(gQueue *queue);
bool isdEmpty(dQueue *queue);
void penqueue(pQueue *queue, void (*value)(int, void *, int, int), int key, void *val, int id, int valtype);
void genqueue(gQueue *queue, void (*value)(int, int), int key, int id);
void denqueue(dQueue *queue, void (*value)(int), int key);
pNode *depqueue(pQueue *queue);
gNode *degqueue(gQueue *queue);
dNode *dedqueue(dQueue *queue);
// 队列的接口

void *put_thread_function(void *arg);
void *get_thread_function(void *arg);
void *del_thread_function(void *arg); // 线程的接口函数
