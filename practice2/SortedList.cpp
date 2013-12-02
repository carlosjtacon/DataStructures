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
			pos->prev = tmp;
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
		pos->prev = tmp;
	}else
	{
		tmp->prev = pos;
		tmp->next = pos->next;
		pos->next = tmp;
	}
}

int SortedList::remove(char id)
{	
	if (isEmpty())
		return 0;
	//find requested position
	listnode* pos = header;
	while (pos->data.front().front() != id)
	{
		pos= pos->next;
		if (pos == NULL)
			return 0;
	}
	//already have position, call delete method
	remove(pos);
	return 1;
}

void SortedList::remove(listnode* pos)
{	
	if (pos == header)//first
	{
		header = pos->next;
		if (header != NULL)
			header->prev = NULL;
	}else if (pos->next == NULL)//last
	{
		cout << "llega"<<endl;
		pos->prev->next = NULL;
		pos->next = NULL;
		pos->prev = NULL;
	}else //intermedio
	{
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		pos->next = NULL;
		pos->prev = NULL;
		cout << "llega2"<<endl;
	}
	delete pos;
}

string SortedList::toString()
{
	stringstream value;

	if (isEmpty())
	{
		value << "empty \n";
		return value.str();
	}
		
	listnode* pos = header;

	int total = 0;
	int count = 0;

	while(pos != NULL)
	{		
		count = pos->data.size();
		total++;
		value << pos->data.front().front() << "(x" << count << ")\n |\n";

		pos = pos->next;
	}
	value << "===\nTOTAL: "<<total<<"\n";
	return value.str();
}

void SortedList::printQ(Queue<string> queue)
{
	while(!queue.isEmpty())
		cout << queue.dequeue() << "->";
	cout << endl;
}

SortedList::~SortedList()
{
	while(!isEmpty())
	{
		remove(header);
	}

}