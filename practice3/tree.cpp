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
		cout << "NULL case" << endl;
		if (input->label < input->parent->label)
			input->parent->leftchild = input;
		else if (input->label > input->parent->label)
			input->parent->rightchild = input;
	}
	else if (input->label < node->label)
	{
		cout << input->label <<" < " << node->label << endl;
		input->parent = node;
		add(input, node->leftchild);
	}
	else if (input->label > node->label)
	{
		cout << input->label <<" > " << node->label << endl;
		input->parent = node;
		add(input, node->rightchild);
	}
	else
	{
		cout << "equal" << endl;
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
		cout << node -> label << " | Palindrome: " << node->palindrome << endl;
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
	if (node->leftchild == NULL && node->rightchild == NULL)		//leaf
	{
		if(node != root)
		{
			if (node->parent->leftchild == node)
				node->parent->leftchild = NULL;
			else if (node->parent->rightchild == node)
				node->parent->rightchild = NULL;

			cout << "deleting leaf node - " << node->label << endl;
			delete node;
		}
		else	//deleting root - we need to reasign root
		{
			cout << "deleting ROOT node (is a leaf) - " << node->label << endl;
			delete node;
			cout << "--- NOW ROOT IS NULL ---" << endl;
			root = NULL;
		}
	}
	else if (node->leftchild == NULL || node->rightchild == NULL)	//branch one child
	{
		if(node != root)
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

			cout << "deleting one child branch - " << node->label << endl;
		}
		else	//deleting root - we need to reasign root
		{
			if (node->leftchild)
			{
				node->leftchild->parent = NULL;
				cout << "--- NOW ROOT IS " << node->leftchild->label << " ---" << endl;
				root = node->leftchild;
			}
			else
			{
				node->rightchild->parent = NULL;
				cout << "--- NOW ROOT IS " << node->rightchild->label << " ---" << endl;
				root = node->rightchild;
			}

			cout << "deleting ROOT (is a one child branch) - " << node->label << endl;
		}
		delete node;
	}
	else	//branch two children
	{
		while(node -> leftchild)
		{
			cout << "swapping " << node->label << " (delete target) with " << node->leftchild->label << endl;
			swap(node, node->leftchild);
		}
		cout << "moving and deleting two children branch - " << node->label << endl;
		delete node;
	}
}

void Tree::swap(treeNode* parent, treeNode* child) //used in AVL implementation
{
	//creo que el error podría estar aqui o en borrar nodo con dos hijos
	//no linkear bien el padre si se hace el swap con el hijo de la derecha
	child->parent = parent->parent;
	parent->parent = child;
	if (child->label < parent->label)
		child->rightchild = parent;
	else if (child->label > parent->label)
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

void Tree::show()
{
	show(root);
}

void Tree::show(treeNode* input)
{
	if (input == NULL)
		return;
	show(input->leftchild);
	cout << "label: " << input->label << endl;
	cout << "palindrome: " << input->palindrome << endl; 
	cout << "count: " << input->count << endl;
	if (input->leftchild !=NULL)
		cout << "leftchild: "<< input->leftchild->label << endl;
	else
		cout << "leftchild: NULL" << endl; 
	if (input->rightchild !=NULL)
		cout << "rightchild: "<< input->rightchild->label << endl;
	else
		cout << "rightchild: NULL" << endl;
	if (input->parent !=NULL)
		cout << "parent: "<< input->parent->label << endl;
	else
		cout << "parent: NULL" << endl;
	cout << "_________________________________________________" << endl;
	show(input->rightchild);
}