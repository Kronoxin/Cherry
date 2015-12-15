//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 24 - Planificación de conferencias
//
/*
 Resumen de solucion:
 * Vamos recorriendo los intervalos ordenados por inicio de la conferencia de menor a mayor.
 * Metemos el final del primer intervalo en un monticulo de minimos.
 * Si el principio del siguiente intervalo es superior al minimo del monticulo de minimos
 * entonces podemos meterlo en esa sala y metemos en el monticulo de minimos el final de ese intervalo.
 * Si no lo es se debe añadir una sala nueva y metemos el final del intervalo al monticulo de minimos.

 
 Coste O(numero de conferencias * log(numero de conferencias)).
 */

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

// Coste O(numero de conferencias * log(numero de conferencias)).
int resuelve(PriorityQueue<Conferencia,menorConferencia> &listaConferencias)
{
    int nSalasNecesarias = 1; // Como minimo necesitaremos una sala.
    int inicioA,finA,inicioAc,finAc;
    
    PriorityQueue<int> minFinales(listaConferencias.size());
    Conferencia c = listaConferencias.top(); // Cogemos la primera conferencia.
    inicioA = c.inicio;
    finA = c.fin;
    listaConferencias.pop();
    
    minFinales.push(finA); // metemos su final en la lista
    
    while (!listaConferencias.empty()) // Mientras siga habiendo conferencias.
    {
        Conferencia c = listaConferencias.top(); // Cogemos la conferencia actual.
        inicioAc = c.inicio;
        finAc = c.fin;
        listaConferencias.pop();
        

        if( minFinales.top() <= inicioAc) // Si puedo meter la conferencia en la misma sala.
        {
            minFinales.push(finAc); // Meto el final de la conferencia actual.
            minFinales.pop();        // Como lo meto en la misma sala, saco el minimo anterior.
        }
        else if (inicioAc < minFinales.top()) // no entra en ninguna de las salas.
        {
            nSalasNecesarias++; // Necesito otra sala mas.
            minFinales.push(finAc); // Meto el final de la conferencia actual.
        }
    }
    
 
    
    return nSalasNecesarias;
}
// O(numero de conferencias * log(numero de conferencias))
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

// Metodo principal, contiene un bucle que llama a la funcion resuelveCaso.
// Esta devuelve true mientras haya casos por resolver.
// Coste O(numero de conferencias*log(numero de conferencias)).

int main()
{
    while(resuelveCaso());
    return 0;
}