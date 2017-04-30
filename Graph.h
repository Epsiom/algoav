//
// Created by steven on 21/04/17.
//
#include "Node.h"
#include <vector>

#ifndef PROJET_GRAPH_H
#define PROJET_GRAPH_H

class Graph {
private:
    int n;
    double p;
    void link_nodes(int _start);
    void link_nodes_bip(int _start);
public:
    std::vector<Node*> node_list;
    Graph(int _n, double _p, bool _isBipartite);
    bool** generate_edmonds_matrix();
    ~Graph();
};

#endif //PROJET_GRAPH_H
