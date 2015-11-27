//
//  Ejercicio17.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 25/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//
/*
#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"
// E LOG V


void relax(AristaDirigida<int> e,std::vector<int> &distTo,std::vector<AristaDirigida<int>> &edgeTo,IndexPQ<int> &pq)
{
    size_t v = e.from();
    size_t w = e.to();
    
    if (distTo[w] > distTo[v] + e.valor())
    {
        distTo[w] = distTo[v] + e.valor();
        edgeTo[w] = e;
        
        try
        {
            pq.push(w, distTo[w]);
        } catch (std::invalid_argument)
        {
            pq.update(w, distTo[w]);
        }
    }
    
}


std::vector<int> &dijkstraSP(GrafoDirigidoValorado<int> G, int s, std::vector<AristaDirigida<int>> &edgeTo, std::vector<int> &distTo){

    std::vector<bool> marked(G.V());
    IndexPQ<int> pq(G.V());


    for (int v = 0; v < G.V(); v++)
        distTo[v] = std::numeric_limits<int>::max();
    
    distTo[s] = 0;
    pq.push(s, 0);
    
    while (!pq.empty())
    {
        int v = (pq.top()).elem;
        pq.pop();
        for (auto e : G.adj(v))
            relax(e,distTo,edgeTo,pq);
    }
    
    return distTo;

}



bool resuelveCaso()
{
    size_t V, A, v, w;
    int c, s , nPaquetes;
    std::cin >> V; // número de vértices
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    std::cin >> A; // número de aristas
    GrafoDirigidoValorado<int> grafo(V);
    
    //como no tengo constructor vacío, lo inicializo y relleno aquí, y se lo paso a dijkstra
    std::vector<AristaDirigida<int>> edgeTo;
    
    // leemos las aristas
    for (int i = 0; i < A; ++i)
    {
        std::cin >> v >> w >> c;
        AristaDirigida<int> arista = AristaDirigida<int>(v-1, w-1, c);
        grafo.ponArista(arista);
        edgeTo.push_back(arista);
    }
    
    //leemos el inicio/fin
    std::cin >> s;
    std::vector<int> distTo(grafo.V());
    std::vector<int> ida = dijkstraSP(grafo, s-1, edgeTo, distTo);
    std::vector<int> vuelta = dijkstraSP(grafo.reverse(), s-1, edgeTo,distTo);
    
    //el numero de paquetes.
    std::cin >> nPaquetes;
    int esfuerzoMinimo = 0;
    int des;
    bool realizable = true;
    
    for (int i = 0; i < nPaquetes; ++i)
    {
        std::cin >> des;
        if (ida[des-1] != std::numeric_limits<int>::max() && vuelta[des-1] != std::numeric_limits<int>::max())
            esfuerzoMinimo += ida[des-1] + vuelta[des-1];
        else
            realizable = false;
    }
    
    if (realizable)
        std::cout << esfuerzoMinimo << "\n";
    else
        std::cout << "Imposible\n";
    
    
    return true;
    
}
int main()
{
    while(resuelveCaso());
    return 0;
}*/