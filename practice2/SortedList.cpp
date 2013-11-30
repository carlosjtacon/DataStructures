#include "SortedList.h"

SortedList::SortedList()
{
	header = null;
}

bool SortedList::isEmpty()
{
	return header == null;
}

void SortedList::insert(string input)
{
	listnode* pos = header;
	if (isEmpty())
	{
		insertP(input);
		return;
	}
	while (pos->next != NULL)
	{
		string key = pos->data.front();
		if key[0] == input[0] //found queue
		{
			pos->data.enqueue(input);
			return;
		}
		pos= pos->next;
	}
	//call to insert method
	insertP(input);
}

void SortedList::insertP(string input)
{
	listnode* pos = header
	listnode* tmp = new node;
	//create queue & insert input
	Queue<string> queueNode = Queue();
	queueNode.enqueue(input);

	if (tmp == NULL)
	{
		cout << "LIST FULL";
		return;
	} 

	//add queue to new node
	tmp->data = queueNode;

	if (isEmpty())
	{
		head = tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
		return;
	}
	while((pos->data.front().front() < input.front()) && (pos->next != NULL))
		pos = pos->next;	
	//already have position to insert to
	tmp->prev = pos->prev;
	pos->prev = tmp;
	tmp->next = pos;
}

void SortedList::remove(char id)
{	
	//find requested position
	*listnode pos = header;
	while (pos->data.front().front() < id && pos->next != NULL)
	{
		pos->next = pos->next->next;
	}
	//already have position, call delete method
	remove(pos);
}

void SortedList::remove(*listnode pos)
{
	if (pos->prev == NULL)//first
	{
		header = pos->next;
	}else
	{
		pos->prev->next = pos->next;
	}
	delete pos;
}

void SortedList::printList()
{
	if (isEmpty())
	{		
		cout << "LIST EMPTY \n";
		return;
	}
	*listnode pos = header;

	while(pos != NULL)
	{
		printQ(pos->data);
		pos = pos->next;
	}
}

void pSortedList::printQ(Queue<string> queue)
{
	while(!queue.isEmpty())
		cout << queue.dequeue() + "->";
	cout << "\n";
}

SortedList::~SortedList()
{
	while (!isEmpty())
		remove(header);
}