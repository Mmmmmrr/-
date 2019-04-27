#define _CRT_SECURE_NO_WARNINGS 1
#include "common.h"

typedef int QUDataType;
typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;


void QueueInit(Queue* q);
void QueueDestory(Queue* q);

QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* q, QUDataType x);
void QueuePop(Queue* q);

int QueueSize(Queue* q);
int QueueEmpty(Queue* q);

QUDataType QueueFront(Queue* q);
QUDataType QueueBack(Queue* q);

void Queueprint(Queue* q);

void QueueTest();