#include<iostream>

using namespace std;

class Node {
    private:
        int data;
        Node *left, *right;
    public:
        Node(int data) {
            this->data = data;
            left = right = NULL;
        }
        friend class BST;
};

class BST {
    private:
        Node *root;
        void inorder(Node *temp) {
            if (temp != NULL) {
                inorder(temp->left);
                cout << temp->data << " ";
                inorder(temp->right);
            }
        }
    public:
        BST() { root = NULL; }
        void insertNode();
        void deleteNode();
        void display() {
            cout << "\nInorder traversal of the tree -> ";
            inorder(root);
        }
        void searchTree();
        ~BST() { delete(root); }
};

void printActionMenu() {
    cout << "\n1. Insert into the tree" <<
            "\n2. Delete from the tree" <<
            "\n3. View the inorder traversal of the tree" << 
            "\n4. Search for an element in the tree" <<
            "\n5. Exit";
}

int main() { // Main function
    BST tree;
    int choice, data;
    bool exit = false;
    while (!exit) {
        printActionMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                tree.insertNode();
                break;
            case 2:
                tree.deleteNode();
                break;
            case 3:
                tree.display();
                break;
            case 4:
                tree.searchTree();
                break;
            case 5:
                exit = true;
                break;
            default:
                cout << "\nWrong choice";
        }
    } 
    return 0;
}

void BST::insertNode() {
    Node *newNode, *temp, *parentNode;
    int data;
    char ch;
    do {
        cout << "\nEnter the data to be inserted: ";
        cin >> data;
        temp = root;
        newNode = new Node(data);
        if (root == NULL)
            root = newNode;
        else {
            while (temp!= NULL) {
                parentNode = temp;
                if (data > temp->data)
                    temp = temp->right;
                else
                    temp = temp->left;
            }
            if (data > parentNode->data)
                parentNode->right = newNode;
            else
                parentNode->left = newNode;
        }
        cout << "\nDo you want to continue(y/n): ";
        cin >> ch;
    }while (ch == 'y' || ch == 'Y');
}

void BST::deleteNode() {
    Node *swapNode, *temp, *checkRight, *checkLeft;
    char ch;
    int data;
    bool foundNode = false;
    temp = root;
    do {
        cout << "\nEnter the number to be deleted: ";
        cin >> data;
        while (temp != NULL) {
            if (data == temp->data) {
                foundNode = true;
                break;
            } else {
                swapNode = temp;
                if (data > temp->data)
                    temp = temp->right;
                else    
                    temp = temp->left;
            }
        }
        if (!foundNode) 
            cout << "\n" << data << " not found in the tree";
        else {
            // Node with single child either left or right
            if ((temp->left == NULL && temp->right != NULL) || 
                (temp->left != NULL && temp->right == NULL)) {
                    if (temp->left == NULL && temp->right != NULL) {
                        if (swapNode->left == temp) 
                            swapNode->left = temp->right;
                        else 
                            swapNode->right = temp->right;
                        delete(temp);
                    } else { // left child present and right child absent
                        if (swapNode->left == temp) 
                            swapNode->left = temp->left;
                        else 
                            swapNode->right = temp->left;
                        delete(temp);
                    }
            } else if (temp->left == NULL && temp->right == NULL) {
                // leaf node
                if (swapNode->left == temp)
                    swapNode->left = NULL;
                else
                    swapNode->right = NULL;
                delete(temp);
            } else if (temp->left != NULL && temp->right != NULL) {
                // node has both left and right children
                checkRight = temp->right;
                if (checkRight->left == NULL && checkRight->right == NULL) {
                    // node has no children
                    temp = checkRight;
                    delete(checkRight);
                    temp->right = NULL;
                } else { // node has children
                    if (checkRight->right->left) {
                        // has left child
                        Node *current = checkRight->right;
                        Node *currentLeft = checkRight->right->left;
                        while (currentLeft != NULL) {
                            current = currentLeft;
                            currentLeft = currentLeft->left;
                        }
                        temp->data = currentLeft->data;
                        delete(currentLeft);
                        current->left = NULL;
                    } else {
                        // has right child
                        Node *current = temp->right;
                        temp->data = current->data;
                        temp->right = current->right;
                        delete(current);
                    }
                }
            }
            cout << "\nNumber removed from the tree";
        }
        cout << "\nDo you want to remove more nodes (y/n): ";
        cin >> ch;
    } while(ch == 'y' || ch == 'Y');
}

void BST::searchTree() {
    Node *swapNode, *temp = root;
    char ch;
    bool foundNode = false;
    int data, j = 0, present = -1;
    do {
        cout << "\nEnter the number to be deleted: ";
        cin >> data;
        while (temp != NULL) {
            if (data == temp->data) {
                foundNode = true;
                break;
            } else {
                swapNode = temp;
                if (data > temp->data)
                    temp = temp->right;
                else    
                    temp = temp->left;
            }
        }
        if (!foundNode) 
            cout << "\n" << data << " not found in the tree";
        cout << "\nDo you want to search for more elements(y/n): ";
        cin >> ch;
    }while (ch == 'y' || ch == 'Y');
}