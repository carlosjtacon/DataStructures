#include "treeNode.h"
#include "functions.h"

#ifndef TREE_H
#define TREE_H

using namespace std;

class Tree
{

private:
	treeNode *root;
	void insert(string input, treeNode* node);
	void search(treeNode* node);
	void traverse(treeNode* node);
	void remove(treeNode * node);
	void removeAllNotPalindromes(treeNode* node);

	//handling functions
	void swap(treeNode* parent, treeNode* child);
	void remplaceNodeInParent(treeNode* parent, treeNode* node);
	
public:
	Tree();
	~Tree();
	void insert(string input);
	void search();
	void traverse();
	void remove();
	void removeAllNotPalindromes();

};

#endif