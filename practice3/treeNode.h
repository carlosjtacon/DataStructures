#ifndef TREE_NODE
#define TREE_NODE

struct treeNode
{
	string label;
	bool palindrome;		//1 = palindrom 0 != palindrome
	int count;				//number of repeated elements
	int bf;					//balance factor	IF AVL
	treeNode* leftchild; 	//leftmostchild
	treeNode* rightchild;	//rigthsibling
	treeNode* parent;		
};

#endif