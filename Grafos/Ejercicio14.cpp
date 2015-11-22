/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
     bool mapa[][];
    std::vector<bool> mapa;
 */
#include "Grafo.h"
#include "Manchas.h"

struct mancha{
    unsigned int x;
    unsigned int y;
    bool negra;
};

bool resuelveCaso()
{  
    
    size_t f, co;
    char c;
    
    std::cin >> f; // número de filas
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    
    std::cin >> co; // número de columnas
    
    std::vector<std::vector<bool>> mapa(f, std::vector<bool>(co));
    for(int i = 0; i < f; i++)
    {
        for(int j = 0; j < co; j++)
        { 
            // de esta forma leo todo, espacios en blanco, saltos de linea, etc.
            std::cin >> std::noskipws >> c;
            if(c == '#')
                mapa[i][j] = true;
            else if(c == ' ')
                mapa[i][j] = false;
            else
                j--;

        }
        
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