#include <iostream>
#include "ListGraph.h"

ListGraph::ListGraph(int nVertices): next(nVertices), prev(nVertices) {}
ListGraph::ListGraph(const ListGraph &other): next(other.next), prev(other.prev){}

ListGraph::ListGraph(const IGraph* other){
    for (int i = 0; i<other->VerticesCount();++i){
        std::vector<int> vertices;
        other->GetNextVertices(i ,vertices);
        for (int vertice : vertices) {
            AddEdge(i, vertice);
        }
    }
}


void ListGraph::AddEdge(int from, int to){
    if (std::find(next[from].begin(), next[from].end(),to) == next[from].end()) {
        next[from].push_back(to);
        prev[to].push_back(from);
    }
}
int ListGraph::VerticesCount() const{
    return next.size();
}
void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const{
    vertices.clear();
    //for (std::list<int>::const_iterator it  = next[vertex].begin(); it != next[vertex].end();++it)
    //   vertices.push_back(*it);
    // for (int v: next[vertex]){
    //     vertices.push_back(v);
    // }
    // vertices.assign(next[vertex].begin(), next[vertex].end());
    vertices = {next[vertex].begin(), next[vertex].end()};

}
void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const{
    vertices.clear();
    vertices = {prev[vertex].begin(), prev[vertex].end()};
}