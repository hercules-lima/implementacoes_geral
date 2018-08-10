#include<iostream>
#include<list>
using namespace std;

class Grafo
{
    int V;

    list<int> *adja;

    void bpfu(int v, bool visitado[]);
public:
    Grafo(int V);

    void adicionaaresta(int v, int w);

    void bpf(int v);
};

Grafo::Grafo(int V)
{
    this->V = V;
    adja = new list<int>[V];
}

void Grafo::adicionaaresta(int v, int w)
{
    adja[v].push_back(w);
}

void Grafo::bpfu(int v, bool visitado[])
{
    visitado[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adja[v].begin(); i != adja[v].end(); ++i)
        if (!visitado[*i])
            bpfu(*i, visitado);
}

void Grafo::bpf(int v)
{

    bool *visitado = new bool[V];
    for (int i = 0; i < V; i++)
        visitado[i] = false;

    bpfu(v, visitado);
}

int main()
{
    Grafo g(4);
    g.adicionaaresta(0, 1);
    g.adicionaaresta(0, 2);
    g.adicionaaresta(1, 2);
    g.adicionaaresta(2, 0);
    g.adicionaaresta(2, 3);
    g.adicionaaresta(3, 3);

    cout << "Comecando do vertice 0 \n";
    g.bpf(0);

    return 0;
}
