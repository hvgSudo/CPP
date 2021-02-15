#include<iostream>

using namespace std;

class node {
    public:
        int data;
        node *next;
};

class linkedList : private node {
    node *link, *head;
    int count;
    public:
        linkedList() {
            head = NULL;
            link = NULL;
            count = 1;
        }
        int getCount() {
            return count;
        }
        void insert(int, int);
        void display();
};

int main() {
    int d, choice, c;
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
                cout << endl << "Enter the integer to insert: ";
                cin >> d;
                cout << endl << "1. At the beginning";
                cout << endl << "2. At any position";
                cout << endl << "3. At the end";
                cout << endl << "The list has " << l.getCount() - 1
                    << " elements";
                cout << endl << "Enter your choice: ";
                cin >> c;
                if (c == 1) 
                    l.insert(d, 1);
                else if (c == 2)
                    l.insert(d, 2);
                else
                    l.insert(d, 3);
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

void linkedList::insert(int data, int position) {
    count = count + 1;
    int n = 0;
    node *temp = new node;
    if (position == 1) {
        temp->data = data;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            link = temp;
        } else {
            link->next = temp;
            link = temp;
        }
    } else if (position == 2) {
        temp->data = data;
        temp->next = NULL;
        while (n < position) {
            link = link->next;
            n = n + 1;
        }
        temp->next = link->next;
        link->next = temp;
    } else if (position == 3) {
        temp->data = data;
        temp->next = NULL;
        while (link->next->next != NULL)
            link = link->next;
        temp->next = link->next->next;
        link->next = temp;
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