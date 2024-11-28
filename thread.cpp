#include <stdio.h>
#include <vector>
#include <time.h>
#include "global.h"
// 在get put del三个接口之上再封装一层对应的线程的接口 主要为了处理对应命令队列为空的情况
void *put_thread_function(void *arg) // 传入的是p[thread_num]的地址
{
    pQueue *p = (pQueue *)arg;
    while (true)
    {
        while (ispEmpty(p))
        {
        } // 如果put队列为空的话 就不断检测

        pNode *putnode = depqueue(p);
        putnode->putfunction(putnode->key, putnode->value, putnode->id, putnode->valtype); // 执行队列头部元素的函数 执行完毕之后把队列头部元素去掉
        free(putnode->value);
        free(putnode);
    } // 小的写线程不断从put队列中取出put并执行
    return NULL;
}

void *get_thread_function(void *arg) // 传入的是g[thread_num]的地址
{
    gQueue *g = (gQueue *)arg;
    while (true)
    {
        while (isgEmpty(g))
        {
        }
        // 出队列函数返回的是一个指向dnode的指针
        gNode *getnode = degqueue(g);
        getnode->getfunction(getnode->key, getnode->id);
        free(getnode);
    }
    return NULL;
}

void *del_thread_function(void *arg) // 传入的是d[thread_num]的地址
{
    dQueue *d = (dQueue *)arg;
    while (true)
    {
        while (isdEmpty(d))
        {
        }
        dNode *delnode = dedqueue(d);
        delnode->delfunction(delnode->key);
        free(delnode);
    }
    return NULL;
}