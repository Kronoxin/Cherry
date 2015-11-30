//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 14 - Deteccion de manchas negras.
//
/*
 Resumen de solucion:
 Recibimos una matriz de booleanos donde true indica que hay una mancha.
 Recorremos la matriz desde la posicion 0,0 a la n-1,n-1 y creamos aristas que conectan una mancha con otra mancha a su derecha y debajo suya.
 Recorremos el grafo generado y contamos el numero de manchas que hay en cada componente, si este es mayor al maximo, lo actualizamos. 
 
 Coste O(filas*columnas).
 */

#include "Grafo.h"
#include "Manchas.h"
#include <string.h>

// Metodo que se encarga de la resolucion del caso.
// Recoge la entrada del usuario, inicializa las variables y llama a la funcion que devuelve el mayor numero de manchas.
// Coste O(filas*columnas).

bool resuelveCaso()
{
    unsigned int f, co;
    
    std::cin >> f; // número de filas
    
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    
    std::cin >> co; // número de columnas
    
    Matriz<bool> mapa = Matriz<bool>(f,co);
    //Ignoramos el \n
    std::cin.ignore();
    
    std::string linea;
    // Coste O(filas*columnas).
    for(int i = 0; i < f; i++)
    {
        std::getline(std::cin,linea);
        
        for(int j = 0; j < co; j++)
        {
            mapa[i][j] = (linea[j] == '#'); // mapa[i][j] es true si existe una mancha.
        }
    }
    
    Manchas m(mapa,f,co); // Coste O(filas*columnas).
    std::cout << m.mayorNumeroManchas() << "\n";
    
    return true;
}
// Metodo principal,contiene un bucle que llama a la funcion resuelveCaso.
// resuelveCaso devuelve true siempre que haya otro caso a resolver.
// Coste O(filas*columnas).

int main()
{
    while(resuelveCaso());
    return 0;
}
