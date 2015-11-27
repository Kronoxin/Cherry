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
#include <limits>


void visit(const GrafoValorado<int> &G, int v,std::vector<bool> &marked,std::vector<Arista<int>> &edgeTo,std::vector<int> &distTo,IndexPQ<int> &pq){

    marked[v] = true;
    for (auto e : G.adj(v))
    {
        
        int w = e.otro(v);
        
        if (marked[w]) continue;
        if (e.valor() < distTo[w])
        {  // Edge e is new best connection from tree to w.
            edgeTo[w] = e;
            distTo[w] = e.valor();
            
            /*
             Hacemos el try-catch porque el "contains" se está comprobando al hacer el push
             * Si se hace push y salta la excepción es porque existe
             * Entonces, hacemos el update
             */

            try {
                pq.push(w, distTo[w]);
            } catch (std::invalid_argument) {
                pq.update(w, distTo[w]);
            }
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

    
    for (int i = 0; i < G.V(); i++){
        if(marked[i]==true)
            resultado += distTo[i];
        else
            return 0;
    }

    

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
    
    if(primMST(grafo)>0){
        std::cout<<primMST(grafo)<<"\n";
    }
    else
        std::cout<<"Imposible\n";

    return true;

}
int main()
{
    while(resuelveCaso());
    return 0;
}