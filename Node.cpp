
//
// Created by steven on 21/04/17.
//

#include "Node.h"
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include <iostream>

Node::Node(int _name){
    name = _name;
    current_target_number = 0;
    std::vector<Node*> link_targets;
}

Node::~Node(){
    //TODO?
}

//Link this node with another with a probability of p (Register for both nodes by using the other link function below)
void Node::link(Node *target, double _p) {
    double dice_roll_0_to_1 = (double)rand() / (RAND_MAX + 1.0);    //Random double between 0 and 1

    if (dice_roll_0_to_1 < _p){
        current_target_number++;
        link_targets.push_back(target);
        target->link(this);
    }
}

//Register a link initiated by another node for this node only
void Node::link(Node *target){
    current_target_number++;
    link_targets.push_back(target);
}