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
    std::vector<Node*> node_list;
    void link_nodes(int _start);
public:
    Graph(int _n, double _p);
    ~Graph();
};

#endif //PROJET_GRAPH_H
