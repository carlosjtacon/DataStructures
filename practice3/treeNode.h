#include <string>

#ifndef TREE_NODE
#define TREE_NODE

struct treeNode
{
	std::string label;
	bool palindrome;		//1 = palindrome 0 != palindrome
	int count;				//number of repeated elements
	int bf;					//balance factor	IF AVL
	treeNode* leftchild; 	//leftmostchild
	treeNode* rightchild;	//rigthsibling
	treeNode* parent;		
};

#endif