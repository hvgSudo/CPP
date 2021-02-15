#include<iostream>

using namespace std;

class node {
    node *left, *right;
    int data;
    public:
        node (int n) {
            data = n;
            left = right = NULL;
        }
        friend class binaryTree;
};

class binaryTree {
    node *root;
    void preorder(node *currentNode);
    void inorder(node *currentNode);
    void postorder(node *currentNode);
    public:
        binaryTree () {
            root = NULL;
        }
        void create();
        void preorder();
        void postorder();
        void inorder();
        void insert(char c);
        void deleteNode(char c);
        void totalNode();
};

int main() {
    return 0;
}

void create() {
    node *temp, *newNode;
    char ans, c, choice;
    
}