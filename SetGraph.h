//
// Created by artum on 06.02.2019.
//

#ifndef UNTITLED26_SETGRAPH_H
#define UNTITLED26_SETGRAPH_H
#include <vector>
#include <unordered_set>
#include "igraph.h"

class SetGraph: public IGraph{
public:
    SetGraph(int nVertices);
    SetGraph(const SetGraph &other);

    SetGraph(const IGraph* other);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

private:
    std::vector<std::unordered_set<int>> next, prev;
};


#endif //UNTITLED26_SETGRAPH_H
