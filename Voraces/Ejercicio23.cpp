//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 23 - Maratón de cine de terror
//

#include <stdio.h>
#include <vector>
#include "IndexPQ.h"


int resuelve(IndexPQ<int> &listaPeliculas)
{
    int hia,hfa,hiac,hfac;
    hia = listaPeliculas.top().prioridad;
    hfa = listaPeliculas.top().elem;
    
    listaPeliculas.pop();
    
    int numeroPelisVisionables = 1;
    
    while(!listaPeliculas.empty()) 
    {
        hiac = listaPeliculas.top().prioridad;
        hfac = listaPeliculas.top().elem;
    
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
    
    IndexPQ<int> listaPeliculas(24*60+1);
    
    
    
    for(int i = 0; i < nPeliculas ; i++)
    {
        
        int hh, mm, duracion; char c;

        std::cin >> hh >> c >> mm;  // el char lee los dos puntos
        std::cin >> duracion;
        
        hh = hh*60 + mm;
        size_t fin = hh+duracion;
        listaPeliculas.push(fin,hh);
        
    }
    std::cout << resuelve(listaPeliculas) << std::endl;
    return true;
    
}



int main()
{
    while(resuelveCaso());
    return 0;
}


