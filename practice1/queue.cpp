#include <stdlib.h>
#include <string.h>
#include <iostream.h>

using namespace std;

struct node
{
	char data;
	node* next;
};

class Queue
{

private:
	node* _front;
	node* _rear;
	node* _current;
	int size;

public:
	Queue()
	{
		/*constructor*/
		_front == NULL;
		_rear == _front;
	}
	~Queue()
	{
		/*destructor*/
	}

	void enqueue(char c)	//Insert an element at the rear of the queue
	{
		_current= new node;
		_current->next=NULL;

		if (_front==NULL)
		{
			_front=_current;
			_rear=_front;
		}
		else if (_front!=NULL)
		{
			_rear->next=_current;
			_rear=_current;
		}
	}

	char dequeue()	//Delete the element at the front of queue (and return it)
	{
		if (_front!=NULL)
		{
			_current=_front;
			_front=_current->next;
		}
	}

	char front()	//Return the element at the front of the queue
	{
		return _front -> data;
	}

	char rear()	//Return the element at the rear of the queue
	{
		return _rear -> data;
	}

	void makenull()	//Make the queue to be an empty queue
	{
		_front = NULL;
		_rear = _front;
	}

	bool isEmpty()	//Return true if the queue is empty, return false otherwise
	{
		return (_front == _rear);
	}
};