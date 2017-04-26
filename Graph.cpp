//
// Created by steven on 21/04/17.
//

#include "Graph.h"
#include "Node.h"
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph(int _n, double _p){
    n = _n;
    p = _p;
    vector<Node*> node_list((unsigned long)n);
    for (int i=0; i<n; ++i){
        Node* new_node = new Node(i);
        node_list.push_back(new_node);
    }
    link_nodes(0);
}

//Recursively link every possible node pair with a probability of p
void Graph::link_nodes(int _start) {
    Node* to_link = node_list.at((unsigned long)_start);
    for (int i=_start+1; i<n; i++){
        to_link->link(node_list.at((unsigned long)i), p);
    }
}

Graph::~Graph() {
    //TODO?
}