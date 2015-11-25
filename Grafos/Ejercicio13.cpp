//
//  Ejercicio13.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 18/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <queue>

int minimoNumeroDeTiradas(const std::vector<int> &atajos, int s, std::vector<bool> &marked,int carasDado, std::vector<int> &distTo,int tamTablero)
{
    std::queue<size_t> q;
    distTo[s] = 0;
    marked[s] = true;
    q.push(s);
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        
        for (int w=1; w <= carasDado; w++)
        {
            int actual = v+w;
            
            if (actual < tamTablero*tamTablero)
            {
                if( atajos[actual] > 0)
                {
                    actual = atajos[actual];
                }
                
                if (!marked[actual])
                {
                    distTo[actual] = distTo[v] + 1;
                    marked[actual] = true;
                    q.push(actual);
                    
                    
                    
                }
            }
        }
    }
    return distTo[tamTablero*tamTablero-1];
}

void resuelveCaso()
{
    int tamTablero,carasDado,numSerpientes,numEscaleras;
    
    std::cin >> tamTablero;
    
    while(tamTablero > 0)
    {
    
    std::cin >> carasDado;
    std::cin >> numSerpientes;
    std::cin >> numEscaleras;
    
    std::vector<int> atajos(tamTablero*tamTablero,-1);
    
    for (int i=0; i < numEscaleras+numSerpientes; i++)
    {
        int a,b;
        std::cin >> a;
        std::cin >> b;
        atajos[a-1]=b-1;
    }
    std::vector<bool> marked(tamTablero*tamTablero,false);
    std::vector<int> disTo(tamTablero*tamTablero,0);
    
    
    std::cout << minimoNumeroDeTiradas(atajos,0,marked,carasDado,disTo,tamTablero) << "\n";
    std::cin >> tamTablero;
    }
    
}

int main()
{
    resuelveCaso();
    return 0;
}*/
