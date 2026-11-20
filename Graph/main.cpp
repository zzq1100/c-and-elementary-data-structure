#include "graph.hpp"

#include <iostream>
using namespace std;

int main()
{
    const char vertices[] = {'A', 'B', 'C'};
    matrix::Graph<char, int> g(vertices, 3);
    g.AddEdge('A', 'B', 5);
    g.AddEdge('B', 'C', 10);
    g.AddEdge('C', 'A', 15);

    int indexA = g.GetVertexIndex('A');
    int indexB = g.GetVertexIndex('B');
    int indexC = g.GetVertexIndex('C');
    int missingIndex = g.GetVertexIndex('D'); // Vertex 'D' does not exist

    cout << "Index of vertex A: " << indexA << endl; // Should print 0
    cout << "Index of vertex B: " << indexB << endl; // Should print 1
    cout << "Index of vertex C: " << indexC << endl; // Should print 2
    cout << "Index of vertex D: " << missingIndex << endl; // Should print -1
}