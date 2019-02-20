#ifndef UNTITLED26_IGRAPH_H
#define UNTITLED26_IGRAPH_H

#include <vector>

struct IGraph{
    IGraph(){}
    virtual ~IGraph(){}

    virtual void AddEdge(int from, int to) = 0;
    //virtual - для переопределения
    //=0 - нет определения
    //const - не меняет объект для которого вызвана
    virtual int VerticesCount() const = 0;
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0;
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0;
};

#endif //UNTITLED26_IGRAPH_H
