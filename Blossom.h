#ifndef REPOSITORY_BLOSSOM_H
#define REPOSITORY_BLOSSOM_H

class Blossom{
private:
    const static int M = 2000;

    struct struct_edge {
        int v;
        struct_edge *n;
    };

    typedef struct_edge *edge;
    struct_edge pool[M * M * 2];
    edge top = pool, adj[M];
    int V, E, match[M], qh, qt, q[M], father[M], base[M];
    bool inq[M], inb[M], ed[M][M];

    int pairs = 0;
public:
    void add_edge(int u, int v);
    int LCA(int root, int u, int v);
    void mark_blossom(int lca, int u);
    void blossom_contraction(int s, int u, int v);
    int find_augmenting_path(int s);
    int augment_path(int s, int t);
    int edmonds();

    Blossom(int n2, double p);
    bool isPerfect();
    void printMatch();
};


#endif //REPOSITORY_BLOSSOM_H
