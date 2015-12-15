//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 23 - Maratón de cine de terror
//
/*
 Resumen de solucion:
 * Vamos recorriendo los intervalos que tienen las peliculas ordenadas por su inicio de menor a mayor.
 * Si el principio de la siguiente pelicula es posterior al final de la pelicula anterior, caben las dos peliculas.
 * y se incrementa el numero de peliculas que puedes ver.
 * Si no es posterior significa que se solapan, por tanto hay dos opciones.
 * Que sea mejor que mi intervalo anterior( termine antes) o peor o igual (termine despues o al mismo tiempo).
 * Si es mejor lo sustituimos, si es peor lo ignoramos.
 * 
 Coste O(numero de peliculas * log(numero de peliculas)).
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

// Metodo que se encarga de la resolucion del caso.
// 
// Coste O(numero de peliculas*log(numero de peliculas)).

int resuelve(PriorityQueue<Peliculas,menorPelis> &listaPeliculas)
{
    int hia,hfa,hiac,hfac;
    Peliculas peli = listaPeliculas.top(); // Cogemos la primera pelicula.
    hia = peli.inicio;
    hfa = peli.fin;
    
    listaPeliculas.pop();
    
    int numeroPelisVisionables = 1; // Como minimo podemos ver una pelicula.
    
    while(!listaPeliculas.empty()) // Mientras la lista de peliculas no este vacia.
    {
        Peliculas peli = listaPeliculas.top(); // Cogemos la pelicula actual.
        hiac = peli.inicio;
        hfac = peli.fin;
        
        listaPeliculas.pop(); // O(log(numero de peliculas))
        
        if (hfa <= hiac-10) // Si el principio de la pelicula actual es posterior al final de la pelicula anterior, caben las dos peliculas.
        {
            numeroPelisVisionables++; // incremento el numero de pelis.
            hia = hiac; // Se cambia el intervalo anterior por el intervalo actual.
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
// O(numero de peliculas*log(numero de peliculas))
bool resuelveCaso()
{
    int nPeliculas;
    
    std::cin >> nPeliculas; // numero de peliculas
    
    if(nPeliculas == 0)
        return false;
    
    PriorityQueue<Peliculas,menorPelis> listaPeliculas(nPeliculas);
    
    
    // O(numero de peliculas * log(numero de peliculas))
    for(int i = 0; i < nPeliculas ; i++)
    {
         // Transformamos las horas y minutos a solo minutos.
        int hh, mm, duracion; char c;
        
        std::cin >> hh >> c >> mm;  // el char lee los dos puntos
        std::cin >> duracion;
        hh = hh*60+mm;
        Peliculas p;
        p.inicio = hh;
        p.fin = hh+duracion;
        listaPeliculas.push(p); // O(log(numero de peliculas))
        
    }
    
    std::cout << resuelve(listaPeliculas) << std::endl;
    
    return true;
    
}

// Metodo principal, contiene un bucle que llama a la funcion resuelveCaso.
// Esta devuelve true mientras haya casos por resolver.
// Coste O(numero de peliculas*log(numero de peliculas)).
int main()
{
    while(resuelveCaso());
    return 0;
}


