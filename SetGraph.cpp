#include <iostream>
#include "SetGraph.h"
SetGraph::SetGraph(int nVertices): next(nVertices), prev(nVertices) {}
SetGraph::SetGraph(const SetGraph &other): next(other.next), prev(other.prev){}

SetGraph::SetGraph(const IGraph* other): next(other->VerticesCount()), prev(other->VerticesCount()){
    for (int i = 0; i<other->VerticesCount();++i){
        std::vector<int> vertices;
        other->GetNextVertices(i ,vertices);
        for (int vertice : vertices) {
            AddEdge(i, vertice);
        }
    }
}


void SetGraph::AddEdge(int from, int to){
    next[from].insert(to);
    prev[to].insert(from);
}
int SetGraph::VerticesCount() const{
    return next.size();
}
void SetGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const{
    vertices.clear();
    for(int i : next[vertex]) {
        vertices.push_back(i);
    }
}
void SetGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const{
    vertices.clear();
    for(int i : prev[vertex])
        vertices.push_back(i);
}