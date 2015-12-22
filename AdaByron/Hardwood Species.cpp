//
//  Hardwood Species.cpp


#include <stdio.h>
#include <iostream>
#include <vector>


bool resuelveCaso()
{
    int nCasos;
    char c ;
    std::vector<std::string> vector(0);
    
    
    std::cin >> nCasos ; // leo el numero de casos.
    std::cin.get(c);     //leo el \n
    std::cin.get(c);     // y otra vez

    
    std::string especie;
    
    do {
        std::getline(std::cin, especie);
        if(especie !="")
            vector.push_back(especie);
        
    } while (especie !="");
    
    std::cout <<" He leido : " << std::endl;
    for ( int i= 0 ; i< vector.size(); i++){
        
        std::cout << vector[i] << std::endl;
        
    }
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}