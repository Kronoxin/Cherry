/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <time.h>

#include "Grafo.h"
#include "ArbolLibre.h"

void dfsAux(Grafo const& G, size_t v,bool marked[],size_t &count) 
{
    ++count;
    marked[v] = true;
    for (auto w : G.adj(v)) {
        if (!marked[w]) {
            dfsAux(G,w,marked,count);
        }
    }
}

size_t dfs(Grafo const& G, size_t v)
{
    bool *marked = new bool[G.V()];
    size_t count = 0;
    dfsAux(G,v,marked,count);
    
    return count;
    
}

bool resuelveCaso() {
    int V, A, v, w;
    std::cin >> V; // número de vértices
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    std::cin >> A; // número de aristas
    Grafo grafo(V);
    // leemos las aristas
    for (int i = 0; i < A; ++i) {
        std::cin >> v >> w;
        grafo.ponArista(v,w);
    }
    
    ArbolLibre arbol = ArbolLibre(grafo);
    if (arbol.grafoLibre())
        std::cout << "SI\n";
    else
        std::cout << "NO\n";
}
int main()
{
    while(resuelveCaso())
    {
        
    }
    return 0;
}