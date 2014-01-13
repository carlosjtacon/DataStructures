#include "treeNode.h"
#include "functions.h"

#ifndef TREE_H
#define TREE_H

using namespace std;

class Tree
{

private:
        treeNode *root;
        void add(treeNode* input, treeNode* node);
        void search(treeNode* node);
        void traverse(treeNode* node);
        void removeNode(treeNode * node);
        void removeAllNotPalindromes(treeNode* node);

        //handling functions
        void swap(treeNode* parent, treeNode* child);
        void remplaceNodeInParent(treeNode* parent, treeNode* node);

        //debugging
        void show(treeNode* input);
        
public:
        Tree();
        ~Tree();
        void add(string input);
        void search();
        void traverse();
        void remove();
        void removeAllNotPalindromes();
        //debugging
        void show();

};

#endif