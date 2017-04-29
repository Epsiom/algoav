//
// Created by steven on 21/04/17.
//

#include "Node.h"
#include "Graph.h"
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph(int _n, double _p, bool _isBipartie){
    n = _n;
    p = _p;
    for (int i = 0; i < n; ++i) {
        Node *new_node = new Node(i);
        node_list.push_back(new_node);
    }
    if (_isBipartie){
        link_nodes_bip(0);
    }
    else {
        link_nodes(0);
    }
}

//Recursively link every possible node pair with a probability of p
void Graph::link_nodes(int _start) {
    Node* to_link = node_list.at((unsigned long)_start);
    for (int i=_start+1; i<n; i++){
        to_link->link(node_list.at((unsigned long)i), p);
    }
    if (_start+1 < n){  //No need to do it for the nth node
        link_nodes(_start+1);
    }
}

void Graph::link_nodes_bip(int _start){
    Node* to_link = node_list.at((unsigned long)_start);
    int second_half = n/2;
    for (int i=second_half; i<n; i++){
        to_link->link(node_list.at((unsigned long)i), p);
    }
    if (_start+1 < second_half){
        link_nodes_bip(_start+1);
    }
}

Graph::~Graph() {
    //TODO?
}
