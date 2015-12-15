//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 25 - El alienígena infiltrado
//
/*
 Resumen de solucion:
 * Vamos recorriendo los intervalos ordenados por inicio del proyecto de menor a mayor. 
 * Tenemos un punto actual que al principio toma el valor del inicio de nuestro rango.
 * Si encontramos un intervalo que empiece antes o en el mismo punto que mi punto actual
 * entonces es un intervalo valido, pero puede que no optimo.
 * Saco la distancia desde mi punto actual al final del intervalo y compruebo si esa distancia
 * es la maxima.
 * Si es la maxima compruebo si hemos terminado o no.
 * Si no encontramos un intervalo que empiece antes o en el mismo punto puede ser debido
 * a que hay un hueco y por tanto es imposible obtener un resultado o que hayamos comprobado
 * todos los intervalos posibles para ese punto actual.
 * Si la distancia maxima es mayor que 0 entonces nos encontramos en el segundo caso y tenemos
 * que actualizar el punto actual con el final del mejor intervalo posible para ese punto.
 * Incrementamos el numero de intervalos y establecemos la distancia maxima como la distancia actual
 * desde el punto al fin del intervalo actual.
 * Seguimos iterando mientras haya elementos en la lista de intervalos y no hayamos llegado al final
 * y no sea imposible.
 
 Coste O(numero de proyectos * log(numero de proyectos)).
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
// O(numero de proyectos * log(numero de proyectos))
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
            listaProyectos.pop(); // Saco el proyecto de la lista.
            
        }
        else if (inicio <= puntoActual + distanciaMaxima) // Significa que he llegado al mejor intervalo alcanzable y debo continuar al siguiente.
        {
            puntoActual += distanciaMaxima; // Actualizo el punto actual.
            distanciaMaxima = 0; // Actualizo la distancia maxima con 0.
            nProyectosMin++; // Incremento el numero de proyectos minimo.
            
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

// O(numero de proyectos*log(numero de proyectos))
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

// Metodo principal, contiene un bucle que llama a la funcion resuelveCaso.
// Esta devuelve true mientras haya casos por resolver.
// Coste O(numero de proyectos*log(numero de proyectos)).

int main()
{
    while(resuelveCaso());
    return 0;
}