#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include "global.h"

// 创建文件  插入k和v
// 创建一个文件
int createfile(std::string filename)
{
  if ((Filefd = open(filename.c_str(), O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
  {
    perror("open file failed");
    return -1;
  }
  int size = 100000001; // 文件key的区域设为100MB 测试放val值的地方能不能遍历到
  if (lseek(Filefd, size - 1, SEEK_SET) == -1)
  {
    perror("lseek file failed");
    close(Filefd);
    return -1;
  }
  // 测试能否正常写入
  int text = 123;
  if (pwrite(Filefd, &text, sizeof(int), size - 1)==-1)
  {
    perror("write file failed");
    close(Filefd);
    return -1;
  }
  return Filefd;
}

// 往大文件开头写key 中间写value
void writekeyval(int Filefd, int thread_num)
{
  // 接下来的操作是 1.通过每个记录长度算出缓冲区序列化之后的长度2.pwrite写入 key缓冲区
  if (pwrite(Filefd, keybuf_Array[thread_num].data(), kboff[thread_num], 4000 * (5 * write_file_num[thread_num] + thread_num)) == -1) // 限制k区写入不超过100MB
  {
    printf("writing keybuffer%d to file failed\n", thread_num);
    return;
  }
  if (pwrite(Filefd, valbuf_Array[thread_num].data(), vboff[thread_num], voff + 20000 * (5 * write_file_num[thread_num] + thread_num)) == -1) // 限制二进制之后一个val最多长20B
  {
    printf("writing valbuffer%d to file failed\n", thread_num);
    return;
  }
  write_file_num[thread_num]++; // 写入次数加1
  printf("writing keybuffer%d and its corresponding valbuffer to file successfully\n", thread_num);
  return;
}

unsigned char *getv(int Filefd, int valoffset, int length, int thread_num) // 这里返回的是指向一个二进制数组buffer的指针
// 暂定一开始的val是整形的 后面修改 实际上的val可能是各种类型的
// 将记录的二进制形式用pread读出到一个内存的二进制数组中
{

  if ((valoffset > (voff + 20000 * (5 * write_file_num[thread_num] + thread_num))) || (valoffset == (voff + 20000 * (5 * write_file_num[thread_num] + thread_num))))
  // 此时 记录所在的缓冲区还没有写入磁盘文件
  {
    return NULL;
  }
  else if ((valoffset < (voff + 20000 * (5 * write_file_num[thread_num] + thread_num)))) // 此时 记录所在缓冲区已经写入了磁盘文件
  {
    unsigned char *buf = (unsigned char *)malloc(sizeof(unsigned char) * length); // 创建一个暂存的数组
    if (pread(Filefd, buf, length, valoffset) == -1)
    {
      printf("reading from bigfile to readbuffer failed!\n");
      return NULL;
    }
    // 存入数据
    return buf;
  }
  return NULL;
}