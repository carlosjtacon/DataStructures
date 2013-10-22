#include <stdlib.h>
#include <string.h>
#include <iostream.h>

using namespace std;

struct node
{
	char data;
	node *link;
};

class Queue
{
private:
	node* _front;

public:
	Queue()
	{
		/*constructor*/
		_front == NULL;
	}
	~Queue()
	{
		/*destructor*/
	}

	void enqueue(char c)
	{
		//Insert an element at the rear of the queue
	}

	char dequeue()
	{
		//Delete the element at the front of queue (and return it)
	}

	char front()
	{
		//Return the element at the front of the queue
		return _front -> data;
	}

	void makenull()
	{
		//Make the queue to be an empty queue
		_front =NULL;
	}

	bool isEmpty()
	{
		//Return true if the queue is empty, return false otherwise
		return (_front == NULL);
	}
};