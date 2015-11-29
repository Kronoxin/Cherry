//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 13 - Haciendo trampas en serpientes y escaleras.
//
/*
 Resumen de solucion:
 Realizamos un recorrido en anchura.
 Todas las casillas alcanzables en una tirada de dado se consideran que estan a 1 de distancia del vertice origen.
 Vamos recorriendo los nodos alcanzables, siendo estos dependientes del numero de tiradas del dado.
 Por cada nodo asignamos el esfuerzo o distancia que hemos recorrido para llegar hasta el.
 La distancia asignada a cada nodo tras recorrerlo sera la minima distancia posible para llegar hasta ese nodo.
 
 Coste O(numero de vertices + numero de aristas).
 */

#include <iostream>
#include <vector>
#include <queue>

// Funcion que devuelve el menor numero de tiradas del dado necesarias para ganar.
// Coste O(numero de vertices + numero de aristas).
int minimoNumeroDeTiradas(const std::vector<int> &atajos, int s, std::vector<bool> &marked,int carasDado, std::vector<int> &distTo,int tamTablero)
{
    std::queue<size_t> q; // Declaramos una cola para ir insertando los vertices.
    distTo[s] = 0; // La distancia al nodo origen es 0.
    marked[s] = true; // Hemos visitado el nodo origen.
    q.push(s); // Lo metemos en la cola para recorrer sus nodos adyacentes.
    
    while (!q.empty()) // Mientras la cola no este vacia.
    {
        auto v = q.front(); // sacamos el primer nodo adyacente.
        q.pop();            // lo eliminamos de la cola.
        
        for (int w=1; w <= carasDado; w++) // Recorremos los nodos alcanzables en una tirada de dado.
        {
            int actual = v+w; // Establecemos el nodo actual a fin de simplificar el cambio de nodo en caso de serpiente o escalera.
            
            if (actual < tamTablero*tamTablero) // Si no nos pasamos del limite del tablero.
            {
                if( atajos[actual] > 0) // Si existe una serpiente o escalera en esa casilla.
                {
                    actual = atajos[actual]; //  Nuestra casilla actual sera la casilla a la que apunte la serpiente o escalera.
                }
                
                if (!marked[actual]) // Si la casilla actual no ha sido ya visitada.
                {
                    distTo[actual] = distTo[v] + 1; // Incrementamos la distancia a nuestro nodo en 1.
                    marked[actual] = true; // Lo marcamos como visitado.
                    q.push(actual);        // Lo metemos en la cola para recorrer sus nodos adyacentes.         
                }
            }
        }
    }
    return distTo[tamTablero*tamTablero-1]; // Devolvemos la distancia que hay desde el punto de origen a la ultima casilla del tablero.
}

// Metodo que se encarga de la resolucion del caso.
// Recoge la entrada del usuario, inicializa las variables y llama a la funcion que devuelve el numero minimo de tiradas.
// Coste O(numero de vertices + numero de aristas).
void resuelveCaso()
{
    int tamTablero,carasDado,numSerpientes,numEscaleras;
    
    std::cin >> tamTablero;
    
    while(tamTablero > 0)
    {
    
    std::cin >> carasDado;
    std::cin >> numSerpientes;
    std::cin >> numEscaleras;
    // atajos guarda la informacion de escaleras y serpientes. La posicion i indica la casilla de origen y atajos[i] indica la casilla final.
    std::vector<int> atajos(tamTablero*tamTablero,-1);
    
    // Leemos las escaleras y las serpientes.
    // Coste O(numEscaleras+NumSerpientes).
    for (int i=0; i < numEscaleras+numSerpientes; i++)
    {
        int a,b;
        std::cin >> a;
        std::cin >> b;
        atajos[a-1]=b-1;
    }
    std::vector<bool> marked(tamTablero*tamTablero,false);
    std::vector<int> disTo(tamTablero*tamTablero,0);
    
    // Imprimimos el numero minimo de tiradas.
    // Coste O((numero de vertices + numero de aristas).
    std::cout << minimoNumeroDeTiradas(atajos,0,marked,carasDado,disTo,tamTablero) << "\n";
    std::cin >> tamTablero;
    }
    
}

// Metodo principal, llama a la funcion resuelveCaso.
// Coste O(numero de vertices + numero de aristas).

int main()
{
    resuelveCaso();
    return 0;
}
