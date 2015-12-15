//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 22 - Carreras de coches.
//
/*
 Resumen de solucion:
 * Tengo un vector con las pilas ordenadas de mayor a menor.
 * Si la suma de la mayor con la menor es suficiente para encender el coche
 * entonces pasamos a comparar la siguiente de los mayores y el anterior de los menores.
 * Si la suma no es suficiente entonces descartamos la pila de menor voltaje.
 * Volvemos a comparar hasta que no queden pilas por comparar.
 Coste O(numero de pilas * log(numero de pilas).
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include "PriorityQueue.h"

// O(numero de pilas * log(numero de pilas))
long resuelve(const std::vector<long> &pilas, long volMin)
{

    long i = 0;
    long j = pilas.size()-1;
    long nCoches = 0;
    // Mientras no se crucen la i y la j.
    while (i < j) 
    {   // Si el voltaje de la mayor y la menor es superior o igual al voltaje minimo necesario.
        if(pilas[i] + pilas[j] >= volMin)
        {
            i++; // Incrementamos la i para probar con una pila de voltaje menor.
            j--; // Incrementamos la j para probar con una pila de voltaje mayor.
            nCoches++; // incrementamos el numero de coches que podemos usar.
        }
        else
            j--; // Descartamos la pila de menor voltaje.
    }
    return nCoches;

}

// O(numero de pilas*log(numero de pilas))
void resuelveCaso()
{
    long nCasos;
    long nPilas;
    long voltajeMin;
    
    std::cin >> nCasos; // numero de casos de prueba
   
    
    for(long i = 0; i < nCasos; i++)
    {
        std::cin >> nPilas; //numero de pilas
        std::cin >> voltajeMin; // voltaje mínimo
        std::vector<long> pilas(nPilas);
        PriorityQueue<long,std::greater<long>> pilasMon(nPilas);
        
        // O (nPilas*log(nPilas))
        for(long i = 0; i < nPilas; i++)
        {
            long a;
            
            std::cin >> a;
            pilasMon.push(a);
           
        }
        // O(nPilas*log(nPilas))
        for (long a = 0; a < nPilas;a++)
        {
            pilas[a] = pilasMon.top();
            pilasMon.pop();
        }
        // O(nPilas*log(nPilas))
        std::cout << resuelve(pilas,voltajeMin) << std::endl;
    }
}

// Funcion principal, llama a resuelveCaso.
// O(numero de pilas * log(numero de pilas))
int main()
{
    resuelveCaso();
    return 0;
}