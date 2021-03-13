#include<iostream>

using namespace std;

class node {
    public:
        int data;
        node *prev, *next;
};

class DLL : private node {
    node *link, *head;
    public:
        DLL () {
            link = NULL;
            head = NULL;
        }
        void createDLL(int);
        void insertNode(int, int);
        void insertNodePosition(int, int);
        void deleteNode(int, int);
        void reverseDLL();
        void display();
        void concatenate(DLL);
};

int main() {
    return 0;
}

void DLL::createDLL(int data) {
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL) {
        link = temp;
        head = temp;
    } else {
        link->next = temp;
        temp->prev = link;
    }
}

void DLL::insertNode(int option, int data) {
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (option == 1) {
        // insert at beginning
        temp->next = head;
        head->prev = temp;
        head = temp;
    } else if (option == 2) {
        // insert at the end
        link = head;
        while (link->next != NULL) 
            link = link->next;
        link->next = temp;
        temp->prev = link;
    }
}

void DLL::insertNodePosition(int data, int position) {
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    int currentPosition = 1;
    link = head;
    while (currentPosition < position) {
        link = link->next;
        currentPosition++;
    }
    link->next = temp;
    temp->prev = link;
    if (link->next->next == NULL) {
        temp->next = link->next->next;
        link->next->next->prev = temp;
    }
}

void DLL::deleteNode(int option, int position) {
    if (head == NULL) {
        cout << endl << "List is empty";
        return;
    }
    node *temp;
    link = head;
    int currentPosition = 1;
    if (option == 1) {
        // delete from beginning
        head = link->next;
        head->prev = NULL;
        delete(link);        
    } else if (option == 3) {
        // delete from last
        while (link->next != NULL) 
            link = link->next;
        temp = link;
        link = link->prev;
        delete(temp);
    } else if (option == 2) {
        // delete from a specific position
        while (currentPosition < position) {
        link = link->next;
        currentPosition++;
        }
        temp = link;
        link = link->next;
        link->prev = temp->prev;
        delete(temp);
    }
}

void DLL::display() {
    link = head;
    while (link->next != NULL) {
        cout << link->data << " ";
        link = link->next;
    }
}

void DLL::reverseDLL() {
    node *temp;
}