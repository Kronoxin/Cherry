//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 11 - Grafo Bipartito.
//
/*
 Resumen de solucion:
 Recorremos el grafo realizando una búsqueda en profundidad.
 Segun pasamos por cada nodo le ponemos un color distinto al color del nodo del que venimos.
 Si nos encontramos un nodo que ya esta coloreado y es igual al color de nuestro nodo actual, el grafo no es bipartito.
 
 Coste O(numero de vertices + numero de aristas).
 */

#include "ArbolBipartito.h"
#include "Grafo.h"

// Metodo que se encarga de la resolucion del caso.
// Hace uso de la clase ArbolBipartito para saber si el grafo es bipartito o no.
// Coste O((numero de vertices + numero de aristas).

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
    
    ArbolBipartito arbol = ArbolBipartito(grafo);
    
    if(arbol.grafoBipartito())
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