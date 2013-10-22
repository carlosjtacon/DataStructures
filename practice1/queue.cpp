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
	node* front;

public:
	Queue()
	{
		/*constructor*/
	}
	~Queue()
	{
		/*destructor*/
	}

	void enqueue()
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
	}
	void makenull()
	{
		//Make the queue to be an empty queue
	}
	bool isEmpty()
	{
		//Return true if the queue is empty, return false otherwise
	}
};