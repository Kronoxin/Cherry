//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 25 - El alienígena infiltrado
//
/*
 Resumen de solucion:

 
 Coste O().
 */


#include <stdio.h>
#include "PriorityQueue.h"

struct Proyectos
{
    int inicio;
    int fin;
};

struct menorProyecto
{
    bool operator()(Proyectos const &p1, Proyectos const &p2)
    {
        return p1.inicio < p2.inicio;
    }
    
};

int resuelve(PriorityQueue<Proyectos,menorProyecto> &listaProyectos, const int iniIntervalo, const int finIntervalo)
{
    int nProyectosMin = 0;
    int inicio,fin;
    int puntoActual=iniIntervalo;
    
    bool imposible = false;
    bool hemosTerminado = false;
    int distanciaMaxima = 0;
    
    while (!listaProyectos.empty() && !imposible && !hemosTerminado)
    {
        Proyectos p = listaProyectos.top();
        inicio = p.inicio;
        fin = p.fin;
        
        if(inicio <= puntoActual) // Es un candidato a evaluar
        {
            if (fin - puntoActual > distanciaMaxima) // Si el candidato llega mas lejos que mi intervalo anterior.
            {
                distanciaMaxima = fin - puntoActual; // Actualizo la distancia maxima.
                if (puntoActual + distanciaMaxima >= finIntervalo)
                {
                    nProyectosMin++;
                    hemosTerminado = true;
                }
            }
            listaProyectos.pop();
            
        }
        else if (inicio <= puntoActual + distanciaMaxima) // Significa que he llegado al mejor intervalo alcanzable y debo continuar al siguiente.
        {
            puntoActual += distanciaMaxima;
            distanciaMaxima = 0;
            nProyectosMin++;
            
        }
        else // no puedo alcanzar el punto final.
        {
            imposible = true;
        }
    }
    
    
    
    if (imposible || !hemosTerminado)
        nProyectosMin = 0;

    
    
    
    return nProyectosMin;
}


bool resuelveCaso()
{
    int nProyectos,iniInter,finInter;
    
    std::cin >> iniInter >> finInter >> nProyectos ;
    
    if(nProyectos == 0 && iniInter == 0 && finInter == 0)
        return false;
    
    PriorityQueue<Proyectos,menorProyecto> listaProyectos(nProyectos);
    
    
    
    for(int i = 0; i < nProyectos ; i++)
    {
        
        int inicio, fin;
        
        std::cin >> inicio >> fin;
        
        Proyectos p;
        p.inicio = inicio;
        p.fin = fin;
        
        listaProyectos.push(p);
        
    }
    
    int resultado = resuelve(listaProyectos,iniInter,finInter);
    if(resultado == 0){
        std::cout << "Imposible" << std::endl;
    }
    else{
        std::cout << resultado << std::endl;
    }
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}