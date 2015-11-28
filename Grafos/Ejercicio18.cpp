//
//  Ejercicio18.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 25/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//
/*
#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"
#include <limits>


void relax(AristaDirigida<int> e,std::vector<int> &distTo,std::vector<AristaDirigida<int>> &edgeTo,IndexPQ<int> &pq,std::vector<int> &pisados,int d)
{
    size_t v = e.from();
    size_t w = e.to();
    if (distTo[w] > distTo[v] + e.valor())
    {
        distTo[w] = distTo[v] + e.valor();
        edgeTo[w] = e;
        pisados[w] = pisados[v];
 
        try
        {
            pq.push(w, distTo[w]);
        }catch (std::invalid_argument)
        {
            pq.update(w, distTo[w]);
        }
        
    }
    else if (distTo[w] == distTo[v] + e.valor())
    {    
        pisados[w] += pisados[v];    
    }
    
}


int dijkstraSP(GrafoDirigidoValorado<int> G, int s,std::vector<AristaDirigida<int>> &edgeTo)
{

    std::vector<int> pisados(G.V());;
    std::vector<int> distTo(G.V());
    pisados[0] = 1;
    //std::vector<AristaDirigida<int>> edgeToFinal;
    
    IndexPQ<int> pq(G.V());
    
    for (int v = 0; v < G.V(); v++)
        distTo[v] = std::numeric_limits<int>::max();
    
    distTo[s] = 0.0;
    pq.push(s, 0.0);
    
    while (!pq.empty())
    {
        int v = (pq.top()).elem;
        pq.pop();
        for (auto e : G.adj(v))
            relax(e,distTo,edgeTo,pq,pisados,G.V()-1);
    }
    
    int nCaminos = 1;

    //Si el grafo no es conexo, no puede llegar al destino.
    if(distTo[distTo.size()-1]== std::numeric_limits<int>::max()){
        nCaminos = 0;
    }
    
    
    return pisados[G.V()-1];
    
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
    
    std::vector<AristaDirigida<int>> edgeTo;
    // leemos las aristas
    for (int i = 0; i < A; ++i)
    {
        std::cin >> v >> w >> c;
        AristaDirigida<int>aristaUno = AristaDirigida<int>(v-1,w-1,c);
        AristaDirigida<int>aristaDos = AristaDirigida<int>(w-1,v-1,c);
        grafo.ponArista(aristaUno);
        grafo.ponArista(aristaDos);
    }
    for (int a = 0; a < grafo.V(); a++)
    {
        AristaDirigida<int> b (0,0,0);
        edgeTo.push_back(b);
    }
    
    int numeroCaminos = 0;
    numeroCaminos = dijkstraSP(grafo, 0,edgeTo);
    
    std::cout << numeroCaminos << "\n";
    
    return true;
    
}

int main()
{
    while(resuelveCaso());
    return 0;
}
 */
