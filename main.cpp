#include "listgraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"
#include "MatrixGraph.h"
#include <vector>
#include <iostream>
#include <unordered_set>
void _DFS(const IGraph &graph, int v, std::vector<int> &mark, std::vector<int> &in, std::vector<int> &out) {
    if (mark[v] != 0)
        return;
    mark[v] = 1;
    in.push_back(v);
    std::vector<int> next;
    graph.GetNextVertices(v, next);
    for (int n : next)
        _DFS(graph, n, mark, in, out);
    out.push_back(v);
}


void DFS(const IGraph &graph, std::vector<int> &in, std::vector<int> &out) {
    in.clear();
    out.clear();
    std::vector<int> mark(graph.VerticesCount(), 0);
    _DFS(graph, 0, mark, in, out);
}
void Check(IGraph &sg){
    sg.AddEdge(0, 1);
    sg.AddEdge(0, 1);
    sg.AddEdge(0, 1);
    sg.AddEdge(0, 1);
    sg.AddEdge(0, 1);
    sg.AddEdge(0, 1);
    std::vector<int> in, out;
    DFS(sg, in, out);

    std::cout << "IN" << "\n";
    for (int v : in)
        std::cout << v << " ";

    std::cout << "OUT" << "\n";
    for (int v : out)
        std::cout << v << " ";
    std::cout<<"\n";
    std::cout<<"count: "<<sg.VerticesCount();
    std::cout<<"\n";
}
int main() {
    ArcGraph ar(4);
    Check(ar);
    ArcGraph* arcGraph = new ArcGraph(ar);
    Check(*arcGraph);
    ListGraph lg(4);
    Check(lg);
    ListGraph* listGraph = new ListGraph(lg);
    Check(*listGraph);
    SetGraph sg(4);
    Check(sg);
    SetGraph* setGraph = new SetGraph(sg);
    Check(*setGraph);
    MatrixGraph mg(4);
    Check(mg);
    MatrixGraph* matrixGraph = new MatrixGraph(mg);
    Check(*matrixGraph);
    return 0;
}