//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 21 - ¡Nos invaden!
//
/*
 Resumen de solucion:
 * Se ordenan los atacantes y los defensores de mayor a menor.
 * Se van recorriendo los atacantes y si se puede defender la ciudad se quitan tanto a los atacantes como a los defensores y se contabiliza la ciudad defendida.
 * Si no se puede defender, no va a existir ningun defensor que pueda defender una ciudad con esa cantidad de atacantes por tanto se saca
 * a ese grupo de atacantes de la lista y se sigue iterando hasta que no haya mas atacantes.

 
 Coste O(numero de ciudades*log(numero de ciudades)).
 */


#include <iostream>
#include "PriorityQueue.h"

// Metodo que se encarga de la resolucion del caso.
// Recoge la entrada del usuario e inicializa las variables.
// * Se ordenan los atacantes y los defensores de mayor a menor.
// * Se van recorriendo los atacantes y si se puede defender la ciudad se quitan tanto a los atacantes como a los defensores y se contabiliza la ciudad defendida.
// * Si no se puede defender, no va a existir ningun defensor que pueda defender una ciudad con esa cantidad de atacantes por tanto se saca
// * a ese grupo de atacantes de la lista y se sigue iterando hasta que no haya mas atacantes.
// Coste O(numero de ciudades*log(numero de ciudades)).

bool resuelveCaso()
{
    unsigned int ciudades;
    
    std::cin >> ciudades; 
    
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    
    int ciudadesDefendibles = 0;
    PriorityQueue<int,std::greater<int>> atacantes(ciudades);
    PriorityQueue<int,std::greater<int>> defensores(ciudades);
    
    // O(numero de ciudades*log(numero de ciudades))
    for(int i = 0; i < ciudades; i++)
    {
        int unidades;
        std::cin >> unidades;
        // O(log(numero de ciudades))
        atacantes.push(unidades);
    }
    // O(numero de ciudades*log(numero de ciudades))
    for(int i = 0; i < ciudades; i++)
    {
        int unidades;
        std::cin >> unidades;
        // O(log(numero de ciudades))
        defensores.push(unidades);
    }
    // O(numero de ciudades*log(numero de ciudades))
    while(!atacantes.empty())
    {
        int atacante = atacantes.top();
        int defensor = defensores.top();
        if (defensor >= atacante) // Si la ciudad es defendible.
        {
            ciudadesDefendibles++; // La contabilizamos.
            atacantes.pop(); // Sacamos a los atacantes. O(log(numero de ciudades))
            defensores.pop(); // Sacamos a los defensores. O(log(numero de ciudades))
        }
        else
            atacantes.pop(); // Si no es defendible solo sacamos a los atacantes. O(log(numero de ciudades))
    }
    
    std::cout << ciudadesDefendibles << "\n";
    
    return true;
}

// Metodo principal, contiene un bucle que llama a la funcion resuelveCaso.
// Esta devuelve true mientras haya casos por resolver.
// Coste O(numero de ciudades*log(numero de ciudades)).

int main()
{
    while(resuelveCaso());
    return 0;
}


