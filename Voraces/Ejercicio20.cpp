//
//  Ejercicio20.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 27/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "PriorityQueue.h"
#include <cmath>

bool resuelveCaso()
{
    long long e, altura, longitud;
    
    std::cin >> e; // numero de esquiadores
    
    if (e==0)  // hemos terminado de procesar todos los casos
        return false;
    
    PriorityQueue<long long> esquiadores(e);
    PriorityQueue<long long> esquis(e);
    
    for(long long i = 0; i < e; i++)
    {
        std::cin >> altura;
        esquiadores.push(altura);
    }
    for(long long i = 0; i < e; i++)
    {
        std::cin >> longitud;
        esquis.push(longitud);
    }
    long long diferenciaMinima = 0;
    
    while(!esquiadores.empty())
    {
        diferenciaMinima += std::abs(esquiadores.top() - esquis.top());
        esquiadores.pop();
        esquis.pop();
    }
    
    std::cout << diferenciaMinima << "\n";
    
    
    return true;
}
int main()
{
    while(resuelveCaso());
    return 0;
}