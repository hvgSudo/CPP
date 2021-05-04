#include<iostream>
#include<list>

using namespace std;

class Graph {
    private:
        int numberOfVertices;
        list<int> *adjacencyList;
    public:
        Graph(int numberOfVertices) {
            this->numberOfVertices = numberOfVertices;
            adjacencyList = new list<int>[numberOfVertices];
        }
        void addEdge(int source, int destination) {
            adjacencyList[source].push_front(destination);
        }
        void printGraph();
};

int main() { // Main method
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.printGraph();
    return 0;
}

void Graph::printGraph() {
    for (int i = 0; i < numberOfVertices; i++) {
        cout << "\nVertex " << i << ": ";
        for (auto x : adjacencyList[i])
            cout << "-> " << x;
        cout << "\n";
    }
}