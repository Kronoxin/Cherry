//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 18 - Camino al cole.
//
/*
 Resumen de solucion:
 Implementamos el algoritmo de dijkstra.
 El algoritmo de dijkstra para nuestro problema no sirve porque descarta soluciones con el mismo coste y es para grafos dirigidos.
 Para usar dijkstra con nuestro grafo añadimos aristas invertidas, asi convertimos el grafo dirigido en uno no dirigido.
 Modificamos dijkstra de la siguiente forma.
 Llevamos un vector que cuenta cada vez que se pasa por un vertice. 
 Si nuestro camino es mejor, el numero de pisadas va a ser igual las pisadas del vertice origen.
 Si nuestro camino es igual, incrementamos las pisadas del vertice destino con las pisadas del vertice origen.
 
 Coste O(numero de aristas*log(numero de vertices)).
 */

#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"
#include <limits>

// Metodo que recorre las aristas adyacentes y selecciona aquellas que tenga un mejor coste.
// Tambien tiene en cuenta cuantas veces se ha pasado por los nodos usando los caminos optimos.
// Coste O(log(numero de vertices)).

void relajar(AristaDirigida<int> e,std::vector<int> &distTo,std::vector<AristaDirigida<int>> &edgeTo,IndexPQ<int> &pq,std::vector<int> &pisados,int d)
{
    size_t v = e.from();
    size_t w = e.to();
    if (distTo[w] > distTo[v] + e.valor()) // Si la distancia por esta arista es menor que la que habia.
    {
        distTo[w] = distTo[v] + e.valor(); // Actualizamos la distancia.
        edgeTo[w] = e;                     // Actualizamos la arista.
        pisados[w] = pisados[v];           // El numero de veces que se pisa el vertice destino es igual que el numero de veces que se pisa el vertice origen.
 
        try
        {
            pq.push(w, distTo[w]);
        }
        catch (std::invalid_argument)
        {
            pq.update(w, distTo[w]);
        }
        
    }
    else if (distTo[w] == distTo[v] + e.valor()) // Si la distancia es la misma.
    {    
        pisados[w] += pisados[v];    // Incrementamos el numero de veces que se ha pisado en el destino con el numero de veces que se ha pisado en el origen.
    }
    
}

// Metodo que implementa el algoritmo de dijkstra.
// Inicializamos todos los nodos con distancia maxima excepto el nodo origen.
// Vamos recorriendo las aristas y comprobando si la distancia por el camino actual es menor que la que habia antes y lo actualizamos.
// Devuelve la distancia al ultimo vertice, en este caso nuestro vertice destino.
// Coste O(numero de aristas*log(numero de vertices)).

int dijkstra(GrafoDirigidoValorado<int> G, int s,std::vector<AristaDirigida<int>> &edgeTo)
{

    std::vector<int> pisados(G.V());;
    std::vector<int> distTo(G.V());
    pisados[0] = 1;
    
    IndexPQ<int> pq(G.V());
    // inicializamos los vertices con el valor maximo de un entero.
    for (int v = 0; v < G.V(); v++)
        distTo[v] = std::numeric_limits<int>::max();
    
    distTo[s] = 0.0; // Inicializamos la distancia al origen con 0.
    pq.push(s, 0.0); // Metemos el vertice origen en el monticulo.
    
    while (!pq.empty()) // Mientras el monticulo no este vacio.
    {
        int v = (pq.top()).elem; // Sacamos el menor elemento.
        pq.pop(); // Sacamos el elemento del monticulo.
        for (auto e : G.adj(v)) // Recorremos todos sus vertices adyacentes.
            relajar(e,distTo,edgeTo,pq,pisados,G.V()-1); // Llamamos a relajar para actualizar las distancias y contar las pisadas. Coste O(log(numero de vertices)).
    }
    
    int nCaminos = 1;

    //Si el grafo no es conexo, no puede llegar al destino.
    if(distTo[distTo.size()-1]== std::numeric_limits<int>::max())
    {
        nCaminos = 0;
    }
    
    // Devolvemos cuantas veces se ha pisado el destino por caminos optimos.
    return pisados[G.V()-1];
    
}

// Metodo que se encarga de la resolucion del caso.
// Recoge la entrada del usuario e inicializa las variables.
// Duplica las aristas e invierte su sentido para hacer del grafo dirigido un grafo no dirigido. 
// Hace una llamada a la implementacion de dijstra, que nos devuelve el numero de caminos posibles desde el origen al destino.
// Coste O(numero de aristas*log(numero de vertices)).

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
        AristaDirigida<int>aristaDos = AristaDirigida<int>(w-1,v-1,c); // Duplicamos la arista invertida.
        grafo.ponArista(aristaUno); // Añadimos la arista uno al grafo.
        grafo.ponArista(aristaDos); // Añadimos la arista invertida al grafo.
    }
    for (int a = 0; a < grafo.V(); a++) // Inicializamos las aristas del vector de aristas.
    {
        AristaDirigida<int> b (0,0,0);
        edgeTo.push_back(b);
    }
    
    int numeroCaminos = 0;
    numeroCaminos = dijkstra(grafo, 0,edgeTo); // Obtenemos el numero de caminos. Coste O(numero de aristas*log(numero de vertices)).
    
    std::cout << numeroCaminos << "\n";
    
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
 
