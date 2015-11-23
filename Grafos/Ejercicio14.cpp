/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Grafo.h"
#include "Manchas.h"

bool resuelveCaso()
{
       
    unsigned int f, co;
    
    std::cin >> f; // número de filas
    char c;
    
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    
    std::cin >> co; // número de columnas
    
    Matriz<bool> mapa = Matriz<bool>(f,co);
    
    std::cin.get(c);
    
    for(int i = 0; i < f; i++)
    {
        for(int j = 0; j < co; j++)
        {
            // de esta forma leo todo, espacios en blanco, saltos de linea, etc.
            std::cin.get(c);
            if(c == '#')
                mapa[i][j] = true;
            else if(c == ' ')
                mapa[i][j] = false;
            else
                j--;
            
        }
        std::cin.get(c);
        
    }
    
    
    Manchas m = Manchas(mapa,f,co);
    std::cout << m.mayorNumeroManchas() << "\n";
    
    return true;
}
int main()
{
    while(resuelveCaso());
    return 0;
}
