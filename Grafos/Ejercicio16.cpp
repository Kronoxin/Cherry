//
//  Ejercicio16.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 25/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#include "GrafoValorado.h"
#include "IndexPQ.h"
#include <vector>
/*
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

void visit(const GrafoValorado<int> &G, int v,std::vector<bool> &marked,std::vector<Arista<int>> &edgeTo,std::vector<int> &distTo,IndexPQ<int> &pq)
{  // Add v to tree; update data structures.
    marked[v] = true;
    for (auto e : G.adj(v))
    {
        
        int w = e.otro(v);
        
        if (marked[w]) continue;
        if (e.valor() < distTo[w])
        {  // Edge e is new best connection from tree to w.
            edgeTo[w] = e;
            distTo[w] = e.valor();
            
            if (contains(pq,w))
                pq.update(w, distTo[w]);
            else
                pq.push(w, distTo[w]);
        }
    }
}

int primMST(GrafoValorado<int> G)
{
    std::vector<Arista<int>> edgeTo(G.V());
    std::vector<int> distTo(G.V());
    std::vector<bool> marked(G.V());
    IndexPQ<int> pq(G.V());
    
    for (int v = 0; v < G.V(); v++)
        distTo[v] = std::numeric_limits<int>::max();
    
    distTo[0] = 0;
    pq.push(0, 0);              // Initialize pq with 0, weight 0.
    
    while (!pq.empty())
    {
        int a = (pq.top()).elem;
        pq.pop();
        visit(G, a,marked,edgeTo,distTo,pq);       // Add closest vertex to tree.
    }
    int resultado = 0;
    for (int i = 0; i < G.V(); i++)
        resultado += distTo[i];
    

    return resultado;
    
}





bool resuelveCaso()
{
    size_t V, A, v, w;
    int c;
    std::cin >> V; // número de vértices
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    std::cin >> A; // número de aristas
    GrafoValorado<int> grafo(V);
    // leemos las aristas
    for (int i = 0; i < A; ++i)
    {
        std::cin >> v >> w >> c;
        Arista<int>arista = Arista<int>(v-1,w-1,c);
        grafo.ponArista(arista);
    }
    
    std::cout << primMST(grafo);

    return true;

}
int main()
{
    while(resuelveCaso());
    return 0;
}*/