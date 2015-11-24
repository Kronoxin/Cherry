/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Grafo.h"
#include "ManchasCrecientes.h"

bool resuelveCaso()
{
   unsigned int f, co;
    
    std::cin >> f; // número de filas
    
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    
    std::cin >> co; // número de columnas
    
    Matriz<bool> mapa = Matriz<bool>(f,co);
    
    //Ignoramos el \n
    std::cin.ignore();
    
    std::string linea;
    for(int i = 0; i < f; i++)
    {
        std::getline(std::cin,linea);
        
        for(int j = 0; j < co; j++)
        {
            mapa[i][j] = (linea[j] == '#'); 
        }
    }
    
    ManchasCrecientes m = ManchasCrecientes(mapa,f,co);
    
    unsigned int inserciones;
    
    std::cin >> inserciones;
    for (unsigned int i = 0; i < inserciones; i++)
    {
        int fila,columna;
        std::cin >> fila;
        std::cin >> columna;
        m.actualizarManchas(fila-1,columna-1);
        std::cout << m.mayorNumeroManchas() << "\n";
    }

    return true;
}
int main()
{
    while(resuelveCaso());
    return 0;
}