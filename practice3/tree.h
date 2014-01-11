#include <string.h>

#include "treeNode.h"

#ifndef TREE_H
#define TREE_H

class Tree
{

private:
	treeNode *root;
	void insert(string input, treeNode* node);
	void swap(treeNode* parent, treeNode* child);
	
public:
	Tree();
	~Tree();
	void insert(string input);
	void search();
	void traverse();
	void remove();

};

#endif