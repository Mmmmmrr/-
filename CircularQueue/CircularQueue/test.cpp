#define _CRT_SECURE_NO_WARNINGS 1
#include <malloc.h>

typedef struct {
	int* _array;
	int _n;
	int _front;
	int _rear;

} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	queue->_array = (int*)malloc(sizeof(int)*(k + 1));
	queue->_n = k + 1;
	queue->_front = 0;
	queue->_rear = 0;
	return queue;
}
/** Checks whether the circular queue is empty or not. */

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->_front == obj->_rear;
}



/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return  (obj->_rear + 1) % obj->_n == obj->_front ? true : false;
}


/** Insert an element into the circular queue. Return true if the operation is successful. */


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

	if (myCircularQueueIsFull(obj) == true)
	{
		return false;
	}
	obj->_array[obj->_rear++] = value;
	obj->_rear %= obj->_n;
	return true;
}
/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj) == true)
		return false;
	++obj->_front;
	obj->_front %= obj->_n;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {

	if (myCircularQueueIsEmpty(obj) == true)
		return -1;
	return obj->_array[obj->_front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj) == true)
		return -1;
	else
	if (obj->_rear == 0)
	{
		return obj->_array[obj->_n - 1];
	}
	else
		return obj->_array[obj->_rear - 1];

}


void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_array);
	free(obj);
}


/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);

* bool param_2 = myCircularQueueDeQueue(obj);

* int param_3 = myCircularQueueFront(obj);

* int param_4 = myCircularQueueRear(obj);

* bool param_5 = myCircularQueueIsEmpty(obj);

* bool param_6 = myCircularQueueIsFull(obj);

* myCircularQueueFree(obj);
*/