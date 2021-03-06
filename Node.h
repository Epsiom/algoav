//
// Created by steven on 21/04/17.
//

#include <vector>

#ifndef PROJET_NODE_H
#define PROJET_NODE_H

class Node {
private:
    int name;
    int current_target_number;
    std::vector<Node*> link_targets;
public:
    Node(int _name);
    ~Node();
    void link(Node* target, double _p);
    void link(Node* target);
    int get_name();
    int get_current_target_number();
    std::vector<Node*> get_link_target();
};

#endif //PROJET_NODE_H
