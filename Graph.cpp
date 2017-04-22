//
// Created by steven on 21/04/17.
//

#include "Graph.h"
#include <vector>

using namespace std;

Graph::Graph(int _n, double _p){
    n = _n;
    p = _p;
    node_list = vector<Node*>();
    for (int i=0; i<n; ++i){
        //TODO:le vecteur est-il bien initialise? Ensuite, mettre les noeuds dans le vecteur, puis appeller link_nodes
    }
}

void Graph::link_nodes(double _p) {
    //TODO
}

Graph::~Graph() {
    //TODO
}