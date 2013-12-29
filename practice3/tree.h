#include <string.h>

#include "node.h" //same node (?)

#ifndef TREE_H
#define TREE_H

template <typename T>
class Tree
{

private:
	//root ... (?)
	node<T>* root;

public:
	Tree();
	~Tree();
	void add(string input);
	void insert(string input, treeNode* node);
	void swap(treeNode* parent, treeNode* child);
	void search();
	void traverse();
	void remove();

	/* 
	parent: node tree -> node 
	leftmost_child: node tree -> node 
	right_sibling: node tree -> node 
	label: node tree -> label
	create: label tree tree -> tree 
	root: tree -> node
	makenull: tree -> tree 
	*/

};

#include "tree.cpp"

#endif