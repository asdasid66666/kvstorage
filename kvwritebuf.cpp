/*k v的写缓冲文件(两个缓冲区需要同时写)
打算定义的接口和函数：
1.写入缓冲并序列化
2.返回记录在缓冲区的offset
3.返回val序列化之后的长度 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include "global.h"
#include "Intmessage.pb.h"
// 序列化并写入缓冲区
void writebuf(int key, valstr *val, int thread_num) // 说明是几号线程的写缓冲和写文件操作
{
  kbnum[thread_num]++; // 缓冲区存入数据量＋1
  // 每个存进去的数据直接进行序列化
  a::IntMessage msg1;  // key
  a::voidMessage msg2; // val
  msg1.Clear();
  msg2.Clear();
  msg1.set_number(key);
  if (val->type == 0)
  {
    msg2.set_int_num(*(int *)(val->num));
  } // 当val->num的类型为int型时
  else if (val->type == 1)
  {
    msg2.set_float_num(*(float *)(val->num));
  } // 当val->num的类型为int型时
  else if (val->type == 2&&val->num!=NULL)
  {
    std::string str((char*)val->num);
    msg2.set_string_num(str);
  } // 当val->num类型为字符串类型
  int size1 = msg1.ByteSizeLong();
  int size2 = msg2.ByteSizeLong(); // 获取了kv序列化之后的大小
  vboff[thread_num] += size2;
  kboff[thread_num] += size1;
  keybuf_Array[thread_num].resize(keybuf_Array[thread_num].size() + size1); // 扩大 vector 尺寸以容纳新数据
  valbuf_Array[thread_num].resize(valbuf_Array[thread_num].size() + size2);
  if (msg1.SerializeToArray(keybuf_Array[thread_num].data() + keybuf_Array[thread_num].size() - size1, size1) == false)
  {
    printf("writing %d to keybuf failed!\n", key);
  }
  if (msg2.SerializeToArray(valbuf_Array[thread_num].data() + valbuf_Array[thread_num].size() - size2, size2) == false)
  {
    printf("writing corresponding value of %d to valuebuf failed!\n", key);
  }
  return;
}

int vallen(valstr *val) // 返回val序列化之后的长度
{
  a::voidMessage msg2; // val
  msg2.Clear();
  if (val->type == 0)
  {
    msg2.set_int_num(*(int *)(val->num));
  } // 当val->num的类型为int型时
  else if (val->type == 1)
  {
    msg2.set_float_num(*(float *)(val->num));
  } // 当val->num的类型为int型时
  else if (val->type == 2)
  {
     std::string str((char*)val->num);  // 从char*创建string
     msg2.set_string_num(str);
  } // 当val->num类型为字符串类型
  int length = msg2.ByteSizeLong(); // 获取了kv序列化之后的大小
  return length;
}