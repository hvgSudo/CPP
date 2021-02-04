#include<iostream>

using namespace std;

class node {
    public:
        int data;
        node *next;
};

class list : private node {
    node *link;
    int d;
    public:
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
    link->next = a;
}

void list::display() {
    while (link != NULL) {
        cout << " " << link->data;
        link = link->next;
    }
}