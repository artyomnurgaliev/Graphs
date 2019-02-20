//
// Created by artum on 06.02.2019.
//

#ifndef UNTITLED26_MATRIXGRAPH_H
#define UNTITLED26_MATRIXGRAPH_H
#include <algorithm>
#include <vector>
#include "igraph.h"

class MatrixGraph: public IGraph{
public:
    MatrixGraph(int nVertices);
    MatrixGraph(const MatrixGraph &other);

    MatrixGraph(const IGraph* other);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

private:
    int nVertices;
    std::vector<std::vector<bool>> edges;
};


#endif //UNTITLED26_MATRIXGRAPH_H
