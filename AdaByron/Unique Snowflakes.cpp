//
//  Unique Snowflakes.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 22/12/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

bool resuelveCaso()
{
    int nCasos; // numero de casos de prueba
    int nCopos; // numero de copos a procesar
    
    
    std::cin >> nCasos ; // leo el numero de casos.
    std::cin >> nCopos ;
    

    
    for ( int i = 0 ; i< nCasos; i++){
        std::vector<int> copos(0);
        
        for(int j = 0; j < nCopos ; j++)
        {
            int a;
            
            std::cin >> a;
            copos.push_back(a);
            
        }

    }

    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}