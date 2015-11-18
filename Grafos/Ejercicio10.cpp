/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Grafo.h"
#include "ArbolLibre.h"


bool resuelveCaso() 
{
    size_t V, A, v, w;
    std::cin >> V; // número de vértices
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    std::cin >> A; // número de aristas
    Grafo grafo(V);
    // leemos las aristas
    for (int i = 0; i < A; ++i) 
    {
        std::cin >> v >> w;
        grafo.ponArista(v,w);
    }
    
    ArbolLibre arbol = ArbolLibre(grafo);
    
    if(arbol.grafoLibre())
        std::cout << "SI\n";
    else
        std::cout << "NO\n";
    
    return true;
}
int main()
{
    while(resuelveCaso());
    return 0;
}