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
        void remove(treeNode * node);
        void removeAllNotPalindromes(treeNode* node);
        void show(treeNode* input);
        void removeAll(treeNode* node);

        //handling functions
        void swap(treeNode* parent, treeNode* child);
        void remplaceNodeInParent(treeNode* parent, treeNode* node);
        
public:
        Tree();
        ~Tree();
        void add(string input);
        void search();
        void traverse();
        void removeAllNotPalindromes();
        void show();

};

#endif