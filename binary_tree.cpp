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

class stack { 
    int top;
    node *data[10];
    public:
        stack() {
            top = -1;
        }
        void push(node *p) {
            data[++top] = p;
        }
        node *pop() {
            return data[top--];
        }
        node *getTop() { return data[top]; }
        int isFull() { return top == 10; }
        int isEmpty() { return top == -1; }
};

class binaryTree {
    node *root;
    void preorder(node *currentNode) {
        if (currentNode != NULL) {
            cout << currentNode->data << " ";
            preorder(currentNode->left);
            preorder(currentNode->right);
        }
    } // recursive
    void inorder(node *currentNode) {
        if (currentNode != NULL) {
            inorder(currentNode->left);
            cout << currentNode->data << " ";
            inorder(currentNode->right);
        }
    }
    void postorder(node *currentNode) {
        if (currentNode != NULL) {
            postorder(currentNode->left);
            postorder(currentNode->right);
            cout << currentNode->data << " ";
        }
    }
    void preorderLoop(node *); // non recursive
    void inorderLoop(node *);
    void postorderLoop(node *);
    
    public:
        binaryTree () {
            root = NULL;
        }
        void create();
        void preorder();
        void postorder();
        void inorder();
        void insert();
        void deleteNode(char c);
        void totalNodes();
        int leafNodes();
        void mirror(binaryTree &);
        void copy(binaryTree &);
};

void menu() {
    cout << "\n1 - Create the tree" <<
        "\n2 - Preorder traversal" <<
        "\n3 - Inorder traversal" << 
        "\n4 - Postorder traversal" <<
        "\n5 - Insert more elements to the tree" <<
        "\n6 - Exit";
    cout << "\nEnter your choice: ";  
}

int main() { // This is the main method
    binaryTree b;
    bool exit = false;
    int choice;
    while (!exit) {
        menu();
        cin >> choice;
        switch(choice) {
            case 1:
                b.create();
                break;
            case 2:
                b.preorder();
                break;
            case 3:
                b.inorder();
                break;
            case 4:
                b.postorder();
                break;
            case 5:
                b.insert();
                break;
            case 6:
                exit = true;
                break;
            default:
                cout << "\nWrong choice";
        }
    }
    return 0;
}

void binaryTree::create() {
    node *temp, *newNode;
    char ans, c, choice;
    int data;
    do {
        cout << endl << "Enter the element to be attached: ";
        cin >> data;
        newNode = new node(data);
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
        cout << endl << "Do you want to insert more elements(y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void binaryTree::preorder() {
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

void binaryTree::inorder() {
    int choice;
    cout << endl << "1. Recursive\n" <<
        "2. Non recursive";
    cout << "\nEnter your choice: ";
    cin >> choice;
    cout << "\nInorder traversal: ";
    if (choice == 1) 
        inorder(root);
    else if (choice == 2)
        inorderLoop(root);
}

void binaryTree::postorder() {
    int choice;
    cout << endl << "1. Recursive\n" <<
        "2. Non recursive";
    cout << "\nEnter your choice: ";
    cin >> choice;
    cout << "\nPostorder traversal: ";
    if (choice == 1) 
        postorder(root);
    else if (choice == 2)
        postorderLoop(root);
}

void binaryTree::preorderLoop(node *copy) {
    stack s;
    node *temp;
    if (copy == NULL)
        return;
    s.push(copy);
    while (!s.isEmpty()) {
        temp = s.getTop();
        cout << temp->data << " ";
        s.pop();
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

void binaryTree::inorderLoop(node *copy) {
    node *temp = copy;
    stack s;
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

void binaryTree::postorderLoop(node *copy) {
    if (copy == NULL)
        return;
    stack s;
    do {
        while (copy != NULL) {
            if (copy->right)
                s.push(copy->right);
            s.push(copy); 
            copy = copy->left; 
        }
        copy = s.pop(); 
        if (copy->right && s.getTop() == copy->right) {
            s.pop(); 
            s.push(copy); 
            copy = copy->right; 
        } else {
            cout << copy->data << " ";
            copy = NULL;
        }
    } while (!s.isEmpty());
}

void binaryTree::insert() {
    int d;
    char ch, choice;
    node *temp;
    node *addition = new node(d);
    do {
        cout << endl << "Enter the element to be attached: ";
        cin >> d;
        addition = new node(d);
        if (root == NULL)
            root = addition;
        else {
            temp = root;
            while (1) {
                cout << endl << "Left or right (l/r) of " << 
                temp->data << ": ";
                cin >> ch;
                if (ch == 'l') {
                    if (temp->left == NULL) {
                        temp->left = addition;
                        break;
                    }
                    else
                        temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        temp->right = addition;
                        break;
                    }
                    else
                        temp = temp->right;
                }
            }
        } 
        cout << endl << "Do you want to insert more elements(y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}