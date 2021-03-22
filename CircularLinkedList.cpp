#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class circularLinkedList : private Node {
    Node *link, *head;
    public:
        circularLinkedList() {
            head = link = NULL;
        }
        void insert(int, int, int);
        void deleteNode(int, int);
        void display();
        void reverse();
        friend void concatenate(circularLinkedList,
            circularLinkedList);
};

int main() {
    circularLinkedList c[2];
    char ch = 'y', h, e;
    int option = -1, data, position = -1;
    int choice, list, r;
    while (ch == 'y') {
        cout << endl << "You have two lists";
        cout << endl << "Which linked list do you want to" <<
            " work upon (1 or 2): ";
        cin >> list;
        r = list - 1;
        cout << endl << "1. Create the list";
        cout << endl << "2. Insert at beginning";
        cout << endl << "3. Insert at any position";
        cout << endl << "4. Insert at the end";
        cout << endl << "5. View the list";
        cout << endl << "6. Delete node from start";
        cout << endl << "7. Delete node at any position";
        cout << endl << "8. Delete node from the end";
        cout << endl << "9. Reverse the list";
        cout << endl << "10. Exit";
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << endl << "Enter data to create the list: ";
                cin >> data;
                c[r].insert(1, data, position);
                c[r].display();
                break;
            case 2:
                cout << endl << "Enter the data: ";
                cin >> data;
                c[r].insert(2, data, position);
                cout << endl << "After Insertion";
                c[r].display();
                break;
            case 3:
                cout << endl << "Enter the data: ";
                cin >> data;
                c[r].display();
                cout << endl << "Enter the position: ";
                cin >> position;
                c[r].insert(3, data, position);
                cout << endl << "After Insertion";
                c[r].display();
                break;
            case 4:
                cout << endl << "Enter the data: ";
                cin >> data;
                c[r].insert(4, data, position);
                cout << endl << "After Insertion";
                c[r].display();
                break;
            case 5:
                c[r].display();
                break;
            case 6:
                c[r].display();
                c[r].deleteNode(1, position);
                cout << endl << "After Deletion";
                c[r].display();
                break;
            case 7:
                c[r].display();
                cout << endl << "Enter the position from"
                    << " where you want to delete data: ";
                cin >> position;
                c[r].deleteNode(2, position);
                cout << endl << "After Deletion";
                c[r].display();
                break;
            case 8:
                c[r].display();
                c[r].deleteNode(3, position);
                cout << endl << "After Deletion";
                c[r].display();
                break;
            case 9:
                c[r].display();
                cout << endl << "After reversal";
                c[r].reverse();
                c[r].display();
                break;
            case 10:
                ch = 'n';
                break;
            default:
                cout << endl << "Wrong choice";
        }
        cout << endl << "Do you want to concatenate " << 
            "the two lists(y/n): ";
        cin >> h;
        if (h == 'y') {
            concatenate(c[0], c[1]);
            cout << endl << "Do you want to exit(y/n): ";
            cin >> e;
            if (e == 'y')
                break;
        } else {
            cout << endl << "Do you want to exit(y/n): ";
            cin >> e;
            if (e == 'y')
                break;
        }
    }
    return 0;
}

void circularLinkedList::insert(int option,
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
        } else {
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

void circularLinkedList::display() {
    link = head;
    cout << endl << "The list is: ";
    if (head != NULL) {
        do {
            cout << link->data << " ";
            link = link->next;
        } while (link != head);
        cout << link->data;
    }
    else 
        cout << endl << "List is empty";
    cout << endl;
}

void circularLinkedList::deleteNode(int option, 
                            int position) {
    Node *temp = new Node;
    if (head == NULL)
        cout << endl << "List is empty";
    else {
        link = head;
        if (option == 1) { 
            // delete at beginning
            temp = head;
            while (link->next != head) 
                link = link->next;
            head = head->next;
            link->next = head;
            delete(temp);
        } else if (option == 2) {
            // delete at any position
            for (int i = 0; i < position - 1; i++)
                link = link->next;
            temp = link->next;
            link->next = temp->next;
            delete(temp);
        } else if (option == 3) {
            // delete from last
            link = head;
            while (link->next->next != head)
                link= link->next;
            temp = link->next;
            link->next = head;
            delete(temp);
        }
    }
}

void circularLinkedList::reverse() {
    if (head == NULL)
        return;
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    current->next = prev;
    current = prev;
}

void concatenate(circularLinkedList first, 
    circularLinkedList second) {
    if (first.head == NULL)
        cout << endl << "First list has not"
            << " been created";
    else if (second.head == NULL)
        cout << endl << "Second list has not"
            << " been created";
    else {
        first.link = first.head;
        while (first.link->next != first.head)
            first.link = first.link->next;
        cout << endl <<"End of list one";
        first.link->next = second.head;
        second.link = second.head;
        while (second.link->next != second.head)
            second.link = second.link->next;
        second.link->next = first.head;
        cout << endl << "After concatenating";
        first.display();
    }
}