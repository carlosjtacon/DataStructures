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

void Tree::add(string input)	//public method
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
		add(newNode, root);
}

void Tree::add(treeNode* input, treeNode* node) //private method
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
		add(input, node->leftchild);
	}
	else if (node->label > input->label)
	{
		input->parent = node;
		add(input, node->rightchild);
	}
	else
	{
		node->count++;
		delete input;
	}
}


void Tree::search(treeNode *node)	//private
{
	if(node == NULL)
		return;
	search(node -> leftchild);
	if(node->count > 0)
		cout << node -> label << " | Palindrome: " << node->palindrome;
	search(node->rightchild);
}

void Tree::search()	//public
{
	search(root);
}

void Tree::traverse(treeNode* node)	//private
{
	if (node == NULL)
		return;
	traverse(node->leftchild);
	if (node->palindrome)
		cout << node->label << endl;
	traverse(node->rightchild);
}

void Tree::traverse()	//public
{
	traverse(tree->root);
}

void removeAllNotPalindromes(treeNode* node)	//private
{
	if (node == NULL)
		return;
	removeAllNotPalindromes(node->leftchild);
	if(!node->palindrome)
		removeNode(node);
	removeAllNotPalindromes(node->rightchild);
}

void Tree::removeAllNotPalindromes()	//public
{
	removeAllNotPalindromes(root);
}

void Tree::removeNode(treeNode* node)	//private (?)
{
	treeNode *aux;

	if (node->leftchild == NULL && node->rightchild == NULL)		//leaf
	{
		delete(node);
	}
	else if (node->leftchild == NULL || node->rightchild == NULL)	//branch one child
	{
		if (node->leftchild)
		{
			remplaceNodeInParent(node->parent, node->leftchild);
			node->leftchild->parent = node-> parent;
		}
		else
		{
			remplaceNodeInParent(node->parent, node->rightchild);
			node->rightchild->parent = node->parent;
		}
		delete(node);
	}
	else	//branch two children
	{
		aux = node;							
		while(aux -> leftchild)
			aux = aux -> leftchild;
		swap(node, aux);
		delete(node);
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

void Tree::remplaceNodeInParent(treeNode* node, treeNode* child)
{
	if(node->parent)
	{
		if (node->parent->leftchild == node)
			node->parent->leftchild = child;
		else
			node->parent->rightchild = child;
	}
}