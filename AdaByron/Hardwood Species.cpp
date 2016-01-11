#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

/*
void resuelveCaso()
{
    int nCasos;
    char c ;
    
    
    std::cin >> nCasos ; // leo el numero de casos.
    std::cin.get(c);     //leo el \n
    std::cin.get(c);     // y otra vez
    
    
    std::string especie;
    
    
    for ( int i = 0 ; i< nCasos; i++)
    {
        unordered_map<string,long> conteoEspecies;
        map<string,short> nombreEspecies;
        long numeroArboles = 0;
        do
         {
            
            std::getline(std::cin, especie);
            if(especie !="")
            {
                if (conteoEspecies.find(especie) != conteoEspecies.end())
                    conteoEspecies[especie]++;
                else
                {
                    conteoEspecies[especie] = 1; // O(1)
                    nombreEspecies[especie] = 1; // O(log n)
                }
                numeroArboles++;
            }
            
        }
        while (especie !="");
        
        map<string,short>::const_iterator it = nombreEspecies.cbegin();
        while(it != nombreEspecies.end())
        {
            float porcentaje = (float)conteoEspecies[it->first]/numeroArboles*100; // Sacamos el porcentaje.
            std::cout << it->first << " " << std::fixed << std::setprecision(4) << porcentaje << std::endl; // Dejamos 4 decimales.
            it++;
        }
        if (i != nCasos-1)
            std::cout << endl;
        
    }
    
}


int main()
{
    resuelveCaso();
    return 0;
}
*/