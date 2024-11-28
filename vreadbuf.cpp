/*1.读取从大文件中反序列化之后的val 并存入v读缓冲中
  2.删除指定的val
*/
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstddef>
#include "global.h"
int pushrebuf(unsigned char *read_buf, int thread_num, int length) // 返回的是指向这个数据的内存指针
{
  // 此时 read缓冲中的每个元素是一个二进制B 需要先定位要写入的位置
  int location = 20 * (5 * write_readbuf_num[thread_num] + thread_num); // 20是每一块的大小 之后的括号是块数
  if(location+length+1>readbuf.size())
  {
    readbuf.resize(location+length+1);
  }
  for (int i = 0; i < length; i++)
  {
    readbuf[i + location] = std::byte(read_buf[i]);
  }
  free(read_buf);  // 释放暂存的空间
  return location; // 返回的是这个记录在readbuf中的初始位置
}