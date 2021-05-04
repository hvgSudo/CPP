#include<iostream>
#include<list>

using namespace std;
const int MAX = 4;

class graphNode { // Node class
    private:
        int vertex;
        graphNode *next;
    public:
        graphNode(int data) {
            vertex = data;
            next = NULL;
        }
        friend class AL;
};

class AL {
    private:
        list<graphNode> *adjList;
        int numberOfVertices;
    public:
        AL() {
            numberOfVertices = MAX;
            for (int j = 0; j < MAX; j++)
                adjList[j] = NULL;
        }
        void insert();
        void display();
};

void menu() {
    cout << "\n1. Insert into the graph" <<
        "\n2. Display" <<
        "\n3. Exit";
}

int main() { // Main function
    int choice;
    AL a;
    bool exit = false;
    while(!exit) {
        menu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                a.insert();
                break;
            case 2:
                a.display();
                break;
            case 3:
                exit = true;
                break;
            default:
                cout << "\nWrong choice";
        }
    } 
    return 0;
}

void AL::insert() {
    graphNode *temp, *newNode;
    char ch;
    for (int i = 0; i < numberOfVertices; i++) {
        for (int j = 0; j < numberOfVertices; j++) {
            cout << "\nIs there an edge between vertex "<< i <<
            " and " << j << ": ";
            cin >> ch;
            if (ch == 'y') {
                newNode = new graphNode(j + 1);
                if (adjList[i] == NULL) 
                    adjList[i] = temp = newNode;
                else {
                    temp->next = newNode;
                    temp = newNode;
                }
            }
        }
    }
}

void AL::display() {
    graphNode *temp;
    int i = 0;
    list<graphNode> :: iterator it;
    for (it = adjList.begin(); it != adjList.end(); ++i, ++it) {
        cout << "\nVertex " << i+1 << "->";
        temp = *it;
        while(temp != NULL) {
            cout << "v" << temp->vertex << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
}