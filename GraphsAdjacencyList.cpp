#include<iostream>

using namespace std;

class Node { // Node class
    private:
        int data;
        Node *next;
    public:
        Node(int data) {
            this->data = data;
            next = NULL;
        }
        friend class AL;
};

class AL {
    private:
        Node *head;
    public:
        AL() { head = NULL; }
        bool insert(int);
};

void menu() {
    cout << "\n1. Insert into the graph" <<
        "\n2. Exit";
}

int main() { // Main function
    return 0;
}

bool AL::insert(int data) {
    
}