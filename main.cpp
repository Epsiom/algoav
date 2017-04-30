#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int n = 10;
    double p = 0.5;
    Graph* my_graph = new Graph(n,p, true);     //Bipartite
    //Graph* my_graph = new Graph(n,p, false);  //Not bipartite
    return 0;
}
