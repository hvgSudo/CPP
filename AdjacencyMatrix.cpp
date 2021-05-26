#include<iostream>

using namespace std;

void initCode() {
    #ifndef A
    // For getting input from input.txt file
    freopen("D:/Codes/CPP/inputCPP.txt", "r", stdin);
  
    // Printing the Output to output.txt file
    freopen("D:/Codes/CPP/outputCPP.txt", "w", stdout);
  
    #endif
}

class Graph {
    private:
        bool **adjacencyMatrix;
        int numberOfVertices;
    public:
        Graph(int numberOfVertices) {
            this->numberOfVertices = numberOfVertices;
            adjacencyMatrix = new bool*[numberOfVertices];
            for (int i = 0; i < numberOfVertices; i++) {
                adjacencyMatrix[i] = new bool[numberOfVertices];
                for (int j = 0; i < numberOfVertices; j++) 
                    adjacencyMatrix[i][j] = 0;
            }
        }
        
        void addEdges(int i, int j) {
            adjacencyMatrix[i][j] = true;
            adjacencyMatrix[j][i] = true;
        }

        void removeEdges(int i, int j) {
            adjacencyMatrix[i][j] = false;
            adjacencyMatrix[j][i] = false;
        }

        void printGraph() {
            for (int i = 0; i < numberOfVertices; i++) {
                cout << i << " : ";
                for (int j = 0; j < numberOfVertices; j++)
                    cout << adjacencyMatrix[i][j] << " ";
                cout << endl;
            }
        }

        ~Graph() {
            for (int i = 0; i < numberOfVertices; i++) {
                delete[] adjacencyMatrix[i];
            delete[] adjacencyMatrix;
            }
        }
};

int main() { // Main Method
    initCode();
    Graph g(4);

    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(1, 2);
    g.addEdges(2, 0);
    g.addEdges(2, 3);

    g.printGraph();
    return 0;
}