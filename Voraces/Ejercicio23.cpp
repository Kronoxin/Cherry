//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 23 - Maratón de cine de terror
//
/*
 Resumen de solucion:

 
 Coste O().
 */

#include <stdio.h>
#include <vector>
#include "PriorityQueue.h"

struct Peliculas
{
    int inicio;
    int fin;
};

struct menorPelis
{
    bool operator()(Peliculas const &p1, Peliculas const &p2)
    {
        return p1.inicio < p2.inicio;
    }
    
};
int resuelve(PriorityQueue<Peliculas,menorPelis> &listaPeliculas)
{
    int hia,hfa,hiac,hfac;
    Peliculas peli = listaPeliculas.top();
    hia = peli.inicio;
    hfa = peli.fin;
    
    listaPeliculas.pop();
    
    int numeroPelisVisionables = 1;
    
    while(!listaPeliculas.empty())
    {
        Peliculas peli = listaPeliculas.top();
        hiac = peli.inicio;
        hfac = peli.fin;
        
        listaPeliculas.pop();
        
        if (hfa <= hiac-10) // Si el principio de la siguiente pelicula es posterior al final de la pelicula anterior, caben las dos peliculas.
        {
            numeroPelisVisionables++;
            hia = hiac;
            hfa = hfac;
        }
        else if(hfac < hfa) // Si se solapan, compruebo si la nueva pelicula acaba antes y si es asi seleccionamos la nueva pelicula puesto que es mejor(mas corta).
        {
            hia = hiac;
            hfa = hfac;
        }
    }
    return numeroPelisVisionables;
}
bool resuelveCaso()
{
    int nPeliculas;
    
    std::cin >> nPeliculas; // numero de peliculas
    
    if(nPeliculas == 0)
        return false;
    
    PriorityQueue<Peliculas,menorPelis> listaPeliculas(nPeliculas);
    
    
    
    for(int i = 0; i < nPeliculas ; i++)
    {
        
        int hh, mm, duracion; char c;
        
        std::cin >> hh >> c >> mm;  // el char lee los dos puntos
        std::cin >> duracion;
        hh = hh*60+mm;
        Peliculas p;
        p.inicio = hh;
        p.fin = hh+duracion;
        listaPeliculas.push(p);
        
    }
    std::cout << resuelve(listaPeliculas) << std::endl;
    
    return true;
    
}



int main()
{
    while(resuelveCaso());
    return 0;
}


