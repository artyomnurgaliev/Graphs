#ifndef UNTITLED26_ARCGRAPH_H
#define UNTITLED26_ARCGRAPH_H

#include <vector>
#include "igraph.h"

class ArcGraph: public IGraph{
public:
    ArcGraph(int nVertices);
    ArcGraph(const ArcGraph &other);

    ArcGraph(const IGraph* other);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

private:
    int nVertices;
    std::vector<std::pair<int, int>> edges;
};


#endif //UNTITLED26_ARCGRAPH_H
