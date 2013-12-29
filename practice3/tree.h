#include <string.h>

#include "treeNode.h"

#ifndef TREE_H
#define TREE_H

class Tree
{

private:
	treeNode *root;

public:
	Tree();
	~Tree();
	void add(string input);
	void insert(string input, treeNode* node);
	void swap(treeNode* parent, treeNode* child);
	void search();
	void traverse();
	void remove();

};

#endif