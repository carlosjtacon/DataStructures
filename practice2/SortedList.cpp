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
	if (isEmpty())
	{
		insertP(input);
		return;
	}

	char key = input.front();
	listnode* pos = header;
	while(pos->next != NULL)//while not last
	{
		if (pos->data.front().front() == key)//if found
		{
			pos->data.enqueue(input);
			return;
		}
		pos= pos->next;
	}
	if (pos->data.front().front() == key)
		pos->data.enqueue(input);
	else
		insertP(input);
}

void SortedList::insertP(string input)
{
	listnode* tmp = new listnode;
	tmp->data.enqueue(input);
	if (isEmpty())
	{
		tmp->prev = NULL;
		tmp->next = NULL;
		header = tmp;
		return;
	}
	listnode* pos = header;
	char key = input.front();
	while(pos->next != NULL)//while not last
	{
		if (pos->data.front().front() > key)//if found
		{
			tmp->next = pos;
			if (pos->prev != NULL)
			{
				pos->prev->next = tmp;
			}
			tmp->prev = pos->prev;
			return;
		}
		pos = pos->next;		
	}//if last
	if (pos->data.front().front() >key)
	{
		tmp->next = pos;
		if (pos->prev != NULL)
		{
			pos->prev->next = tmp;
		}
		tmp->prev = pos->prev;
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
		cout << "REMOVE char" << endl;
		pos->next = pos->next->next;
	}
	//already have position, call delete method
	remove(pos);
}

void SortedList::remove(listnode* pos)
{	
	cout << "REMOVE" << endl;
	if (pos->prev == NULL)//first
	{
		header = pos->next;
		if (header != NULL)
			header->prev = NULL;
	}else if (pos->next == NULL)//last
	{
		pos->prev->next = NULL;
	}else
	{
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
	}
	cout << "LLEGA1"<<endl;
	delete pos;
	cout << "LLEGA2"<<endl;

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
	cout << "LLEGA D" << endl;
	while(!isEmpty())
	{
		remove(header);
	}

}