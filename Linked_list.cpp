#include<iostream>

using namespace std;

class node {
    public:
        int data;
        node *next;
};

void add(node **, int);
void display(node *);

int main() {
    int d, n;
    node *head = NULL;
    cout << endl << "How many numbers do you want to enter: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << endl << "Number " << i + 1 << ": ";
        cin >> d;
        add(&head, d); 
    }
    for (int i = 0; i < n; i++)
        display(head);
    return 0;
}

void add(node **head_ref, int data) {
    node *new_node = NULL;
    new_node = new node();
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void display(node *head) {
    cout << endl;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}