#include<iostream>

using namespace std;

class Node {
    private:
        int vertex;
        Node* next;
    public:
        Node(int d) {
            vertex = d;
            next = NULL;
        }
        friend class Graph;
};

class Graph {
    private:
        int numberOfVertices;
        Node **adjacencyList;
        int *visited;
    public:
        Graph(int vertices) {
            numberOfVertices = vertices;
            for (int i = 0; i < vertices; ++i) {
                adjacencyList[i] = NULL;
                visited[i] = 0;
            }
        }
        void addEdge(int, int);
        void DFS(int);
        void printGraph();
};

void initCode() {
    #ifndef A
 // For getting input from input.txt file
    freopen("D:/Codes/CPP/inputCPP.txt", "r", stdin);
  
    // Printing the Output to output.txt file
    freopen("D:/Codes/CPP/outputCPP.txt", "w", stdout);
  
    #endif
}

int main() { // Main method
    initCode();
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "\nThe Graph is ";
    g.printGraph();
    cout << "\nDepth First Search is\n";
    g.DFS(1);
    return 0;
}

void Graph::printGraph() {
    for (int i = 0; i < numberOfVertices; ++i) {
        Node *temp = adjacencyList[i];
        cout << "\n Vertex " << i;
        while (temp) {
            cout << temp->vertex << " -> ";
            temp = temp->next;
        } 
        cout << "\n";
    }
}

void Graph::addEdge(int source, int destination) {
    // Add edge from source to destination
    Node* newNode = new Node(destination);
    newNode->next = adjacencyList[source];
    adjacencyList[source] = newNode;

    // Add edge from destination to source
    newNode = new Node(source);
    newNode->next = adjacencyList[destination];
    adjacencyList[destination] = newNode;
}

void Graph::DFS(int vertex) {
    Node *List = adjacencyList[vertex];
    Node *temp = List;

    visited[vertex] = 1;
    cout << vertex << " ";
    while (temp) {
        int connectedVertex = temp->vertex;
        if (visited[connectedVertex] == 0)
            DFS(connectedVertex);
        temp = temp->next;
    }
}