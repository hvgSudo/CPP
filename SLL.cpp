#include<iostream>

using namespace std;

class Node {
    private:
        int data;
        Node* next;
    public:
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
        friend class SLL;
};

class SLL {
    private:
        Node* head;
    public:
        SLL() {
            head = NULL;
        }
        void insert(int);
        void remove(int);
        void display(int);
};

void printMenu() {
    cout << "\n1. Create Linked List"
         << "\n2. Insert data into linked list"
         << "\n3. View linked list"
         << "\n4. Remove data from linked list"
         << "\n5. Exit"
         << "\nEnter your choice: ";
}

// Main function
int main() {
    SLL s;
    return 0;
}