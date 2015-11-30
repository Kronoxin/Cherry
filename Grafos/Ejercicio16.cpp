//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 16 - Pavimentar Barro City.
//
/*
 Resumen de solucion:
 Implementamos el algoritmo voraz de Prim.
 El algoritmo de Prim realiza un arbol recubridor de coste total minimo.
 Tras establecer el peso de las aristas con menor coste total para el arbol lo recorremos sumando los costes para cada uno de los vertices.
 El resultado es el coste minimo necesario para conectar todos los vertices. 
 
 Coste O(numero de aristas*log(numero de vertices)).
 */

#include "GrafoValorado.h"
#include "IndexPQ.h"
#include <vector>
#include <limits>

// Metodo que recorre las adyacentes de un nodo y comprueba si se ha llegado por un camino mejor al nodo.
// En ese caso selecciona la arista actual y la mete en la cola, o la actualiza si ya existe.

void visitar(const GrafoValorado<int> &G, int v,std::vector<bool> &marked,std::vector<int> &distancias,IndexPQ<int> &pq,std::vector<Arista<int>> &aristas){

    marked[v] = true;
    // Recorremos las aristas adyacentes al vertice. Coste O(numero de aristas).
    for (auto e : G.adj(v))
    {
        int destino = e.otro(v); // Cogemos el destino.
        
        if (!marked[destino]) // Si no esta ya marcado el destino.
        {
            if (e.valor() < distancias[destino]) // Comprobamos si esta arista es mejor
            {
                aristas[destino] = e; // Como es mejor la seleccionamos.
                distancias[destino] = e.valor(); // Ponemos el peso de la arista en el vector de distancias.

                // Debido a que en IndexPQ no hay un metodo que compruebe si ya existe el elemento, usamos la excepcion
                // que lanza el metodo push en caso de que exista. Si salta la excepcion invalid_argument es porque ya existe el elemento
                // y lo actualizamos.
                try 
                {
                    pq.push(destino, distancias[destino]);
                } 
                catch (std::invalid_argument) 
                {
                    pq.update(destino, distancias[destino]);
                }
            }
        }
    }
}

// Metodo que implementa el algoritmo de Prim.
// Obtenemos el arbol recubridor de coste minimo y devolvemos la suma de los costes de las aristas de ese arbol.
// Coste O(numero de aristas*log(numero de vertices)).

int primVoraz(GrafoValorado<int> G)
{
    
    std::vector<Arista<int>> aristas(G.V());
    std::vector<int> distancias(G.V());
    std::vector<bool> marked(G.V());
    IndexPQ<int> pq(G.V()); // Declaramos e inicializamos un monticulo clave-valor.
    
    for (int v = 0; v < G.V(); v++)
        distancias[v] = std::numeric_limits<int>::max();
    
    distancias[0] = 0;              // Inicializamos la distancia al vertice 0 con 0.
    pq.push(0, 0);              // Inicializamos el monticulo.
    
    while (!pq.empty()) // Mientras el monticulo no este vacio.
    {
        int a = (pq.top()).elem; // Cogemos el menor elemento.
        pq.pop(); // Sacamos el elemento del monticulo.
        visitar(G,a,marked,distancias,pq,aristas);       // Visitamos ese vertice.
    }
    
    
    int resultado = 0;
    // Recorremos el vector con las distancias de vertices. Coste O(numero de vertices).
    for (int i = 0; i < G.V(); i++)
    {
        if(marked[i]==true)
            resultado += distancias[i]; // Sumamos las distancias para obtener el coste total.
        else
            return 0;               // Si hay algun nodo no visitado devolvemos 0;
    }

    return resultado;
    
}

// Metodo que se encarga de la resolucion del caso.
// Recoge la entrada del usuario, inicializa las variables y llama a la funcion que devuelve el coste del arbol recubridor de coste minimo.
// Coste O(numero de aristas*log(numero de vertices)).

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
    
    if(primVoraz(grafo)>0){
        std::cout<<primVoraz(grafo)<<"\n";
    }
    else
        std::cout<<"Imposible\n";

    return true;

}

// Metodo principal, contiene un bucle que llama a la funcion resuelveCaso.
// Esta devuelve true mientras haya casos por resolver.
// Coste O(numero de aristas*log(numero de vertices)).

int main()
{
    while(resuelveCaso());
    return 0;
}