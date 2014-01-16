//binary search tree
[BST|treeNode *root|-void add(treeNode* input, treeNode* node);-void search(treeNode* node);-void traverse(treeNode* node);-void remove(treeNode * node);-int removeAllNotPalindromes(treeNode* node);-void show(treeNode* input);-void removeAll(treeNode* node);-void swap(treeNode* parent, treeNode* child);-void remplaceNodeInParent(treeNode* parent, treeNode* node)|+Tree();+~Tree();+void add(string input);+void search();+void traverse();+int removeAllNotPalindromes();+void show()]

//tree node
[TreeNode|string label;bool palindrome;int count;treeNode* leftchild;treeNode* rightchild;treeNode* parent;]

//stack and queue node
[Node<T>|T data;node<T>* next]

//stack
[Stack<T>|node<T>* top|Stack();~Stack();bool isEmpty();void push(int n);T pop();T getTop();void makeNull()]

//queue
[Queue<T>|node<T>* _front;node<T>* _rear|Queue();~Queue();void enqueue(T c);T dequeue();T front();T rear();void makenull();bool isEmpty();int size()]


//UML
[Node<T>|T data;node<T>* next]+->[Stack<T>|node<T>* top|Stack();~Stack();bool isEmpty();void push(int n);T pop();T getTop();void makeNull()]
[Node<T>|T data;node<T>* next]+->[Queue<T>|node<T>* _front;node<T>* _rear|Queue();~Queue();void enqueue(T c);T dequeue();T front();T rear();void makenull();bool isEmpty();int size()]

[TreeNode|string label;bool palindrome;int count;treeNode* leftchild;treeNode* rightchild;treeNode* parent;]+->[BST|treeNode *root|-void add(treeNode* input, treeNode* node);-void search(treeNode* node);-void traverse(treeNode* node);-void remove(treeNode * node);-int removeAllNotPalindromes(treeNode* node);-void show(treeNode* input);-void removeAll(treeNode* node);-void swap(treeNode* parent, treeNode* child);-void remplaceNodeInParent(treeNode* parent, treeNode* node)|+Tree();+~Tree();+void add(string input);+void search();+void traverse();+int removeAllNotPalindromes();+void show()]