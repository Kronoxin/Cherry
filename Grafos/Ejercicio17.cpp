//
//  Ejercicio17.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 25/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"
#include <vector>
#include <limits>
// E LOG V

bool contains(IndexPQ<int> pq, int elem)
{
    bool exist = false;
    IndexPQ<int> copia = pq;
    while (!copia.empty())
    {
        if((copia.top()).elem == elem)
            exist = true;
        
        copia.pop();
    }
    return exist;
}



void relax(AristaDirigida<int> e, std::vector<int> &distTo, std::vector<AristaDirigida<int>> &edgeTo, IndexPQ<int> &pq)
{
    int v = e.from(), w = e.to();
    if (distTo[w] > distTo[v] + e.valor())
    {
        distTo[w] = distTo[v] + e.valor();
        edgeTo[w] = e;
    }
    if (contains(pq,w)){
        pq.update(w, distTo[w]);
    }
    else
        pq.push(w, distTo[w]);
}


void dijkstraSP(GrafoDirigidoValorado<int> G, int s){

    std::vector<AristaDirigida<int>> edgeTo;
    std::vector<int> distTo(G.V());
    std::vector<bool> marked(G.V());
    IndexPQ<int> pq(G.V());


    for (int v = 0; v < G.V(); v++)
        distTo[v] = std::numeric_limits<int>::max();
    
    distTo[s] = 0.0;
    pq.update(s, 0.0);
    
    while (!pq.empty())
    {
        int v = (pq.top()).elem;
        pq.pop();
        for (auto e : G.adj(v))
            relax(e,distTo,edgeTo,pq);
    }

}


bool resuelveCaso()
{
    size_t V, A, v, w;
    int c;
    std::cin >> V; // número de vértices
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    std::cin >> A; // número de aristas
    GrafoDirigidoValorado<int> grafo(V);
    // leemos las aristas
    for (int i = 0; i < A; ++i)
    {
        std::cin >> v >> w >> c;
        AristaDirigida<int> arista = AristaDirigida<int> (v-1,w-1,c);
        grafo.ponArista(arista);
    }
    
    
    
    return true;
    
}
int main()
{
    while(resuelveCaso());
    return 0;
}