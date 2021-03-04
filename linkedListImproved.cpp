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
            count = 0;
        }
        int getCount() {
            return count;
        }
        void insert(int, int, int);
        void deleteNode(int);
        node *getHead() {
            return head;
        }
        void display();
        void reverse();
        friend void concatenate(linkedList, linkedList);
};

int main() {
    int d, choice, c, position, list, r;
    char ch = 'y', h, e;
    linkedList l[2];
    while (ch == 'y') {
        cout << endl << "You have two lists";
        cout << endl << "Do you want to concatenate " << 
            "the two lists(y/n): ";
        cin >> h;
        if (h == 'y') {
            concatenate(l[0], l[1]);
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
        cout << endl << "Which linked list do you want to" <<
            " work upon (1 or 2): ";
        cin >> list;
        r = list - 1;
        cout << endl << "1. Insert to the list";
        cout << endl << "2. Display the list";
        cout << endl << "3. Delete a node";
        cout << endl << "4. Reverse the list";
        cout << endl << "5. Exit";
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << endl << "Enter the integer to insert: ";
                cin >> d;
                cout << endl << "1. At the beginning";
                cout << endl << "2. At any position";
                cout << endl << "3. At the end";
                cout << endl << "The list has " << l[r].getCount()
                    << " elements";
                cout << endl << "Enter your choice: ";
                cin >> c;
                if (c == 1) 
                    l[r].insert(d, 1, 0);
                else if (c == 2) {
                    cout << endl << "Enter the position: ";
                    cin >> position;
                    l[r].insert(d, 2, position);
                }
                else
                    l[r].insert(d, 3, 0);
                break;
            case 2:
                cout << endl << "The list is";
                l[r].display();
                break;
            case 3:
                cout << endl << "1. Beginning node";
                cout << endl << "2. Any position";
                cout << endl << "3. Last node";
                cout << endl << "The list has " << l[r].getCount()
                    << " elements";
                cout << "Enter your choice: ";
                cin >> c;
                if (c == 1)
                    l[r].deleteNode(0);
                else if (c == 2) {
                    cout << endl << "Enter the position: ";
                    cin >> position;
                    l[r].deleteNode(position);
                } else
                    l[r].deleteNode(-1);
                break;
            case 4:
                l[r].reverse();
                break;
            case 5:
                ch = 'n';
                break;
            default:
                cout << endl << "Wrong choice";
        }   
    }
    return 0;
}

void linkedList::insert(int data, int position, int place) {
    count = count + 1;
    int n = 1;
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        link = temp;
    } else {
        if (position == 1) {
            link = head;
            temp->next = head;
            head = temp;
        } else if (position == 2) {
            link = head;
            while (n < place) {
                link = link->next;
                n = n + 1;
            }
            temp->next = link->next;
            link->next = temp;
        } else if (position == 3) {
            link = head;
            while (link->next != NULL)
                link = link->next;
            temp->next = link->next;
            link->next = temp;
        }     
    }
    cout << endl << "Element successfully inserted";
    display();
}

void linkedList::display() {
    node *temp = new node;
    temp = head;
    while (temp != NULL) {
        cout << endl << "\t" << temp->data;
        temp = temp->next; 
    }
}

void linkedList::deleteNode(int position) {
    count = count - 1;
    if (head == NULL) {
        cout << endl << "List is empty - Underflow";
        return;
    }
    link = head;
    if (position == 0) {
        head = link->next;
        delete(link);
    } else if (position == -1) { // delete from the last
        node *temp;
        while (link->next->next != NULL)
            link = link->next;
        temp = link->next;
        link->next = NULL;
        delete(temp);
    } else {
        node *temp;
        for (int i = 0; i < position - 1; i++) 
            link = link->next;
        temp = link->next;
        link->next = temp->next;
        delete(temp);
    }
    cout << endl << "Element successfully deleted";
    display();
}

void linkedList::reverse() {
    node *forward, *current, *backward;
    forward = head;
    current = NULL;
    while (forward != NULL) {
        backward = current;
        current = forward;
        forward = forward->next;
        current->next = backward;
    }
    head = current;
    cout << endl << "List successfully reversed";
    display();
}

void concatenate(linkedList first, linkedList second) {
    if (first.head == NULL) {
        cout << endl << "First list is not initialized";
        return;
    } else if (second.head == NULL) {
        cout << endl << "Second list is not initialized";
        return;
    } else {
        // Concatenating
        first.link = first.head;
        while (first.link->next != NULL)
            first.link = first.link->next;
        first.link->next = second.getHead();
        cout << endl << "After concatenating";
        first.display();
    }
}