
#include <iostream>
#include "PriorityQueue.h"

bool resuelveCaso()
{
    unsigned int ciudades;
    
    std::cin >> ciudades; 
    
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    
    int ciudadesDefendibles = 0;
    PriorityQueue<int,std::greater<int>> atacantes(ciudades);
    PriorityQueue<int,std::greater<int>> defensores(ciudades);
    
    for(int i = 0; i < ciudades; i++)
    {
        int unidades;
        std::cin >> unidades;
        atacantes.push(unidades);
    }
    for(int i = 0; i < ciudades; i++)
    {
        int unidades;
        std::cin >> unidades;
        defensores.push(unidades);
    }
    while(!atacantes.empty())
    {
        int atacante = atacantes.top();
        int defensor = defensores.top();
        if (defensor >= atacante)
        {
            ciudadesDefendibles++;
            atacantes.pop();
            defensores.pop();
        }
        else
            atacantes.pop();
    }
    
    std::cout << ciudadesDefendibles << "\n";
    
    return true;
}
int main()
{
    while(resuelveCaso());
    return 0;
}


