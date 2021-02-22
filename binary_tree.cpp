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
        void totalNodes();
        int leafNodes();
        void mirror(binaryTree &);
        void copy(binaryTree &);
};

int main() {
    binaryTree b;
    b.create();
    return 0;
}

void binaryTree::create() {
    node *temp, *newNode;
    char ans, c, choice;
    int ch;
    do {
        cout << endl << "Enter the element to be attached: ";
        cin >> ch;
        newNode = new node(ch);
        if (root == NULL)
            root = newNode;
        else {
            temp = root;
            while (1) {
                cout << endl << "Left or right (l/r) of " << 
                temp->data << ": ";
                cin >> ans;
                if (ans == 'l') {
                    if (temp->left == NULL) {
                        temp->left = newNode;
                        break;
                    }
                    else
                        temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        temp->right = newNode;
                        break;
                    }
                    else
                        temp = temp->right;
                }
            }
        } 
        cout << endl << "Any more nodes(y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}