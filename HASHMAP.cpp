/*hash表中需要设置的接口（可以用部分map库定义的接口）：
  1.插入新结点 只填部分结构体元素信息
  2.查找时间戳最晚的val在大文件上的偏移量
  3.修改结构体元素信息 将val的内存地址以及val是否在内存中填充进去
  4.查找val的内存指针
  5.查找val的序列化之后的长度
  6.查找k对应的结点 并将结点中的是否被删除设为被删除
  7.在hashmap中找key 返回key结点的v是否被删除
  8.找key对应的val的数据类型Type
  9.查找hashmap中是否有Key结点
  10.修改结构体元素信息 将val序列化之后的长度填充进去
  11.修改结构体元素信息 将val的soffset填充进去
  12.修改结构体元素信息 将val的loff填充进去
  13.修改结构体元素信息 将val的valoffset填充进去*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "global.h"

// 只插入新结点 填结构体元素信息(部分信息不填)
bool insertmap(int key, kvmap notemap)
{
  // 用insert方式插入hashmap 这种方式当key相同而val不同时 自动覆盖之前的val 即会保存最新值
  pthread_mutex_lock(&mapMutex);
  if (mymap.insert({key, notemap}).second == false)
  {
    pthread_mutex_unlock(&mapMutex);
    return false;
  }
  pthread_mutex_unlock(&mapMutex);
  return true;
}

// 查找时间戳最晚的val在大文件上的绝对偏移量
int findval(int key) // hashmap上每个Key对应的val只存一个 且存的是最新的val
{
  pthread_mutex_lock(&mapMutex);
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key); // 迭代器it指向了key对应的结点
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return -1; // 查找失败
  }
  else
  {
    int a=it->second.valoffset;
    pthread_mutex_unlock(&mapMutex);
    return (a);
  }
 
}

// 修改结构体元素信息 将val的内存地址以及val是否在内存中填充进去

void addmem(int key, int location)
{
  pthread_mutex_lock(&mapMutex);
  // 还是先找到结点后填充信息
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key);
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return; // 查找失败
  }
  else
  {
    it->second.location = location;
    it->second.exist = 1;
    pthread_mutex_unlock(&mapMutex);
    return;
  }
}

// 查找val的内存指针 条件是一定在hashmap中
int getaddr(int key)
{
  pthread_mutex_lock(&mapMutex);
  // 还是先找到结点
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key);
  if (it->second.location == -1)
  {
    pthread_mutex_unlock(&mapMutex);
    return 0; // 代表还没有存入内存
  }
  else
  {
    pthread_mutex_unlock(&mapMutex);
    return 1;
  }
}

// 查找val的序列化之后的长度
int getlen(int key)
{
  pthread_mutex_lock(&mapMutex);
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key);
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return -1; // 查找失败
  }
  else
  {
    int a=it->second.length;
    pthread_mutex_unlock(&mapMutex);
    return a;
  }
}

// 查找k对应的结点 并将结点中的是否被删除设为被删除
void setdel(int key)
{
  pthread_mutex_lock(&mapMutex);
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key);
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return;
  }
  else
  {
    it->second.ifdel = 1;
    pthread_mutex_unlock(&mapMutex);
    return;
  }
}

// 在hashmap中找key 返回key结点的v是否被删除
int mapifdeleted(int key)
{
  pthread_mutex_lock(&mapMutex);
  // 还是先找到结点
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key);
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return -1; // 查找失败
  }
  else
  {
    int a=it->second.ifdel;
    pthread_mutex_unlock(&mapMutex);
    return a;
  }
}

// 找key对应的val的数据类型Type
int findtype(int key) // hashmap上每个Key对应的val只存一个 且存的是最新的val
{
  pthread_mutex_lock(&mapMutex);
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key); // 迭代器it指向了key对应的结点
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return -1; // 查找失败
  }
  else
  {
    int a=it->second.val.type;
    pthread_mutex_unlock(&mapMutex);
    return a;
  }
}

// 查找hashmap中是否有Key结点
int Hashifexist(int key)
{
  pthread_mutex_lock(&mapMutex);
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key); // 迭代器it指向了key对应的结点
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return -1; // 查找失败
  }
  pthread_mutex_unlock(&mapMutex);
  return 0; // 查找成功
}

// 修改结构体元素信息 将val序列化之后的长度填充进去
void addlen(int key, int length)
{
  pthread_mutex_lock(&mapMutex);
  // 还是先找到结点后填充信息
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key);
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return; // 查找失败
  }
  else
  {
    it->second.length = length;
    pthread_mutex_unlock(&mapMutex);
    return;
  }
}

// 修改结构体元素信息 将val的soffset填充进去
void addsoff(int key, int soff)
{
  pthread_mutex_lock(&mapMutex);
  // 还是先找到结点后填充信息
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key);
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return; // 查找失败
  }
  else
  {
    it->second.val.soffset = soff;
    pthread_mutex_unlock(&mapMutex);
    return;
  }
}

// 修改结构体元素信息 将val的loff填充进去
void addloff(int key, int loff)
{
  pthread_mutex_lock(&mapMutex);
  // 还是先找到结点后填充信息
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key);
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return; // 查找失败
  }
  else
  {
    it->second.val.loffset = loff;
    pthread_mutex_unlock(&mapMutex);
    return;
  }
}

// 修改结构体元素信息 将val的valoffset填充进去
void addvaloff(int key, int soff, int loff)
{
  pthread_mutex_lock(&mapMutex);
  // 还是先找到结点后填充信息
  std::unordered_map<int, kvmap>::iterator it = mymap.find(key);
  if (it == mymap.end())
  {
    pthread_mutex_unlock(&mapMutex);
    return; // 查找失败
  }
  else
  {
    it->second.valoffset = soff + loff;
    pthread_mutex_unlock(&mapMutex);
    return;
  }
}
