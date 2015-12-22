//
//  Commandos.cpp


#include <stdio.h>
#include <iostream>
#include <vector>


bool resuelveCaso()
{
    int nCasos, nCaminos;
    
    size_t A, v, w;
    
    std::cin >> nCasos; // número de casos de prueba
    
   // GrafoDirigidoValorado<int> grafo(V);
    
   // std::vector<AristaDirigida<int>> edgeTo;
    
    for(int j = 0; j < nCasos; j++){
        
        std::cin >> A; // número de aristas
        
        std::cin >> nCaminos ; // numero de caminos
   
        for (int i = 0; i < A; ++i)
        {
            std::cin >> v >> w;
            //AristaDirigida<int>arista = AristaDirigida<int>(v,w,1);
            //grafo.ponArista(arista);
            //edgeTo.push_back(arista);
        
        }
        
    }

    
    return true;
    
}
int main()
{
    while(resuelveCaso());
    return 0;
}

