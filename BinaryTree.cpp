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
        void preorderLoop(Node *current);
        void inorderLoop(Node *current);
        void postorderLoop(Node *current);
    public :
        void create();
        void insert();
        void preorder();
        void inorder();
        void postorder();
};

class stack {
    private :
        int top;
        Node *data[10];
    public :
        stack() {
            top = -1;
        }
        void push(Node *p) {
            data[++top] = p;
        }
        Node *pop() { return data[top--]; }
        Node *peek() { return data[top]; }
        int isFull() { return top == 10; }
        int isEmpty() { return top == -1; }
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

void BT::preorder() {
    int choice;
    cout << endl << "1. Recursive\n" <<
        "2. Non recursive";
    cout << "\nEnter your choice: ";
    cin >> choice;
    cout << "\nPreorder traversal: ";
    if (choice == 1) 
        preorder(root);
    else if (choice == 2)
        preorderLoop(root);
}

void BT::inorder() {
    int choice;
    cout << endl << "1. Recursive\n" <<
        "2. Non recursive";
    cout << "\nEnter your choice: ";
    cin >> choice;
    cout << "\nPreorder traversal: ";
    if (choice == 1) 
        inorder(root);
    else if (choice == 2)
        inorderLoop(root);
}

void BT::postorder() {
    int choice;
    cout << endl << "1. Recursive\n" <<
        "2. Non recursive";
    cout << "\nEnter your choice: ";
    cin >> choice;
    cout << "\nPreorder traversal: ";
    if (choice == 1) 
        postorder(root);
    else if (choice == 2)
        postorderLoop(root);
}

void BT::preorderLoop(Node *current) {
    stack s;
    Node *temp;
    if (current == NULL) 
        return;
    s.push(current);
    while (!s.isEmpty()) {
        temp = s.peek();
        cout << temp->data << " ";
        s.pop();
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

void BT::inorderLoop(Node *current) {
    stack s;
    Node *temp = current;
    bool exit = false;
    while (!exit) {
        while (temp != NULL) {
            s.push(temp);
            temp = temp->left;
        } 
        if (s.isEmpty()) {
            exit = true;
            break;
        }
        temp = s.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void BT::postorderLoop(Node *current) {
    if (current == NULL) 
        return;
    stack s;
    do {
        while (current != NULL) {
            if (current->right)
                s.push(current->right);
            s.push(current);
            current = current->left;
        }
        current = s.pop();
        if (current->right &&s.peek() == current->right) {
            s.pop();
            s.push(current);
            current = current->right;
        } else {
            cout << current->data << " ";
            current = NULL;
        }
    } while (!s.isEmpty());
}