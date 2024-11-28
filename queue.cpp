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
bool isp0Empty(pQueue *queue)
{
    pthread_mutex_lock(&put0Mutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&put0Mutex);
        return true;
    }
    pthread_mutex_unlock(&put0Mutex);
    return false;
}
bool isp1Empty(pQueue *queue)
{
    pthread_mutex_lock(&put1Mutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&put1Mutex);
        return true;
    }
    pthread_mutex_unlock(&put1Mutex);
    return false;
}
bool isp2Empty(pQueue *queue)
{
    pthread_mutex_lock(&put2Mutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&put2Mutex);
        return true;
    }
    pthread_mutex_unlock(&put2Mutex);
    return false;
}
bool isp3Empty(pQueue *queue)
{
    pthread_mutex_lock(&put3Mutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&put3Mutex);
        return true;
    }
    pthread_mutex_unlock(&put3Mutex);
    return false;
}
bool isp4Empty(pQueue *queue)
{
    pthread_mutex_lock(&put4Mutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&put4Mutex);
        return true;
    }
    pthread_mutex_unlock(&put4Mutex);
    return false;
}
// 检查get队列是否为空
bool isg0Empty(gQueue *queue)
{
    pthread_mutex_lock(&get0Mutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&get0Mutex);
        return true;
    }
    pthread_mutex_unlock(&get0Mutex);
    return false;
}
bool isg1Empty(gQueue *queue)
{
    pthread_mutex_lock(&get1Mutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&get1Mutex);
        return true;
    }
    pthread_mutex_unlock(&get1Mutex);
    return false;
}
    bool isg2Empty(gQueue *queue)
{
    pthread_mutex_lock(&get2Mutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&get2Mutex);
        return true;
    }
    pthread_mutex_unlock(&get2Mutex);
    return false;
}
bool isg3Empty(gQueue *queue)
{
    pthread_mutex_lock(&get3Mutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&get3Mutex);
        return true;
    }
    pthread_mutex_unlock(&get3Mutex);
    return false;
}
bool isg4Empty(gQueue *queue)
{
    pthread_mutex_lock(&get4Mutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&get4Mutex);
        return true;
    }
    pthread_mutex_unlock(&get4Mutex);
    return false;
}

// 检查del队列是否为空
bool isdEmpty(dQueue *queue)
{
    pthread_mutex_lock(&delMutex);
    if (queue->front == NULL)
    {
        pthread_mutex_unlock(&delMutex);
        return true;
    }
    pthread_mutex_unlock(&delMutex);
    return false;
}
// put队列入队操作
void p0enqueue(pQueue *queue, void (*value)(int, void *, int, int), int key, void *val, int id, int valtype)
{ // 插入队列的元素是函数指针
    pNode *newNode = (pNode *)malloc(sizeof(pNode));
    newNode->putfunction = value;
    newNode->key = key;
    newNode->value = val;
    newNode->id = id;
    newNode->valtype = valtype;
    newNode->next = NULL;
    pthread_mutex_lock(&put0Mutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&put0Mutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&put0Mutex);
        return;
    }
}
void p1enqueue(pQueue *queue, void (*value)(int, void *, int, int), int key, void *val, int id, int valtype)
{ // 插入队列的元素是函数指针
    pNode *newNode = (pNode *)malloc(sizeof(pNode));
    newNode->putfunction = value;
    newNode->key = key;
    newNode->value = val;
    newNode->id = id;
    newNode->valtype = valtype;
    newNode->next = NULL;
    pthread_mutex_lock(&put1Mutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&put1Mutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&put1Mutex);
        return;
    }
}
void p2enqueue(pQueue *queue, void (*value)(int, void *, int, int), int key, void *val, int id, int valtype)
{ // 插入队列的元素是函数指针
    pNode *newNode = (pNode *)malloc(sizeof(pNode));
    newNode->putfunction = value;
    newNode->key = key;
    newNode->value = val;
    newNode->id = id;
    newNode->valtype = valtype;
    newNode->next = NULL;
    pthread_mutex_lock(&put2Mutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&put2Mutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&put2Mutex);
        return;
    }
}
void p3enqueue(pQueue *queue, void (*value)(int, void *, int, int), int key, void *val, int id, int valtype)
{ // 插入队列的元素是函数指针
    pNode *newNode = (pNode *)malloc(sizeof(pNode));
    newNode->putfunction = value;
    newNode->key = key;
    newNode->value = val;
    newNode->id = id;
    newNode->valtype = valtype;
    newNode->next = NULL;
    pthread_mutex_lock(&put3Mutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&put3Mutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&put3Mutex);
        return;
    }
}
void p4enqueue(pQueue *queue, void (*value)(int, void *, int, int), int key, void *val, int id, int valtype)
{ // 插入队列的元素是函数指针
    pNode *newNode = (pNode *)malloc(sizeof(pNode));
    newNode->putfunction = value;
    newNode->key = key;
    newNode->value = val;
    newNode->id = id;
    newNode->valtype = valtype;
    newNode->next = NULL;
    pthread_mutex_lock(&put4Mutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&put4Mutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&put4Mutex);
        return;
    }
}
// get队列入队操作
void g0enqueue(gQueue *queue, void (*value)(int, int), int key, int id)
{ // 插入队列的元素是函数指针
    gNode *newNode = (gNode *)malloc(sizeof(gNode));
    newNode->getfunction = value;
    newNode->key = key;
    newNode->id = id;
    newNode->next = NULL;
    pthread_mutex_lock(&get0Mutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&get0Mutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&get0Mutex);
        return;
    }
}
void g1enqueue(gQueue *queue, void (*value)(int, int), int key, int id)
{ // 插入队列的元素是函数指针
    gNode *newNode = (gNode *)malloc(sizeof(gNode));
    newNode->getfunction = value;
    newNode->key = key;
    newNode->id = id;
    newNode->next = NULL;
    pthread_mutex_lock(&get1Mutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&get1Mutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&get1Mutex);
        return;
    }
}
void g2enqueue(gQueue *queue, void (*value)(int, int), int key, int id)
{ // 插入队列的元素是函数指针
    gNode *newNode = (gNode *)malloc(sizeof(gNode));
    newNode->getfunction = value;
    newNode->key = key;
    newNode->id = id;
    newNode->next = NULL;
    pthread_mutex_lock(&get2Mutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&get2Mutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&get2Mutex);
        return;
    }
}
void g3enqueue(gQueue *queue, void (*value)(int, int), int key, int id)
{ // 插入队列的元素是函数指针
    gNode *newNode = (gNode *)malloc(sizeof(gNode));
    newNode->getfunction = value;
    newNode->key = key;
    newNode->id = id;
    newNode->next = NULL;
    pthread_mutex_lock(&get3Mutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&get3Mutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&get3Mutex);
        return;
    }
}
void g4enqueue(gQueue *queue, void (*value)(int, int), int key, int id)
{ // 插入队列的元素是函数指针
    gNode *newNode = (gNode *)malloc(sizeof(gNode));
    newNode->getfunction = value;
    newNode->key = key;
    newNode->id = id;
    newNode->next = NULL;
    pthread_mutex_lock(&get4Mutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&get4Mutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&get4Mutex);
        return;
    }
}
// del队列入队操作
void denqueue(dQueue *queue, void (*value)(int), int key)
{ // 插入队列的元素是函数指针
    dNode *newNode = (dNode *)malloc(sizeof(dNode));
    newNode->delfunction = value;
    newNode->key = key;
    newNode->next = NULL;
    pthread_mutex_lock(&delMutex);
    if (queue->front==NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&delMutex);
        return;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        pthread_mutex_unlock(&delMutex);
        return;
    }
}
// put出队操作 返回的是一个函数指针
pNode *dep0queue(pQueue *queue)
{
    pthread_mutex_lock(&put0Mutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&put0Mutex);
        return NULL; // 表示出队失败
    }
    pNode *putnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&put0Mutex);
    return putnode;
}
pNode *dep1queue(pQueue *queue)
{
    pthread_mutex_lock(&put1Mutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&put1Mutex);
        return NULL; // 表示出队失败
    }
    pNode *putnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&put1Mutex);
    return putnode;
}
pNode *dep2queue(pQueue *queue)
{
    pthread_mutex_lock(&put2Mutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&put2Mutex);
        return NULL; // 表示出队失败
    }
    pNode *putnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&put2Mutex);
    return putnode;
}
pNode *dep3queue(pQueue *queue)
{
    pthread_mutex_lock(&put3Mutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&put3Mutex);
        return NULL; // 表示出队失败
    }
    pNode *putnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&put3Mutex);
    return putnode;
}
pNode *dep4queue(pQueue *queue)
{
    pthread_mutex_lock(&put4Mutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&put4Mutex);
        return NULL; // 表示出队失败
    }
    pNode *putnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&put4Mutex);
    return putnode;
}
// get出队操作
gNode *deg0queue(gQueue *queue)
{
    pthread_mutex_lock(&get0Mutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&get0Mutex);
        return NULL; // 表示出队失败
    }
    gNode *getnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&get0Mutex);
    return getnode;
}
gNode *deg1queue(gQueue *queue)
{
    pthread_mutex_lock(&get1Mutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&get1Mutex);
        return NULL; // 表示出队失败
    }
    gNode *getnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&get1Mutex);
    return getnode;
}
gNode *deg2queue(gQueue *queue)
{
    pthread_mutex_lock(&get2Mutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&get2Mutex);
        return NULL; // 表示出队失败
    }
    gNode *getnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&get2Mutex);
    return getnode;
}
gNode *deg3queue(gQueue *queue)
{
    pthread_mutex_lock(&get3Mutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&get3Mutex);
        return NULL; // 表示出队失败
    }
    gNode *getnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&get3Mutex);
    return getnode;
}
gNode *deg4queue(gQueue *queue)
{
    pthread_mutex_lock(&get4Mutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&get4Mutex);
        return NULL; // 表示出队失败
    }
    gNode *getnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&get4Mutex);
    return getnode;
}
// del出队操作
dNode *dedqueue(dQueue *queue)
{
    pthread_mutex_lock(&delMutex);
    if (queue->front==NULL)
    {
        pthread_mutex_unlock(&delMutex);
        return NULL; // 表示出队失败
    }
    dNode *delnode = queue->front;

    queue->front = queue->front->next;
    // 如果队列变为空，则更新 rear
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&delMutex);
    return delnode;
}
