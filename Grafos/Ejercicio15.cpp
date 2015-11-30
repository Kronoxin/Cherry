//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 15 - Deteccion de manchas negras crecientes.
//
/*
 Resumen de solucion:
 Recibimos una matriz de booleanos donde true indica que hay una mancha.
 Recorremos la matriz y unimos los vertices de los conjuntos disjuntos.
 Coste O((f*c) + inserciones).
 */


#include "Grafo.h"
#include "ManchasCrecientes.h"
 
 // Metodo que se encarga de la resolucion del caso.
// Recoge la entrada del usuario e inicializa las variables.
// Si nos llega un simbolo # se considera una mancha.
// Coste O((f*c) + inserciones).

bool resuelveCaso()
{
    
    unsigned int f, co;
    
    std::cin >> f; // número de filas
    
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    
    std::cin >> co; // número de columnas
    
    Matriz<bool> mapa(f,co);
    
    //Ignoramos el \n
    std::cin.ignore();
    
    std::string linea;
    // Recorremos todos los caracteres.
    // Coste O(numero de caracteres.)
    for(int i = 0; i < f; i++)
    {
        std::getline(std::cin,linea);
        
        for(int j = 0; j < co; j++)
        {
            mapa[i][j] = (linea[j] == '#'); // Si es igual a # se considera una mancha.
        }
    }
    // Coste O(f*c).
    ManchasCrecientes m(mapa,f,co);
    
    unsigned int inserciones;
    
    std::cin >> inserciones;
    // Por cada nueva insercion.
    // Coste O(inserciones)
    for (unsigned int i = 0; i < inserciones; i++)
    {
        int fila,columna;
        std::cin >> fila;
        std::cin >> columna;
        // Coste O(1)
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

// Metodo principal, contiene un bucle que llama a la funcion resuelveCaso.
// Esta devuelve true mientras haya casos por resolver.
// Coste O(f*c).

int main()
{
    while(resuelveCaso());
    return 0;
}