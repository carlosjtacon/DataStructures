#include "tree.h"

using namespace std;

Tree::Tree()
{
	root = NULL;
}

Tree::~Tree()
{
	removeAll(root);
}

void Tree::add(string input)	//public method
{
	treeNode* newNode = new treeNode;
	newNode->label = input;
	newNode->palindrome = isPalindrome(input);
	newNode->count = 0;
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
		if (input->label < input->parent->label)
			input->parent->leftchild = input;
		else if (input->label > input->parent->label)
			input->parent->rightchild = input;
	}
	else if (input->label < node->label)
	{
		input->parent = node;
		add(input, node->leftchild);
	}
	else if (input->label > node->label)
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
		cout << "Label: " << node -> label << " | Palindrome: " << node->palindrome << " | Repeated: "<< node->count << " times." << endl;
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
	traverse(root);
}

void Tree::removeAllNotPalindromes(treeNode* node)	//private
{
	if (node == NULL)
		return;
	removeAllNotPalindromes(node->leftchild);
	removeAllNotPalindromes(node->rightchild);
	if(!node->palindrome)
		remove(node);
}

void Tree::removeAllNotPalindromes()	//public
{
	removeAllNotPalindromes(root);
}

void Tree::remove(treeNode* node)	//private (?)
{
	if (node->leftchild == NULL && node->rightchild == NULL)		//leaf
	{
		if(node != root)
		{
			if (node->parent->leftchild == node)
				node->parent->leftchild = NULL;
			else if (node->parent->rightchild == node)
				node->parent->rightchild = NULL;

			delete node;
			return;
		}
		else	//deleting root - we need to reasign root
		{
			delete node;
			root = NULL;
			return;
		}
	}
	else if (node->leftchild == NULL || node->rightchild == NULL)	//branch one child
	{
		if(node != root)
		{
			if (node->leftchild)
			{
				remplaceNodeInParent(node, node->leftchild);
				node->leftchild->parent = node-> parent;
			}
			else
			{
				remplaceNodeInParent(node, node->rightchild);
				node->rightchild->parent = node->parent;
			}

			delete node;
			return;
		}
		else	//deleting root - we need to reasign root
		{
			if (node->leftchild)
			{
				node->leftchild->parent = NULL;
				root = node->leftchild;
			}
			else
			{
				node->rightchild->parent = NULL;
				root = node->rightchild;
			}

			delete node;
			return;
		}
	}
	else	//branch two children
	{
		treeNode* aux =  node->rightchild;
		while(aux -> leftchild)
		{
			aux = aux->leftchild;
		}
		swap(aux, node);
		remove(aux);
		return;	
	}
}

void Tree::swap(treeNode* parent, treeNode* child) //used in AVL implementation
{
	string label = parent->label;			//data aux
	bool palindrome = parent->palindrome;
	int count = parent->count;

	parent->label = child->label;
	parent->palindrome = child->palindrome;
	parent->count = child->count;

	child->label = label;
	child->palindrome = palindrome;
	child->count = count;
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

void Tree::show()
{
	show(root);
}

void Tree::show(treeNode* input)
{
	if (input == NULL)
		return;
	show(input->leftchild);
	cout << "Label: " << input->label << endl;
	cout << "Palindrome: " << input->palindrome << endl; 
	cout << "Count: " << input->count << endl;
	if (input->leftchild !=NULL)
		cout << "Leftchild: "<< input->leftchild->label << endl;
	else
		cout << "Leftchild: NULL" << endl; 
	if (input->rightchild !=NULL)
		cout << "Rightchild: "<< input->rightchild->label << endl;
	else
		cout << "Rightchild: NULL" << endl;
	if (input->parent !=NULL)
		cout << "Parent: "<< input->parent->label << endl;
	else
		cout << "Parent: NULL" << endl;
	cout << "_________________________________________________" << endl;
	show(input->rightchild);
}

void Tree::removeAll(treeNode* node)
{
	if (node == NULL)
		return;
	removeAll(node->leftchild);
	removeAll(node->rightchild);
	remove(node);
}