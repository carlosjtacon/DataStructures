#ifndef TREE_NODE
#define TREE_NODE

struct treeNode
{
	string label;
	int palindrom;			//1 = palindrom 0 != palindrome
	int bf;					//balance factor
	treeNode* leftchild; 	//leftmostchild
	treeNode* rightchild;	//rigthsibling
	treeNode* parent;
};

#endif