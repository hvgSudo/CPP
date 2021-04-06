#include<iostream>
#include<string.h>

using namespace std;

class Node {
    private :
        int data;
        Node *left, *right;
    public :
        Node(int number) {
            data = number;
            left = NULL;
            right = NULL;
        }
        friend class BT;
};

class BT {
    private :
        Node *root;
        Node preorder(Node *current);
        Node inorder(Node *current);
        Node postorder(Node *current);
        Node preorderLoop(Node *current);
        Node inorderLoop(Node *current);
        Node postorderLoop(Node *current);
    public :
        void create();
        void insert();
        void preorder();
        void inorder();
        void postorder();
};

int main() {
    return 0;
}

void BT::create() {
    Node *newNode;
    int number;
    cout << "\nEnter the root node: ";
    cin >> number;
    newNode = new Node(number);
    root = newNode;
}

void BT::insert() {
    Node *newNode;
    Node *temp = root;
    int number;
    string position;
    cout << "\nEnter the number: ";
    cin >> number;
    newNode = new Node(number);
    while (true) {
        cout << "\nleft or right of " << temp->data << ": ";
        cin >> position;
        if (position.toLowerCase().compare("left")) {
            if (temp->left == NULL) {
                temp->left = newNode;
                break;
            }
            else
                temp = temp->left;
        } else if (position.tLowerCase().compare("right")) {

        }
    }            
}