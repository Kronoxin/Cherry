//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 12 - Arborescencias.
//
/*
 Resumen de solucion:
 Para encontrar la raiz damos la vuelta a las aristas del grafo, de forma que si existe una raiz esta sera alcanzable desde
 cualquier nodo y su numero de adyacentes en el grafo inverso sera 0.
 Una vez encontrada la raiz hacemos dfs para comprobar que sea conexo y que exista un solo camino para llegar a cada uno de los nodos.
 Es arborescencia si tiene una raiz y desde ella podemos acceder a todos los nodos de una unica forma.
 
 Coste O(numero de vertices + numero de aristas).
 */

#include "GrafoDirigido.h"
#include "Arborescencia.h"

// Metodo que se encarga de la resolucion del caso.
// Hace uso de la clase Arborescencia para saber si el grafo es arborescente o no.
// Coste O((numero de vertices + numero de aristas).

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
// Metodo principal, contiene un bucle que llama a la funcion resuelveCaso.
// Esta devuelve true mientras haya casos por resolver.
// Coste O(numero de vertices + numero de aristas).

int main()
{
    while(resuelveCaso());
    return 0;
}