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
			insert(input, node->leftchild);
		else if (strcmp(input, node->label) > 0)
			insert(input, node->rightchild);
		else
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
			if (strcmp(input, node->rightchild->label) > 0)
			{
				swap(node, node->rightchild);
				insert(input, node->parent->rightchild);
			}
			else if (strcmp(input, node->rightchild->label) < 0)
			{
				//movida de la hostia
			}			
			node->bf = 0;
		}
		else
		{
			//input = node-> label ==> don't know what to do
		}
	}
	else if (node->bf = -1)
	{
		if (strcmp(input, node->label) > 0) //new > parent
		{
			insert(input, node->rightchild);
			node->bf = 0;
		}
		else if (strcmp(input, node->label) < 0) //new < parent
		{
			if (strcmp(input, node->leftchild->label) < 0) // new < parent.leftchild
			{
				swap(node, node->leftchild);
				insert(input, node->parent->leftchild);
			}else if (strcmp(input, node->leftchild->label) > 0) //new > parent.leftchild
			{
				//movida de la hostia
			}			
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
	if (strcmp(child->label, parent->label) < 0)
		child->rightchild = parent;
	else if (strcmp(child->label, parent->label) > 0)
		child->leftchild = parent;
}