#include <iostream>
#include "MatrixGraph.h"
MatrixGraph::MatrixGraph(int nVertices): nVertices(nVertices), edges(nVertices, std::vector<bool>(nVertices,false)) {}
MatrixGraph::MatrixGraph(const IGraph *other) {
    nVertices = other->VerticesCount();
    for (int i = 0; i<other->VerticesCount();++i){
        std::vector<int> vertices;
        other->GetNextVertices(i ,vertices);
        for (int vertice : vertices) {
            AddEdge(i, vertice);
        }
    }
}
MatrixGraph::MatrixGraph(const MatrixGraph &other): nVertices(other.nVertices), edges(other.edges) {}

int MatrixGraph::VerticesCount() const {
    return nVertices;
}
void MatrixGraph::AddEdge(int from, int to) {
    edges[from][to] = true;
}
void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for(int i=0; i<nVertices; ++i)
        if (edges[vertex][i]){
            vertices.push_back(i);
        }
    }
void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for (int i=0; i<nVertices; ++i)
        if (edges[i][vertex])
            vertices.push_back(i);
}