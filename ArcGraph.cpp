#include <iostream>
#include "ArcGraph.h"

ArcGraph::ArcGraph(int nVertices): nVertices(nVertices){}
ArcGraph::ArcGraph(const ArcGraph& other): edges(other.edges), nVertices(other.nVertices){}

ArcGraph::ArcGraph(const IGraph* other){
    for (int i = 0; i<other->VerticesCount();++i){
        std::vector<int> vertices;
        other->GetNextVertices(i ,vertices);
        for (int vertice : vertices) {
            AddEdge(i, vertice);
        }
    }
    nVertices = other->VerticesCount();
}

void ArcGraph::AddEdge(int from, int to){
    for (int i=0;i<edges.size();++i){
        if (edges[i].first == from && edges[i].second == to) return;
   }
   edges.push_back(std::pair<int, int>(from,to));
}
int ArcGraph::VerticesCount() const{
    return nVertices;
}
void ArcGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const{
    vertices.clear();
    for (int i=0;i<edges.size();++i){
        if (edges[i].first == vertex){
            vertices.push_back(edges[i].second);
        }
    }
}
void ArcGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const{
    vertices.clear();
    for (int i=0;i<edges.size();++i){
        if (edges[i].second == vertex)
            vertices.push_back(edges[i].first);
    }
}