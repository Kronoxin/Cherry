//
//  Ejercicio18.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 25/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"


void relax(AristaDirigida<int> e,std::vector<int> &distTo,std::vector<AristaDirigida<int>> &edgeTo,IndexPQ<int> &pq,int d,int &nCaminos)
{
    int v = e.from(), w = e.to();
    if (distTo[w] > distTo[v] + e.valor())
    {
        distTo[w] = distTo[v] + e.valor();
        edgeTo[w] = e;
        if (w==d)
            nCaminos++;
        
        try
        {
            pq.push(w, distTo[w]);
        }catch (std::invalid_argument)
        {
            pq.update(w, distTo[w]);
        }

    }
    else if (distTo[w] == distTo[v] + e.valor() && w==d)
        nCaminos++;
    
    
}


int dijkstraSP(GrafoDirigidoValorado<int> G, int s,std::vector<AristaDirigida<int>> &edgeTo, int des){
    
    int nCaminos=0;
    std::vector<int> distTo(G.V());
    std::vector<bool> marked(G.V());
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
            relax(e,distTo,edgeTo,pq,des,nCaminos);
    }
    
    return nCaminos;
    
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
        edgeTo.push_back(aristaUno);
        edgeTo.push_back(aristaDos);
    }
    
    int numeroCaminos = 0;
    numeroCaminos = dijkstraSP(grafo, 0,edgeTo,grafo.V()-1);
    
    if (numeroCaminos > 0)
        std::cout << numeroCaminos << "\n";
    else
        std::cout << "0\n";
    return true;
    
}
int main()
{
    while(resuelveCaso());
    return 0;
}
