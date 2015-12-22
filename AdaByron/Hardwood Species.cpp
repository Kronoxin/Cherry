//
//  Hardwood Species.cpp


#include <stdio.h>
#include <iostream>
#include <vector>


bool resuelveCaso()
{
    int nCasos;
    char c ;
    
    
    std::cin >> nCasos ; // leo el numero de casos.
    std::cin.get(c);     //leo el \n
    std::cin.get(c);     // y otra vez

    
    std::string especie;
    
    
    for ( int i = 0 ; i< nCasos; i++){
        std::vector<std::string> vector(0);
    
        do {
            
            std::getline(std::cin, especie);
            if(especie !="")
                vector.push_back(especie);
        
        } while (especie !="");
    }
    
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}