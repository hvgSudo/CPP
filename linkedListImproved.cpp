#include<iostream>

using namespace std;

class node {
    public:
        int data;
        node *next;
};

class linkedList {
    node *link, *head;
    public:
        void create(int);
        void display();
};

int main() {
    int d, choice;
    char ch = 'y';
    linkedList l;
    while (ch == 'y') {
        cout << endl << "1. Insert to the list";
        cout << endl << "2. Display the list";
        cout << endl << "3. Exit";
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter the integer to insert: ";
                cin >> d;
                l.create(d);
                break;
            case 2:
                cout << endl << "The list is";
                l.display();
                break;
            case 3:
                ch = 'n';
                break;
            default:
                cout << endl << "Wrong choice";
        }   
    }
    return 0;
}

void linkedList::create(int data) {
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head->next = temp;
        link->next = temp;
    } else {
        link->next = temp;
        link = temp;
    }    
}

void linkedList::display() {
    node *temp = new node;
    temp = head;
    while (temp != NULL) {
        cout << endl << "\t" << temp->data;
        temp = temp->next; 
    }
}