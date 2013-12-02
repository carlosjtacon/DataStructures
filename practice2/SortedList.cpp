#include "SortedList.h"

SortedList::SortedList()
{
	header = NULL;
}

listnode* SortedList::getHeader()
{
	return header;
}

bool SortedList::isEmpty()
{
	return header == NULL;
}

void SortedList::insert(string input)
{
	listnode* pos = header;
	
	while (pos != NULL)
	{
		string key = pos->data.front();
		if (key.front() == input.front()) //found queue
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
	listnode* tmp = new listnode;

	if (tmp == NULL)
	{
		cout << "LIST FULL";
		return;
	} 
	//add queue to new node
	tmp->data.enqueue(input);

	listnode* pos = header;

	if (isEmpty())
	{
		//add queue to new node
		tmp->next = NULL;
		tmp->prev = NULL;
		header = tmp;
		return;
	}
	while(pos->next != NULL)
	{
		if (pos->data.front().front() < input.front())
		{
			pos = pos->next;
		}
		else
			break;
	}
	//already have position to insert to
	if (pos->data.front().front() > input.front())
	{
		tmp->prev = pos->prev;
		if (tmp->prev != NULL)
		{
			pos->prev->next = tmp;
		}
		pos->prev = tmp;
		tmp->next = pos;
	}else
	{
		tmp->prev = pos;
		tmp->next = pos->next;
		pos->next = tmp;
	}
}

void SortedList::remove(char id)
{	
	//find requested position
	listnode* pos = header;
	while (pos->data.front().front() < id && pos->next != NULL)
	{
		pos->next = pos->next->next;
	}
	//already have position, call delete method
	remove(pos);
}

void SortedList::remove(listnode* pos)
{	
	listnode* tmp = pos;
	if (pos->prev == NULL)//first
	{
		header = header->next;
		//header->next->prev = NULL;
	}else
	{
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
	}
	delete tmp;
}

void SortedList::printList()
{
	if (isEmpty())
	{		
		cout << "LIST EMPTY \n";
		return;
	}
	listnode* pos = header;

	while(pos != NULL)
	{
		printQ(pos->data);
		pos = pos->next;
	}
}

void SortedList::printQ(Queue<string> queue)
{
	while(!queue.isEmpty())
		cout << queue.dequeue() << "->";
	cout << endl;
}

SortedList::~SortedList()
{
	/*listnode* tmp = header;
	cout << header->data.front().front()<<endl;
	while(!isEmpty())
	{
		header = header->next;
		header->prev = NULL;
		delete tmp;
	}
*/
}