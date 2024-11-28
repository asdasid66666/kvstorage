/*1.在cache中查找是否有对应的key 若找到了 将对应的内存地址返回 若未找到则返回NULL
  2.在cache尾部新增结点 并把hash的信息填进去
  3.在cache中找到了key 将key结点移动到链表尾部
  4.在cache中找key 将key结点的ifdel改为1
  5.在cache中找key 返回key结点的v是否被删除
  6.在cache中找key 返回key结点的v的type类型*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "global.h"

// 在cache中查找是否有对应的key 若找到了 将对应的内存地址返回 若未找到则返回NULL
int ifkeyexist(int key)
{
    pthread_mutex_lock(&cacheMutex);
    if (head == NULL && tail == NULL)
    {
        pthread_mutex_unlock(&cacheMutex);
        return -1;
    }
    LNode *k = tail;
    for (; k != NULL; k = k->prior)//遍历lru
    {
        if (k->key == key)
        {
            int a=k->location;
            pthread_mutex_unlock(&cacheMutex);
            return a;
        }
    }
    pthread_mutex_unlock(&cacheMutex);
    return -1;
}

// 在cache尾部新增结点 并把hash的信息填进去
void addnode(int key, int location)
{
    int type=findtype(key);
    int len=getlen(key);
    pthread_mutex_lock(&cacheMutex);
    // 先建立一个新结点
    LNode *newnode = (DLinkList)malloc(sizeof(LNode));
    newnode->key = key;
    newnode->location = location;
    newnode->ifdel = 0; 
    newnode->next = NULL;
    newnode->prior = NULL;
    newnode->type = type;            // 此时是hashmap信息填入 所以一定是读入过程而不是删除过程 故ifdel为0
    newnode->length = len; // 从hashmap中找对应的length来填充cache的length
    
    if (head == NULL && tail == NULL)
    {
        head = newnode;
        tail = newnode;
        pthread_mutex_unlock(&cacheMutex);
        return;
    }
    else
    {
        if (nodenum < 5000)
        {
            nodenum++;
            // 尾插入新节点
            tail->next = newnode;
            newnode->prior = tail;
            tail = newnode; // 更新尾指针
            tail->next = NULL;
            pthread_mutex_unlock(&cacheMutex);
            return;
        }
        else // 此时应该是cache中恰好有5000个结点 需要先将头结点释放 再尾插
        {
            head = head->next;
            free(head->prior);
            tail->next = newnode;
            newnode->prior = tail;
            tail = newnode; // 更新尾指针
            tail->next = NULL;
            pthread_mutex_unlock(&cacheMutex);
            return;
        }
    }
}

// 将该key结点移动到链表尾部
void movenode(int key) // 传入的是要移动的结点的指针
{
    pthread_mutex_lock(&cacheMutex);
    LNode *k = tail;
    for (; k != NULL; k = k->prior)
    {
        if (k->key == key)
        {
            break; // 此时k指针指向了key对应的cache结点
        }
    }
    if (k->key == key)
    {
        if (k->next == NULL)
        {
            pthread_mutex_unlock(&cacheMutex);
            return;
        } // 当目标结点已经是尾结点时 无需操作
        else if (head == k)
        {
            tail->next = k;
            head = k->next;
            k->next->prior = NULL;
            k->next = tail;
            tail = k;
            tail->next = NULL;
            pthread_mutex_unlock(&cacheMutex);
            return;
        } // 当目标结点为头结点时
        else
        {
            tail->next = k;
            k->next->prior = k->prior;
            k->prior->next = k->next;
            k->prior = tail;
            tail = k;
            tail->next = NULL;
            pthread_mutex_unlock(&cacheMutex);
            return;
        } // 当目标结点为中间的某个结点时
    }
    else
    {
        pthread_mutex_unlock(&cacheMutex);
        return; // 此时未找到key
    }
}

// 在cache中找key 将key结点的ifdel改为1
void changeifdel(int key)
{
    pthread_mutex_lock(&cacheMutex);
    LNode *k = tail;
    for (; k != NULL; k = k->prior)
    {
        if (k->key == key)
        {
            k->ifdel = 1; // 此时k指针指向了key对应的cache结点
            pthread_mutex_unlock(&cacheMutex);
            return;
        }
    }
    pthread_mutex_unlock(&cacheMutex);
    return;
}

// 在cache中找key 返回key结点的v是否被删除
int LRUifdeleted(int key)
{
    pthread_mutex_lock(&cacheMutex);
    LNode *k = tail;
    for (; k != NULL; k = k->prior)
    {
        if (k->key == key)
        {
            int a=k->ifdel;
            pthread_mutex_unlock(&cacheMutex);
            return a;
        } // 找到的情况
    }
    pthread_mutex_unlock(&cacheMutex);
    return -1; // 没有找到时返回-1
}

// 在cache中找key 返回key结点的v的type类型
int LRUtype(int key)
{
    pthread_mutex_lock(&cacheMutex);
    LNode *k = tail;
    for (; k != NULL; k = k->prior)
    {
        if (k->key == key)
        {
            int a=k->type;
            pthread_mutex_unlock(&cacheMutex);
            return a;
        } // 找到的情况
    }
    pthread_mutex_unlock(&cacheMutex);
    return -1; // 没有找到时返回-1
}
