//
//  Ejercicio24.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 11/12/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#include <stdio.h>
#include "PriorityQueue.h"

struct Conferencia
{
    int inicio;
    int fin;
};

struct menorConferencia
{
    bool operator()(Conferencia const &c1, Conferencia const &c2)
    {
        return c1.inicio < c2.inicio;
    }
    
};

int resuelve(PriorityQueue<Conferencia,menorConferencia> &listaConferencias)
{
    int nSalasNecesarias = 1;
    int inicioA,finA,inicioAc,finAc;
    
    PriorityQueue<int> minFinales(listaConferencias.size());
    Conferencia c = listaConferencias.top();
    inicioA = c.inicio;
    finA = c.fin;
    listaConferencias.pop();
    
    minFinales.push(finA);
    
    while (!listaConferencias.empty())
    {
        Conferencia c = listaConferencias.top();
        inicioAc = c.inicio;
        finAc = c.fin;
        listaConferencias.pop();
        

        if( minFinales.top() <= inicioAc) // puedo meter la conferencia en la misma sala.
        {
            minFinales.push(finAc);
            minFinales.pop();        // Como lo meto en la misma sala, saco el minimo anterior.
        }
        else if (inicioAc < minFinales.top()) // no entra en ninguna de las salas.
        {
            nSalasNecesarias++;
            minFinales.push(finAc);
        }
    }
    
 
    
    return nSalasNecesarias;
}

bool resuelveCaso()
{
    int nConferencias;
    
    std::cin >> nConferencias; // numero de peliculas
    
    if(nConferencias == 0)
        return false;
    
    PriorityQueue<Conferencia,menorConferencia> listaConferencias(nConferencias);
    
    
    
    for(int i = 0; i < nConferencias ; i++)
    {
        
        int inicio, fin;
        
        std::cin >> inicio >> fin;
        
        Conferencia c;
        c.inicio = inicio;
        c.fin = fin;
        
        listaConferencias.push(c);
        
    }
    std::cout << resuelve(listaConferencias) << std::endl;
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}