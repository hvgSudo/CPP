#include<iostream>

using namespace std;

class node {
    public:
        int data;
        node *next;
};

class list : private node {
    node *link, *head;
    int d;
    public:
        list() {
            link = NULL;
            head = NULL;
        }
        void add();
        void display();
};

int main() {
    list l;
    int choice, a = 1;
    while (a == 1) {
        cout << endl << "1. Add to the list";
        cout << endl << "2. Display the list";
        cout << endl << "3. Exit";
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                l.add();
                break;
            case 2:
                l.display();
                break;
            case 3:
                a = 0;
                break;
            default:
                cout << endl << "Wrong choice";
        }
    }
    return 0;
}

void list::add() {
    cout << endl << "Enter the number to be entered to the list: ";
    cin >> d;
    node *a = new node;
    a->data = d;
    a->next = NULL;
    if (head == NULL) {
        head = a;
        link = a;
    } else {
        link->next = a;
        link = a;
    }
}

void list::display() {
    cout << endl << "The list is";
    link = head;
    cout << " " << link->data;
    while (link != NULL) {
        link = link->next;
        cout << " " << link->data;
    }
}