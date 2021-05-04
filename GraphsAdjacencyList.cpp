#include<iostream>

using namespace std;

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
        graphNode *list[20];
        int numberOfVertices;
    public:
        AL(int n) {
            numberOfVertices = n;
            for (int j = 0; j < n; j++)
                list[j] = NULL;
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
    AL a = new AL(5);
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
    char ans;
    for (int i = 0; i < numberOfVertices; i++) {
        for (int j = 0; j < numberOfVertices; j++) {
            cout << "\nIs there an edge between vertex "<< i+1 <<
            j+1 << ": ";
            cin >> ans;
            if (ans == 'y') {
                newNode = new graphNode(j + 1);

                if (list[i] == NULL) 
                    list[i] = temp = newNode;
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
    for (int i = 0; i < numberOfVertices; i++) {
        cout << "\nVertex " << i+1 << "->";
        temp = list[i];
        while(temp != NULL) {
            cout << "v" << temp->vertex << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
}