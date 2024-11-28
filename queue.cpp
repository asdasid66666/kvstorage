#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "global.h"

// 创建put队列
pQueue *createpQueue()
{
    pQueue *queue = (pQueue *)malloc(sizeof(pQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
// 创建get队列
gQueue *creategQueue()
{
    gQueue *queue = (gQueue *)malloc(sizeof(gQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
// 创建del队列
dQueue *createdQueue()
{
    dQueue *queue = (dQueue *)malloc(sizeof(dQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// 检查put队列是否为空
bool ispEmpty(pQueue *queue)
{

    if (queue->front == NULL)
    {
        return true;
    }
    return false;
}
// 检查get队列是否为空
bool isgEmpty(gQueue *queue)
{

    if (queue->front == NULL)
    {
        return true;
    }
    return false;
}
// 检查del队列是否为空
bool isdEmpty(dQueue *queue)
{

    if (queue->front == NULL)
    {
        return true;
    }
    return false;
}
// put队列入队操作
void penqueue(pQueue *queue, void (*value)(int, void *, int, int), int key, void *val, int id, int valtype)
{ // 插入队列的元素是函数指针
    pNode *newNode = (pNode *)malloc(sizeof(pNode));
    newNode->putfunction = value;
    newNode->key = key;
    newNode->value = val;
    newNode->id = id;
    newNode->valtype = valtype;
    newNode->next = NULL;

    if (ispEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
// get队列入队操作
void genqueue(gQueue *queue, void (*value)(int, int), int key, int id)
{ // 插入队列的元素是函数指针
    gNode *newNode = (gNode *)malloc(sizeof(gNode));
    newNode->getfunction = value;
    newNode->key = key;
    newNode->id = id;
    newNode->next = NULL;

    if (isgEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
// del队列入队操作
void denqueue(dQueue *queue, void (*value)(int), int key)
{ // 插入队列的元素是函数指针
    dNode *newNode = (dNode *)malloc(sizeof(dNode));
    newNode->delfunction = value;
    newNode->key = key;
    newNode->next = NULL;

    if (isdEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
// put出队操作 返回的是一个函数指针
pNode *depqueue(pQueue *queue)
{
    if (ispEmpty(queue))
    {
        return NULL; // 表示出队失败
    }
    pNode *putnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    return putnode;
}
// get出队操作
gNode *degqueue(gQueue *queue)
{
    if (isgEmpty(queue))
    {
        return NULL; // 表示出队失败
    }
    gNode *getnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    return getnode;
}
// del出队操作
dNode *dedqueue(dQueue *queue)
{
    if (isdEmpty(queue))
    {
        return NULL; // 表示出队失败
    }
    dNode *delnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    return delnode;
}
