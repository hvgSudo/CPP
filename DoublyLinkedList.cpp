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

void printMenu() {
    cout << "\n1. View the list" <<
        "\n2. Create the list" <<
        "\n3. Insert elements into the list" <<
        "\n4. Delete elements from the list" << 
        "\n5. Reverse the list" << 
        "\n6. Exit";
}

int main() {
    int choice, c, index, data, a, position;
    int exit = 0;
    char ch, h;
    DLL d[2];
    do {
        cout << "\nWhich list do you want to work upon(1 or 2): ";
        cin >> c;
        index = c - 1;
        printMenu();
        cout << "\nEnter your choice of action: ";
        cin >> choice;
        switch(choice) {
            case 1:
                d[index].display();
                break;
            case 2:
                cout << "\nEnter the data to be inserted: ";
                cin >> data;
                d[index].createDLL(data);
                d[index].display();
                break;
            case 3:
                cout << "\n1. Insert at beginning" <<
                    "\n2. Insert at a specific position" <<
                    "\n3. Insert at last";
                cout << "\nEnter your choice: ";
                cin >> a;
                cout << "\nEnter the data to be inserted: ";
                cin >> data;
                if (a == 1) 
                    d[index].insertNode(1, data);
                else if (a == 2) {
                    cout << "\nEnter the position where you want to insert: ";
                    cin >> position;
                    d[index].insertNodePosition(data, position);
                }
                else if (a == 3)
                    d[index].insertNode(2, data);
                d[index].display();
                break;
            case 4:
                cout << "\n1. Delete at beginning" <<
                    "\n2. Delete at a specific position" <<
                    "\n3. Delete at last";
                cout << "\nEnter your choice: ";
                cin >> a;
                if (a == 1)
                    d[index].deleteNode(1, -1);
                else if (a == 2) {
                    cout << "\nEnter the position where you want to insert: ";
                    cin >> position;
                    d[index].deleteNode(2, position);
                }
                else if (a == 3)
                    d[index].deleteNode(3, -1);
                d[index].display();
                break;
            case 5:
                d[index].reverseDLL();
                d[index].display();
                break;
            case 6:
                exit = 1;
                break;
            default:
                cout << "\nWrong choice";
        }
        cout << "\nYou have two lists";
        cout << ", do you want to concatenate them(y/n): ";
        cin >> ch;
        if (ch == 'y') {
            d[0].concatenate(d[1]);
            cout << "\nDo you want to exit(y/n): ";
            cin >> h;
            if (h == 'y') {
                exit = 1;
                break;
            }
        }
    } while (exit == 0);
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
    cout << "\nThe list is ";
    link = head;
    while (link != NULL) {
        cout << link->data << " ";
        link = link->next;
    }
}

void DLL::reverseDLL() {
    node *current, *forward;
    forward = head;
    while (current != NULL) {
        current = forward->prev;
        forward->prev = forward->next;
        forward->next = current;
        forward = forward->prev;
    }
    if (current != NULL)
    forward = current->prev;
}

void DLL::concatenate(DLL d) {
    if (head == NULL) {
        cout << endl << "List 1 is empty";
        return;
    } else if (d.head == NULL) {
        cout << endl << "List 2 is empty";
        return;
    } else {
        link = head;
        while (link->next != NULL) 
            link = link->next;
        link->next = d.head;
        d.head->prev = link;
        display();
    }
}