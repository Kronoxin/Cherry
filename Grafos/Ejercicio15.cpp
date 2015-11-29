//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 15 - Deteccion de manchas negras crecientes.
//
/*
 Resumen de solucion:
 Recibimos una matriz de booleanos donde true indica que hay una mancha.
 Recorremos la matriz desde la posicion 0,0 a la n-1,n-1 y creamos aristas que conectan una mancha con otra mancha a su derecha y debajo suya.
 Recorremos el grafo generado y contamos el numero de manchas que hay en cada componente, si este es mayor al maximo, lo actualizamos. 
 
 Coste O(filas*columnas).
 */

#include "Grafo.h"
#include "ManchasCrecientes.h"
 
 //Conjuntos disjuntos

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
    for(int i = 0; i < f; i++)
    {
        std::getline(std::cin,linea);
        
        for(int j = 0; j < co; j++)
        {
            mapa[i][j] = (linea[j] == '#');
        }
    }
    
    ManchasCrecientes m = ManchasCrecientes(mapa,f,co);
    
    unsigned int inserciones;
    
    std::cin >> inserciones;
    for (unsigned int i = 0; i < inserciones; i++)
    {
        int fila,columna;
        std::cin >> fila;
        std::cin >> columna;
        m.actualizarManchas(fila-1,columna-1);
        
        std::cout << m.mayorNumeroManchas();
        
        if (i < inserciones - 1)
            std::cout << " ";
        else
           std::cout << "\n";
    }
    
    if (inserciones == 0)
        std::cout << "\n";
    
    
    
    
    return true;
}
int main()
{
    while(resuelveCaso());
    return 0;
}