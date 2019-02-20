//
// Created by artum on 06.02.2019.
//

#ifndef UNTITLED26_LISTGRAPH_H
#define UNTITLED26_LISTGRAPH_H

#include <algorithm>
#include <vector>
#include <list>
#include "igraph.h"

class ListGraph: public IGraph{
public:
    ListGraph(int nVertices);
    ListGraph(const ListGraph &other);

    ListGraph(const IGraph* other);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

private:
    std::vector<std::list<int>> next, prev;
};



#endif //UNTITLED26_LISTGRAPH_H
