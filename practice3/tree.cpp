#include "tree.h"

using namespace std;

Tree::Tree()
{
	root = NULL;
}

Tree::~Tree()
{
	//destructor
}

void Tree::add(string input)
{
	treeNode* newNode = new treeNode;
	newNode->label = input;
	newNode->bf = 0;
	newNode->palindrome = isPalindrome(input);
	newNode->leftchild = NULL;
	newNode->rightchild = NULL;
	newNode->parent = NULL; //means newNode is root
	if (root == NULL)
		root = newNode;
	else
		insert(input, root);
}

void Tree::insert(treeNode* input, treeNode* node)
{						
	input->parent = node;							
	if (node == NULL)								
	{			
		if (strcmp(input->label, input->parent->label) < 0)
			input->parent->leftchild = input;
		else if (strcmp(input->label, input->parent->label) > 0)
			input->parent->rightchild = input;
		input->leftchild = NULL;
		input->rightchild = NULL;
	}
	else if (node->bf = 0)
	{
		if (strcmp(input->label, node->label) < 0)
			insert(input, node->leftchild);
		else if (strcmp(input->label, node->label) > 0)
			insert(input, node->rightchild);
		else
		{
			//input = node-> label ==> don't know what to do
		}
	}
	else if (node->bf = 1)
	{
		if (strcmp(input->label,node->label) < 0)
		{
			insert(input, node->leftchild);
			node->bf = 0;
		}
		else if (strcmp(input->label,node->label) > 0)
		{
			if (strcmp(input->label, node->rightchild->label) > 0)
			{
				swap(node, node->rightchild);
				insert(input, node->parent->rightchild);
			}
			else if (strcmp(input->label, node->rightchild->label) < 0)
			{
				input->parent = node->parent;
				input->leftchild = node;
				input->rightchild = node->rightchild;
				input->rightchild->parent = input;
				node->parent = input;
				node->rightchild = NULL;	
				if (strcmp(input->label, input->parent->label) < 0)
					input->parent->leftchild = input;
				else if (strcmp(input->label, input->parent->label) > 0)
					input->parent->rightchild = input;
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
		if (strcmp(input->label, node->label) > 0) //new > parent
		{
			insert(input, node->rightchild);
			node->bf = 0;
		}
		else if (strcmp(input->label, node->label) < 0) //new < parent
		{
			if (strcmp(input->label, node->leftchild->label) < 0) // new < parent.leftchild
			{
				swap(node, node->leftchild);
				insert(input, node->parent->leftchild);
			}else if (strcmp(input->label, node->leftchild->label) > 0) //new > parent.leftchild
			{
				input->parent = node->parent;
				input->rightchild = node;
				input->leftchild = node->leftchild;
				input->leftchild->parent = input;
				node->parent = input;
				node->leftchild = NULL;
				if (strcmp(input->label, input->parent->label) < 0)
					input->parent->leftchild = input;
				else if (strcmp(input->label, input->parent->label) > 0)
					input->parent->rightchild = input;
			}	
			node->bf = 0;
		}
		else
		{
			//input = node-> label ==> don't know what to do
		}
	}
}

void Tree::swap(treeNode* parent, treeNode* child)
{
	child->parent = parent->parent;
	parent->parent = child;
	if (strcmp(child->label, parent->label) < 0)
		child->rightchild = parent;
	else if (strcmp(child->label, parent->label) > 0)
		child->leftchild = parent;
}