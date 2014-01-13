<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> 92d71e9d837dfe6d33fe9b311090ca77b388d0ab
#include "treeNode.h"
#include "functions.h"

#ifndef TREE_H
#define TREE_H

using namespace std;

class Tree
{

private:
	treeNode *root;
<<<<<<< HEAD
	void add(treeNode* input, treeNode* node);
=======
	void insert(string input, treeNode* node);
	void search(treeNode* node);
	void traverse(treeNode* node);
	void remove(treeNode * node);
	void removeAllNotPalindromes(treeNode* node);

	//handling functions
>>>>>>> 92d71e9d837dfe6d33fe9b311090ca77b388d0ab
	void swap(treeNode* parent, treeNode* child);
	void remplaceNodeInParent(treeNode* parent, treeNode* node);
	
public:
	Tree();
	~Tree();
	void add(string input);
	void search();
	void traverse();
	void remove();
	void removeAllNotPalindromes();

};

#endif