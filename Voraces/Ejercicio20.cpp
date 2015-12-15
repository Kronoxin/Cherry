//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 20 - Esquiando en Alaska.
//
/*
 Resumen de solucion:
 * Ordenamos las alturas y la longitud de los esquis de menor a mayor y hacemos la suma de las diferencias.
 Coste O(numero de esquiadores * log(numero de esquiadores)).
 */

#include <stdio.h>
#include <iostream>
#include "PriorityQueue.h"
#include <cmath>

// Metodo que se encarga de la resolucion del caso.
// Recoge la entrada del usuario e inicializa las variables.
// Ordenamos las alturas y la longitud de los esquis de menor a mayor y hacemos la suma de las diferencias. 
// Coste O(numero de esquiadores * log(numero de esquiadores)).

bool resuelveCaso()
{
    long e, altura, longitud;
    
    std::cin >> e; // numero de esquiadores
    
    if (e==0)  // hemos terminado de procesar todos los casos
        return false;
    
    PriorityQueue<long> esquiadores(e); 
    PriorityQueue<long> esquis(e);
    
    // O(numero de esquiadores*log(numero de esquiadores))
    for(long i = 0; i < e; i++)
    {
        std::cin >> altura;
        // O(log(numero de esquiadores)
        esquiadores.push(altura);
    }
    // O(numero de esquiadores*log(numero de esquiadores))
    for(long i = 0; i < e; i++)
    {
        std::cin >> longitud;
        // O(log(numero de esquiadores))
        esquis.push(longitud);
    }
    long diferenciaMinima = 0;
    
    // Mientras queden esquiadores, calculamos la diferencia minima.
    // O(numero de esquiadores* log(numero de esquiadores))s
    while(!esquiadores.empty())
    {
        diferenciaMinima += std::abs(esquiadores.top() - esquis.top());
        esquiadores.pop(); // O(log(numero de esquiadores))
        esquis.pop();      // O(log(numero de esquiadores))
    }
    
    std::cout << diferenciaMinima << "\n";
    
    
    return true;
}

// Metodo principal, contiene un bucle que llama a la funcion resuelveCaso.
// Esta devuelve true mientras haya casos por resolver.
// Coste O(numero de esquiadores*log(numero de esquiadores)).

int main()
{
    while(resuelveCaso());
    return 0;
}