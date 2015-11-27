//
//  Ejercicio19.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 27/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#include <iostream>

bool resuelveCaso()
{
    unsigned int a, p;
    
    std::cin >> a; // numero de agujeros
    
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    
    std::cin >> p; // longitud parches

    int longitudParche = p;
    int agujeroAnterior = 0;
    int numeroParches = 0;
    
    for(int i = 0; i < a; i++)
    {
        int agujeroActual;
        std::cin >> agujeroActual;
        
        if (agujeroAnterior == 0)
        {
            agujeroAnterior = agujeroActual;
            numeroParches++;
        }
        
        int distancia = agujeroActual - agujeroAnterior;
        
        if(distancia > longitudParche)
        {
            numeroParches++;
            longitudParche=p;
        }
        else{
            longitudParche -=distancia;
        }
        
        agujeroAnterior=agujeroActual;
    }
    
    std::cout << numeroParches << "\n";
    
    return true;
}
int main()
{
    while(resuelveCaso());
    return 0;
}


