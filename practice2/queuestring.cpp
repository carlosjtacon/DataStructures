#include "queuestring.h"
using namespace std;


Queuestring::Queuestring()
{
	makenull();
}
Queuestring::~Queuestring()
{
	nodestring* tmp;
	while(!isEmpty())
	{
		tmp=_front;
		_front=_front->next;
		delete tmp;
		cout << "llega a queuestring" << endl;
	}
}

void Queuestring::enqueue(string c)	//Insert an element at the rear of the queuestring
{
	nodestring* _current;
	_current= new nodestring;
	_current->next=NULL;
	_current->data= c;

	if (isEmpty())
	{
		_front=_current;
		_rear=_current;
	}
	else if (!isEmpty())
	{
		_rear->next= _current;
		_rear=_current;
	}
}

string Queuestring::dequeue()	//Delete the element at the front of queuestring (and return it)
{
	string rt=_front -> data;

	nodestring* _current;

	if (!isEmpty())
	{
		_current=_front;
        _front=_front->next;
		delete _current;
	}
	return rt;
}

string Queuestring::front()	//Return the element at the front of the queuestring
{
	return _front -> data;
}

string Queuestring::rear()	//Return the element at the rear of the queuestring
{
	return _rear -> data;
}

void Queuestring::makenull()	//Make the queuestring to be an empty queuestring
{
	_front = NULL;
	_rear = _front;
}

bool Queuestring::isEmpty()	//Return true if the queuestring is empty, return false otherwise
{
	return (_front == NULL);
}

