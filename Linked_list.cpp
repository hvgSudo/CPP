/* #include<iostream>

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
        void add_middle();
        void display();
        void delete_node();
        void delete_last_node();
        void delete_intermmediate();
        void invert();
        void create_CLL();
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

void list::add_middle() {
    int x, n, i = 0;
    node *b = new node;
    cin >> x;
    b->data = x;
    b->next = NULL;
    cout << "Enter the position: ";
    cin >> n;
    while (i != n -1) {
        link = link->next;
        i++;
    }
    b->next = link->next;
    link->next = b;
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

void list::delete_node() {
    link = head;
    head = head->next; // or head = link->next;
    delete(link);
}

void list::delete_last_node() {
    link = head;
    node *a;
    while(link->next->next != NULL) 
        link = link->next;
    a = link->next;
    link->next = NULL;
    delete(a);
}

void list::delete_intermmediate() {
    node *a;
    int n;
    link = head;
    cout << "Enter position: ";
    cin >> n;
    for (int i = 0; i < n - 1; i++)
        link = link->next;
    a = link->next;
    link->next = link->next->next; // or link->next = a->next;
    delete(a);
}

void list::invert() {
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
}

void list::create_CLL() {
    int x;
    node *newNode = new node;
    cout << "Enter data: ";
    cin >> x;
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = link = newNode;
        newNode->next = link;
    } else {
        link->next = newNode;
        newNode->next = head;
        link = link->next;
    }
}

void concatTwoCLLs(list l) {
    link = head;
    while (link->next != head)
        link = link->next;
    link = l.head;
    l.link = l.head;
    while (l.link->next != l.head)
        l.link = l.link->next;
    l.link->next = head;
} */