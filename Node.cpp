
//
// Created by steven on 21/04/17.
//

#include "Node.h"
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Node::Node(int _name){
    name = _name;
    current_target_number = 0;
    std::vector<Node*> link_targets();
}

Node::~Node(){
    //TODO?
}

void Node::link(Node *target, double _p) {
    srand (time(NULL));
    double dice_roll_0_to_1 = ((double)rand() / (double)(RAND_MAX));    //Random double between 0 and 1

    if (dice_roll_0_to_1 < _p){
        //The chance has spoken : the link must be created
        current_target_number++;
        link_targets.resize(current_target_number);
        link_targets.push_back(target);
    }
}