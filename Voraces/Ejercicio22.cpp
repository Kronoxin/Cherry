//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 22 - Carreras de coches.
//


#include <stdio.h>
#include <iostream>
#include <vector>
#include "PriorityQueue.h"

long resuelve(const std::vector<long> &pilas, long volMin){
    
    /*
     * 15 12 10 8 
     * 8  10 12 15
     * 
     * 
     *   */
    
    long i = 0;
    long j = pilas.size()-1;
    long nCoches = 0;
    while (i < j) 
    {
        if(pilas[i] + pilas[j] >= volMin)
        {
            i++;
            j--;
            nCoches++;
        }
        else
        {
            j--;
        }
    }
    return nCoches;

}

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
        for(long i = 0; i < nPilas; i++)
        {

            long a;
            
            std::cin >> a;
            pilasMon.push(a);

            
        }
        //quickSort(pilas,pilas.size());
        for (long a = 0; a < nPilas;a++)
        {
            pilas[a] = pilasMon.top();
            pilasMon.pop();
        }
        
        std::cout << resuelve(pilas,voltajeMin) << std::endl;
    }
}



int main()
{
    resuelveCaso();
    return 0;
}