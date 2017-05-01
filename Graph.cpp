//
// Created by steven on 21/04/17.
//

#include "Node.h"
#include "Graph.h"
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph(int _n, double _p, bool _isBipartite){
    n = _n;
    p = _p;
    for (int i = 0; i < n; ++i) {
        Node *new_node = new Node(i);
        node_list.push_back(new_node);
    }
    if (_isBipartite){
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

//Only use when the current graph is bipartite
//Generate an edmond matrix of the current graph
bool** Graph::generate_edmonds_matrix(){
    bool** edm = 0;
    int size = n/2;
    edm = new bool*[size];

    //Initial filling of the array
    for (int i=0; i<size; i++)
    {
        edm[i] = new bool[size];
        for (int j=0; j<size; j++)
        {
            edm[i][j] = 0;
        }
    }

    for (int i=0; i<n/2; i++){
        Node* studied = node_list.at((unsigned long)i);
        for (int j=0; j<studied->get_current_target_number(); j++){
            //Find the name of the target of each link of this node, and assigns 1 in the matching column
            //then fills the same value at the symmetric position in the array
            //Warning: the name of each nodes is in [0;n] as in the array, the rows and columns are both [0;n/2]
            //and thus, we have to substract n/2 to the value of the columns labels
            int target_name = (studied->get_link_target().at((unsigned long) j)->get_name()) - n/2;
            edm[i][target_name] = 1;
        }
    }
    return edm;
}

Graph::~Graph() {
    //TODO?
    for (int i = 0; i < node_list.size(); ++i) {
        delete(node_list[i]);
    }
}
