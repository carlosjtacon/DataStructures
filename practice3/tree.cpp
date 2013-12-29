#include "tree.h"

using namespace std;

Tree()
{
	root = NULL;
}

~Tree()
{
	//destructor
}

void add(string input)
{
	if (root == NULL)
	{
		treeNode* newNode = new treeNode;

		newNode->label = input;
		newNode->bf = 0;
		newNode->palindrome = isPalindrome(input);
		newNode->leftchild = NULL;
		newNode->rightchild = NULL;
		newNode->parent = NULL; //means newNode is root
		root = newNode;
	}
	else
		insert(input, root);
}

void insert(string input, treeNode* node) 	//IMPORTANT: right now there's no 
{											//pointer-linking between nodes, 
	if (node == NULL)						//must find a way of linking before
	{										//calling recursively
		treeNode* newNode = new treeNode;

		newNode->label = input;
		newNode->bf = 0;
		newNode->palindrome = isPalindrome(input);
		newNode->leftchild = NULL;
		newNode->rightchild = NULL;
	}
	else if (node->bf = 0)
	{
		if (strcmp(input, node->label) < 0)
		{
			insert(input, node->leftchild);
			node->bf = -1;
		}else if (strcmp(input, node->label) > 0)
		{
			insert(input, node->rightchild);
			node->bf = 1;
		}else
		{
			//input = node-> label ==> don't know what to do
		}
	}
	else if (node->bf = 1)
	{
		if (strcmp(input,node->label) < 0)
		{
			insert(input, node->leftchild);
			node->bf = 0;
		}
		else if (strcmp(input,node->label) > 0)
		{
			swap(node, node->rightchild);
			insert(input, node->parent->rightchild);
			node->bf = 0;
		}
		else
		{
			//input = node-> label ==> don't know what to do
		}
	}
	else if (node->bf = -1)
	{
		if (strcmp(input, node->label) > 0)
		{
			insert(input, node->rightchild);
			node->bf = 0;
		}
		else if (strcmp(input, node->label) < 0)
		{
			swap(node, node->leftchild);
			insert(input, node->parent->leftchild);
			node->bf = 0;
		}
		else
		{
			//input = node-> label ==> don't know what to do
		}
	}
}

void swap(treeNode* parent, treeNode* child)
{
	child->parent = parent->parent;
	parent->parent = child;
}