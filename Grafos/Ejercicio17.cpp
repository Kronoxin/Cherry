//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 17 - Repartiendo paquetes.
//
/*
 Resumen de solucion:
 Implementamos el algoritmo de dijkstra.
 Necesitamos llegar de un punto de origen a varios destinos. Los caminos de vuelta pueden ser distintos a los de ida.
 Realizamos dijstra desde el punto de origen una vez y guardamos los resultados de las distancias minimas al resto de vertices.
 El problema es calcular los caminos de vuelta, por tanto invertimos las aristas de forma que los caminos de vuelta ahora son caminos
 de ida, lo que nos permite hacer dijkstra otra vez desde el origen y saber cuanto nos cuesta volver desde cada uno de los destinos.
 La suma de las distancias a los destinos de ida y las distancias de vuelta es el coste total minimo.
 
 Coste O(numero de aristas*log(numero de vertices)).
 */

#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"
#include <limits>

// Metodo que recorre las aristas adyacentes y selecciona aquellas que tenga un mejor coste.
void relajar(AristaDirigida<int> aristaActual,std::vector<int> &distTo,std::vector<AristaDirigida<int>> &aristas,IndexPQ<int> &pq)
{
    size_t origen = aristaActual.from();
    size_t destino = aristaActual.to();
    
    // Si la distancia que tiene nuestro destino mayor que lo que costaria recorrerlo a traves de nuestra arista.
    if (distTo[destino] > distTo[origen] + aristaActual.valor())
    {
        distTo[destino] = distTo[origen] + aristaActual.valor(); // Actualizamos la distancia.
        aristas[destino] = aristaActual; // Actualizamos la arista seleccionada.
        
        // Debido a que en IndexPQ no hay un metodo que compruebe si ya existe el elemento, usamos la excepcion
        // que lanza el metodo push en caso de que exista. Si salta la excepcion invalid_argument es porque ya existe el elemento
        // y lo actualizamos.
        try
        {
            pq.push(destino, distTo[destino]);
        } 
        catch (std::invalid_argument)
        {
            pq.update(destino, distTo[destino]);
        }
    }
    
}
// Metodo que implementa el algoritmo de dijkstra.
// Inicializamos todos los nodos con distancia maxima excepto el nodo origen.
// Vamos recorriendo las aristas y comprobando si la distancia por el camino actual es menor que la que habia antes y lo actualizamos.
// Devuelve el vector de distancias.
// Coste O(numero de aristas*log(numero de vertices)).

std::vector<int> &dijkstra(GrafoDirigidoValorado<int> G, int s, std::vector<AristaDirigida<int>> &aristas, std::vector<int> &distTo)
{

    std::vector<bool> marked(G.V());
    IndexPQ<int> pq(G.V());

    // Hacemos la inicializacion al maximo numero representable por un entero, debido a que los enteros no tienen una representacion de infinito.
    for (int v = 0; v < G.V(); v++)
        distTo[v] = std::numeric_limits<int>::max();
    
    distTo[s] = 0; // Inicializamos el origen con distancia 0.
    pq.push(s, 0); // Añadimos el vertice al monticulo.
    
    while (!pq.empty()) // Mientras queden vertices.
    {
        int v = (pq.top()).elem; // Cogemos el menor elemento.
        pq.pop(); // Lo sacamos del monticulo.
        for (auto e : G.adj(v)) // recorremos los vertices adyacentes.
            relajar(e,distTo,aristas,pq); // Llamamos a relajar para actualizar las distancias. Coste O(log(numero de vertices)).
    }
    
    return distTo;

}

// Metodo que se encarga de la resolucion del caso.
// Recoge la entrada del usuario e inicializa las variables.
// Hace una llamada a la implementacion de dijstra, da la vuelta a las aristas del grafo y vuelve a hacer la llamada con ese grafo.
// Coste O(numero de aristas*log(numero de vertices)).

bool resuelveCaso()
{
    size_t V, A, v, w;
    int c, s , nPaquetes;
    std::cin >> V; // número de vértices
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    std::cin >> A; // número de aristas
    GrafoDirigidoValorado<int> grafo(V);
    
    
    std::vector<AristaDirigida<int>> aristas;
    
    // Leemos las aristas
    for (int i = 0; i < A; ++i)
    {
        std::cin >> v >> w >> c;
        AristaDirigida<int> arista = AristaDirigida<int>(v-1, w-1, c);
        grafo.ponArista(arista);
        aristas.push_back(arista);
    }
    
    // Leemos la ciudad inicial.
    std::cin >> s;
    std::vector<int> distTo(grafo.V());
    std::vector<int> ida = dijkstra(grafo, s-1, aristas, distTo); // Hacemos dijkstra y obtenemos la distancia desde el origen a todos los destinos.
    // Hacemos dijkstra con el grafo inverso y obtenemos la distancia desde todos los destinos al origen. Coste O(numero de vertices + numero de aristas).
    std::vector<int> vuelta = dijkstra(grafo.reverse(), s-1, aristas,distTo); 
    
    std::cin >> nPaquetes;
    int esfuerzoMinimo = 0;
    int des;
    bool realizable = true;
    
    for (int i = 0; i < nPaquetes; ++i) // Por cada paquete.
    {
        std::cin >> des;
        if (ida[des-1] != std::numeric_limits<int>::max() && vuelta[des-1] != std::numeric_limits<int>::max()) // Si se puede llegar al destino tanto de ida como de vuelta.
            esfuerzoMinimo += ida[des-1] + vuelta[des-1]; // Calculamos el esfuerzo minimo.
        else
            realizable = false; // Si no se puede llegar no es realizable el trayecto.
    }
    
    if (realizable)
        std::cout << esfuerzoMinimo << "\n"; // Si el trayecto es realizable imprimimos el esfuerzo minimo.
    else
        std::cout << "Imposible\n";         // Si no es realizable imprimimos Imposible.
    
    
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