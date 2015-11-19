/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GrafoDirigido.h"
#include "Arborescencia.h"

bool resuelveCaso()
{
    size_t V, A, v, w;
    std::cin >> V; // número de vértices
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    std::cin >> A; // número de aristas
    GrafoDirigido grafo(V);
    // leemos las aristas
    for (int i = 0; i < A; ++i)
    {
        std::cin >> v >> w;
        grafo.ponArista(v,w);
    }
    
    Arborescencia arbol = Arborescencia(grafo);
    
    if(arbol.grafoArborescente())
        std::cout << "SI " << arbol.raiz() << "\n";
    else
        std::cout << "NO\n";
    
    return true;
}
int main()
{
    while(resuelveCaso());
    return 0;
}