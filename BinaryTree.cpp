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
    Node *newNode, *temp;
    int number;
    char position, ch;
    cout << "\nEnter the root node: ";
    cin >> number;
    newNode = new Node(number);
    if (root == NULL)
        root = newNode;
    else {
        temp = root;
        do {
            cout << "\nEnter the number: ";
            cin >> number;
            newNode = new Node(number);
            while (true) {
                cout << "\nLeft or right (l/r) of " << temp->data << ": ";
                cin >> position;
                if (position == 'l') {
                    if (temp->left == NULL) {
                        temp->left = newNode;
                        break;
                    }
                    else
                        temp = temp->left;
                } else if (position == 'r') {
                    if (temp->right == NULL) {
                        temp->right = newNode;
                        break;
                    }
                    else
                        temp = temp->right;
                }
            }
            cout << "\nDo you want to insert more elements(y/n): ";
            cin >> ch;
        }while(ch == 'y' || ch == 'Y');
    }
}

void BT::insert() {
    Node *newNode;
    Node *temp = root;
    int number;
    char position, ch;
    do {
        cout << "\nEnter the number: ";
        cin >> number;
        newNode = new Node(number);
        while (true) {
            cout << "\nLeft or right (l/r) of " << temp->data << ": ";
            cin >> position;
            if (position == 'l') {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    break;
                }
                else
                    temp = temp->left;
            } else if (position == 'r') {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    break;
                }
                else
                    temp = temp->right;
            }
        }
        cout << "\nDo you want to insert more elements(y/n): ";
        cin >> ch;
    }while(ch == 'y' || ch == 'Y');            
}