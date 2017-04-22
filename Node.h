//
// Created by steven on 21/04/17.
//

#ifndef PROJET_NODE_H
#define PROJET_NODE_H

class Node {
private:
    vector<Node*> link_targets;
public:
    Node();
    ~Node();
    void link(Node* target);
};

#endif //PROJET_NODE_H
