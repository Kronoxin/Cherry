//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 10 - Árboles libres.
//
/*
 Resumen de solucion:
 Recorremos el grafo realizando una búsqueda en profundidad.
 Vamos contando el numero de nodos por los que pasamos para comprobar que el grafo sea conexo.
 Si algun nodo esta conectado con otro nodo que ya hayamos marcado distinto de su nodo padre el grafo
 es cícliclo.
 
 Coste O(numero de vertices + numero de aristas).
 */

#include "Grafo.h"
#include "ArbolLibre.h"

// Metodo que se encarga de la resolucion del caso.
// Hace uso de la clase ArbolLibre para saber si el grafo del caso es arbol libre o no.
// Coste O((numero de vertices + numero de aristas)
bool resuelveCaso() 
{
    size_t V, A, v, w;
    std::cin >> V; // número de vértices
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    std::cin >> A; // número de aristas
    Grafo grafo(V);
    
    // leemos las aristas
    // Coste O(numero de aristas)
    for (int i = 0; i < A; ++i) 
    {
        std::cin >> v >> w;
        grafo.ponArista(v,w);
    }
    
    //  Coste O(numero de vertices + numero de aristas).
    ArbolLibre arbol = ArbolLibre(grafo);
    
    if(arbol.grafoLibre())
        std::cout << "SI\n";
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