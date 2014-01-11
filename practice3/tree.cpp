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

void Tree::insert(string input)	//public method
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

void Tree::insert(treeNode* input, treeNode* node) //private method
{						
	if (node == NULL)
	{
		if (input->parent->label < input->label)
			input->parent->leftchild = input;
		else if (input->parent->label > input->label)
			input->parent->rightchild = input;
	}
	else if (node->label < input->label)
	{
		input->parent = node;
		insert(input, node->leftchild);
	}
	else if (node->label > input->label)
	{
		input->parent = node;
		insert(input, node->rightchild);
	}
	else
	{
		node->count++;
		delete input;
	}
}

void Tree::swap(treeNode* parent, treeNode* child) //used in AVL implementation
{
	child->parent = parent->parent;
	parent->parent = child;
	if (strcmp(child->label, parent->label) < 0)
		child->rightchild = parent;
	else if (strcmp(child->label, parent->label) > 0)
		child->leftchild = parent;
}

void Tree::search()
{

}

void Tree::traverse(treeNode* node)
{
	if (node == NULL)
		return;
	traverse(node->leftchild);
	if (node->isPalindrome)
		printf("%s\n", node->label);
	traverse(node->rightchild);
}

void Tree::remove()
{
	
}