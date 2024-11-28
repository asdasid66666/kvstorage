/*1.hashmap中创立一个新节点
  2.kv写缓冲中写入数据并序列化
  3.缓冲区满之后写入磁盘大文件*/
#include <stdio.h>
#include <vector>
#include "global.h"
// put接口的样子是： put key val 放入一组键值对
void put(int key, void *val, int thread_num, int type) // 整个流程是向大文件中写入一个键值对 此时的val只是一个数字
{
  // 先建立一个新结点
  valstr note;
  note.num = val;
  note.type = type; // 0表整形 1表浮点 2表字符串
  note.soffset = 0;
  note.loffset = 0; // 定义一个小记录
  kvmap notemap;
  notemap.val = note;
  notemap.valoffset = 0;
  notemap.location = -1;
  notemap.exist = 0; // 因为写过程最后缓冲区写入后会清空数据 所以写过程最终数据一定不在内存 只有读过程才会数据存入内存
  notemap.length = 0;
  notemap.ifdel = 0;

  int loffset = voff + 20000 * (5 * write_file_num[thread_num] + thread_num); // 记录所在缓冲区在大文件的偏移可以直接算出来
  int soffset = vboff[thread_num];                                            // 记录在缓冲区里的偏移量为该缓冲区上一次写完之后的偏移

  if (insertmap(key, notemap) == false) // 先在hashmap中创立一个新结点 此时结点还有很多元素没有填
  {
    printf("writing %d to hashmap failed!\n", key);
  }
  addloff(key, loffset);
  addsoff(key, soffset);
  addvaloff(key, soffset, loffset);
  addlen(key, vallen(&note)); // hashmap中添加长度信息
  // 初始节点插入hashmap之后再将未初始化的信息补全
  if (kbnum[thread_num] < 1000) // 若线程对应的kv缓冲区没有满
  {
    writebuf(key, &note, thread_num);
    printf("the key %d and its corresponding value have been written to buffer!\n", key);
  }
  else
  {                                  // 若kv写缓冲区已满
    writekeyval(Filefd, thread_num); // 缓冲区向大文件写入
    // 清空线程对应的kv写缓冲区
    kbnum[thread_num] = 0;
    kboff[thread_num] = 0;
    vboff[thread_num] = 0;
    keybuf_Array[thread_num].clear();
    valbuf_Array[thread_num].clear();
    writebuf(key, &note, thread_num); // 将值写入清空后的缓冲区
    printf("the key %d and its corresponding value have been written to buffer!\n", key);
  }
  return;
}