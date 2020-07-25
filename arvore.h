typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
}Node;
void makeTree(Node **pRoot);
void insert(Node **pRoot, int key2);
void remove(Node **pRoot, int key2);
void destroy(Node **pRoot);
void showInOrder(Node *pRoot);
void showPreOrder(Node *pRoot);
void showPostOrder(Node *pRoot);
int countNodes(Node *pRoot);
//int countLeafs(Node *pRoot);
int high(int a, int b);
int height(Node *pRoot);
void menuBin();
