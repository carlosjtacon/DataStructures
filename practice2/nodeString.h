#include <string.h>
using namespace std;

#ifndef NODESTRING_H
#define NODESTRING_H

struct nodeString
{
	string data;
	nodeString* next;
};

#endif