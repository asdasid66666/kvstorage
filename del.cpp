/*大文件删除指定记录的过程：
  1.用户输入del key
  2.在hashmap中找到Key对应的结点 并修改相应的标志位为被删除
  3.在cache中找是否有key对应的结点 若有 则修改相应的标志位为被删除
*/
#include <stdio.h>
#include <vector>
#include "global.h"

// 删除接口的样子是：del key
void del(int key)
{
   if (Hashifexist(key) == 0) // k在hashmap中
   {
      setdel(key);                                               // 改hashmap节点中是否被删除的标志位
      if ((LRUifdeleted(key) == 1) || (LRUifdeleted(key) == -1)) // LRU中若没有这个结点 或者结点的标志位已为被删除 则不做修改
      {
         printf("the key %d and its corresponding value has been deleted!\n");
         return;
      }
      else if (LRUifdeleted(key) == 0) // 否则 将标志位改为被删除
      {
         changeifdel(key); // 改LRU中的标志位
         printf("the key %d and its corresponding value has been deleted!\n");
         return;
      }
   }
   else
   {
      printf("the key %d does not exist!\n", key);
      return;
   }
}