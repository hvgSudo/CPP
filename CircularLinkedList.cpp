#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class CircularLinkedList : private Node {
    Node *link, *head;
    public:
        CircularLinkedList() {
            head = link = NULL;
        }
        void insert(int, int, int);
        void deleteNode(int, int);
        void display();
};

int main() {
    CircularLinkedList c;
    char ch;
    int option = -1, data, position = -1;
    int choice;
    while (ch == 'y') {
        cout << endl << "1. Create the list";
        cout << endl << "2. Insert at beginning";
        cout << endl << "3. Insert at any position";
        cout << endl << "4. Insert at the end";
        cout << endl << "5. View the list";
        cout << endl << "6. Delete node from start";
        cout << endl << "7. Delete node at any position";
        cout << endl << "8. Delete node from the end";
        cout << endl << "9. Exit";
        cout << endl << "Enter your choice: ";
        cin >> ch;
        switch (choice) {
            case 1:
                cout << endl << "Enter data to create the list: ";
                cin >> data;
                c.insert(1, data, position);
                c.display();
                break;
            case 2:
                cout << endl << "Enter the data: ";
                cin >> data;
                c.insert(2, data, position);
                c.display();
                break;
            case 3:
                cout << endl << "Enter the data: ";
                cin >> data;
                c.display();
                cout << endl << "Enter the position: ";
                cin >> position;
                c.insert(3, data, position);
                c.display();
                break;
            case 4:
                cout << endl << "Enter the data: ";
                cin >> data;
                c.insert(4, data, position);
                c.display();
                break;
            case 5:
                c.display();
                break;
            case 6:
                c.display();
                c.deleteNode(1, position);
                c.display();
                break;
            case 7:
                c.display();
                cout << endl << "Enter the position from"
                    << " where you want to delete data: ";
                cin >> position;
                c.deleteNode(2, position);
                c.display();
                break;
            case 8:
                c.display();
                c.deleteNode(3, position);
                c.display();
                break;
            case 9:
                ch = 'n';
                break;
            default:
                cout << endl << "Wrong choice";
        }
    }
    return 0;
}

void CircularLinkedList::insert(int option,
                         int data, int position) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    int currentPosition = 1;
    // create the list
    if (option == 1) {
        if (head == NULL) {
        head = link = temp;
        temp->next = link;
        } else  {
            link->next = temp;
            temp->next = head;
            link = link->next;
        }
    } else if (option == 2) {
        // insert at start
        link = head;
        while (link->next != head) 
            link = link->next;
        link->next = temp;
        temp->next = head;
        head = temp;
    } else if (option == 3) {
        // insert at any position
        link = head;
        while (currentPosition < position) {
            link = link->next;
            currentPosition++;
        }
        temp->next = link->next;
        link->next = temp;
    } else if (option == 4) {
        // insert at end
        link = head;
        while(link->next != head)
            link = link->next;
        link->next = temp;
        temp->next = head;
    }
}

void CircularLinkedList::display() {
    link = head;
    cout << endl << "The list is: ";
    if (head != NULL) {
        do {
            cout << link->data << " ";
            link = link->next;
        } while (link != head);
    }
    else 
        cout << endl << "List is empty";
    cout << endl;
}

void CircularLinkedList::deleteNode(int option, 
                            int position) {
    Node *temp = new Node;
    if (head == NULL)
        cout << endl << "List is empty";
    else {
        link = head;
        if (option == 1) { 
            // delete at beginning
            head = link->next;
            delete(link);
        } else if (option == 2) {
            // delete at any position
            for (int i = 0; i < position - 1; i++)
                link = link->next;
                temp = link->next;
                link->next = temp->next;
                delete(temp);
        } else if (option == 3) {
            // delete from last
            while (link->next->next != head)
                link= link->next;
            temp = link->next;
            link->next = head;
            delete(temp);
        }
    }
}