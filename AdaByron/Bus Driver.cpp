//
//  Bus Driver.cpp
//  Ejercicio1


#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>
#include <functional>     // std::greater


void resuelveCaso()
{
    int nBus; // numero de buses
    int nHoras; // numero de horas
    int costePenalizacion; // coste penalización por horas
    char c;

    
    std::cin >> nBus ; // leo el numero de casos.
    std::cin >> nHoras ; // leo el numero de casos.
    std::cin >> costePenalizacion ; // leo el numero de casos.
    std::cin.get(c);     //quemamos el \n
    
  
    while(nBus !=0 && nHoras !=0 && costePenalizacion !=0)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int> > dia;
        std::priority_queue<int, std::vector<int>, std::less<int> > noche;
    
        int a;
        for ( int i= 0 ; i < nBus ;i++){
            std::cin >> a;
            dia.push(a);
        }
        for ( int i= 0 ; i < nBus ;i++){
            std::cin >> a;
            noche.push(a);
        }
        
      
        
        int i = 0;
        int resultado = 0;
        
        while(!dia.empty() && !noche.empty() && i<nBus)
        {
            int horaDia , horaNoche;
            horaDia = dia.top();
            dia.pop();
            horaNoche = noche.top();
            noche.pop();
            i++;
            
            if (nHoras-(horaDia+horaNoche) < 0)
                resultado += abs((nHoras-(horaDia + horaNoche)))*costePenalizacion;
            
        }
        
        std::cout<<resultado<< std::endl;
        

        std::cin >> nBus ; // leo el numero de casos.
        std::cin >> nHoras ; // leo el numero de casos.
        std::cin >> costePenalizacion ; // leo el numero de casos.
        std::cin.get(c);     // quemamos el \n

    }
    

    
    
}


int main()
{
    resuelveCaso();
    return 0;
}