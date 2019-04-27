#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"




void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}
void QueueDestory(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* newnode =(QueueNode*) malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;

}

void QueuePush(Queue* q, QUDataType x)
{
	assert(q);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = BuyQueueNode(x);
	}
	else
	{
		q->_rear->_next = BuyQueueNode(x);
		q->_rear = q->_rear->_next;
	}
}


void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front)
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL)
			q->_rear = NULL;
	}
	
}

int QueueSize(Queue* q)
{
	assert(q);
	int size = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		cur = cur->_next;
		size++;
	}
	return size;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 0 : 1;
}

QUDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

QUDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

void Queueprint(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		printf("%d ", cur->_data);
		cur = next;
	}
	printf("\n");
}

void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	Queueprint(&q);
	QueuePop(&q);
	Queueprint(&q);

	



	QueueDestory(&q);
}

