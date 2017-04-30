//
// Created by steven on 30/04/17.
//

#ifndef REPOSITORY_EDMONDSKARP_H
#define REPOSITORY_EDMONDSKARP_H

bool bpm(bool** bpGraph, int u, bool seen[], int matchR[], int N, int M);
int maxBPM(bool** bpGraph, int N, int M);
int find_max_flow(bool** edm, int N, int M);

#endif //REPOSITORY_EDMONDSKARP_H
