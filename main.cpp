#include <iostream>
#include "Graph.h"
#include "EdmondsKarp.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int n = 10;
    double p = 0.5;
    Graph* my_graph = new Graph(n,p, true);     //Bipartite
    //Graph* my_graph = new Graph(n,p, false);  //Not bipartite
    bool** edm = my_graph->generate_edmonds_matrix();
    find_max_flow(edm, n/2, n/2);
    return 0;
}
