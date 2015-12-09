/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <iostream>
#include "PriorityQueue.h"
#include <cmath>

bool resuelveCaso()
{
    long long nCasos,nPilas,voltajeMin, altura, longitud;
    
    std::cin >> nCasos; // numero de casos de prueba
   
    
    
    for(long long i = 0; i < nCasos; i++)
    {
        std::cin >> nPilas; //numero de pilas
        std::cin >> voltajeMin; // voltaje mínimo
        for(long long i = 0; i < nPilas; i++)
        {
            PriorityQueue<int,std::greater<long long>> monMax(nPilas);
            PriorityQueue<int,std::less<long long>> monMin(nPilas);
            int a;
            
            std::cin >> a;
            monMax.push(a);
            monMin.push(a);

            
        }
    }
    
   
    
    
    
    return true;
}

int resuelve(PriorityQueue<int,std::greater<long long>> &monMax , PriorityQueue<int,std::less<long long>> &monMin){
    
    /*
     * 15 12 10 8 
     * 8  10 12 15
     * 
     * 
     *   */
    
    
    while (exp) {

    }

    
}
int main()
{
    while(resuelveCaso());
    return 0;
}