#include <string>

#ifndef TREE_NODE
#define TREE_NODE

using namespace std;

struct treeNode
{
	string label;
	bool palindrome;		//1 = palindrome 0 != palindrome
	int count;				//number of repeated elements
	treeNode* leftchild; 	//leftmostchild
	treeNode* rightchild;	//rigthsibling
	treeNode* parent;		
};

#endif