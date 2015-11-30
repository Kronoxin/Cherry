//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 3 - Rango de Claves en un arbol de busqueda binario.
//
/* Resumen de solucion:
 Recorremos el arbol y vamos decidiendo en funcion de si nuestra clave es menor o mayor que los limites
 del rango si nos metemos en las ramas izquierdas o derechas o no.
 
 */

#include <stdio.h>
#include "TreeMapRango.h"

TreeMapRango<int,int> cargarArbol(int n)
{
    
    int clave;
    TreeMapRango<int,int> mapa;
    
    for (int i =0; i<n; i++)
    {
        std::cin >> clave;
        mapa.insert(clave, i);
        
    }
    return mapa;
}


int main()
{
    while (true)
    {
        int numCasos;
    std::cin >> numCasos;
    if (numCasos == 0)
        return 0;
    
    auto mapa = cargarArbol(numCasos);
    int min,max;
    
    std::cin >> min;
    std::cin >> max;
    
    std::vector<int> lista = mapa.rango(min, max);
    
        for (unsigned int i = 0; i < lista.size(); i++)
        {
            if (lista[i] != lista[lista.size()-1])
                std::cout << lista[i] << " ";
            else
                std::cout << lista[i];
        }
        
        
        std::cout << "\n";
            
            
        
        
    }
    
    return 0;
}