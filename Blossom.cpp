#include "Blossom.h"
#include "Graph.h"
#include <bits/stdc++.h>


using namespace std;

void Blossom::add_edge(int u, int v) {
    top->v = v, top->n = adj[u], adj[u] = top++;
    top->v = u, top->n = adj[v], adj[v] = top++;
}

int Blossom::LCA(int root, int u, int v) {
    static bool inp[M];
    memset(inp, 0, sizeof(inp));
    while (1) {
        inp[u = base[u]] = true;
        if (u == root) break;
        u = father[match[u]];
    }
    while (1) {
        if (inp[v = base[v]]) return v;
        else v = father[match[v]];
    }
}

void Blossom::mark_blossom(int lca, int u) {
    while (base[u] != lca) {
        int v = match[u];
        inb[base[u]] = inb[base[v]] = true;
        u = father[v];
        if (base[u] != lca) father[u] = v;
    }
}

void Blossom::blossom_contraction(int s, int u, int v) {
    int lca = LCA(s, u, v);
    memset(inb, 0, sizeof(inb));
    mark_blossom(lca, u);
    mark_blossom(lca, v);
    if (base[u] != lca)
        father[u] = v;
    if (base[v] != lca)
        father[v] = u;
    for (int u = 0; u < V; u++)
        if (inb[base[u]]) {
            base[u] = lca;
            if (!inq[u])
                inq[q[++qt] = u] = true;
        }
}

int Blossom::find_augmenting_path(int s) {
    memset(inq, 0, sizeof(inq));
    memset(father, -1, sizeof(father));
    for (int i = 0; i < V; i++) base[i] = i;
    inq[q[qh = qt = 0] = s] = true;
    while (qh <= qt) {
        int u = q[qh++];
        for (edge e = adj[u]; e; e = e->n) {
            int v = e->v;
            if (base[u] != base[v] && match[u] != v)
                if ((v == s) || (match[v] != -1 && father[match[v]] != -1))
                    blossom_contraction(s, u, v);
                else if (father[v] == -1) {
                    father[v] = u;
                    if (match[v] == -1)
                        return v;
                    else if (!inq[match[v]])
                        inq[q[++qt] = match[v]] = true;
                }
        }
    }
    return -1;
}

int Blossom::augment_path(int s, int t) {
    int u = t, v, w;
    while (u != -1) {
        v = father[u];
        w = match[v];
        match[v] = u;
        match[u] = v;
        u = w;
    }
    return t != -1;
}

int Blossom::edmonds() {
    int matchc = 0;
    memset(match, -1, sizeof(match));
    for (int u = 0; u < V; u++)
        if (match[u] == -1)
            matchc += augment_path(u, find_augmenting_path(u));
    free(match);
    return matchc;
}

Blossom::Blossom(int n2,double p) {
    //cout << "#nodes" << n2;

    Graph *g = new Graph(n2, p, false);
    E = 0;
    V = g->node_list.size();

    //cout << "#nodes" << n2;

    for (int j = 0; j < g->node_list.size(); ++j) {
        Node *from = g->node_list[j];
        int u = from->get_name();
        vector<Node *> list = from->get_link_target();
        for (int i = 0; i < list.size(); ++i) {
            Node *to = list[i];
            E++;
            int v = to->get_name();
            if (!ed[u][v]) {
                add_edge(u, v);
                ed[u][v] = ed[v][u] = true;
            }
        }
    }
    //cout << "#edges" << E << "\n";
    //cout << "#edgesAtt" << n2 * (n2 - 1) << "\n";
    //cout << "#nodes" << n2 << "\n";

    /*int u,v;
    //cin>>V>>E;
    V=n;

    while(E--)
    {
        cin>>u>>v;
        if (!ed[u-1][v-1])
        {
            add_edge(u-1,v-1);
            ed[u-1][v-1]=ed[v-1][u-1]=true;
        }
    }
*/
    pairs = edmonds();

    delete(g);
}

bool Blossom::isPerfect(){
    //cout<<"pairs "<<pairs<<"  V "<<V<<"E "<<E<<endl;
    return pairs==(V/2);
}

void Blossom::printMatch(){
    for (int i = 0; i < V; i++)
        if (i < match[i])
            cout << i << " " << match[i] << endl;
}

int main(){

    int nbRun=1000;

    for (int i = 0; i <= 20; ++i) {
        double p=i/1000.;
        cout<<p<<"\n";
        int perfect = 0;
        for (int j = 0; j < nbRun; ++j) {
            Blossom* b = new Blossom(1000,p);
            if(b->isPerfect())
            perfect++;
            delete(b);
        }
        cout<<"Result for N=1000 and p="<<p<<" have "<<perfect<<" perfect matching on " << nbRun <<" runs"<<endl;
    }

}