//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 4 - Kesimo elemento.
//
/*
 Resumen de solucion:
 Hemos modificado la clase TreeMap_AVL de forma que al insertar un nodo nuevo en la rama izquierda (Siempre y cuando la clave no exista ya) se incrementa la variable tam_i que indica el numero de nodos en la rama izquierda del arbol. Tambien hacemos las modificaciones necesarias  en la variable tam_i cuando se hacen rotaciones y eliminaciones de nodos.
 
 Vamos buscando el kesimo elemento dependiendo del numero de nodos por la rama izquierda que haya. De forma que se busca en tiempo logaritmico.
 
 */

#include <stdio.h>
#include "TreeMap_AVL_Mod.h"
#include <vector>


// Llamamos a una funcion del arbol que hemos modificado para buscar el kesimo nodo del arbol.
// Coste O(Log(numeroDeNodosDelArbol))
void resuelve(TreeMap<int,int> const &arbol, int kesimo)
{
    arbol.buscaKesimo(kesimo);
}

// Por cada numero a comprobar llamamos a la funcion resuelve.
// Coste // Coste O(numeroCasosABuscar * Log(numeroDeNodosDelArbol))
int main()
{
    
    
    int nElementos;
    
    std::cin >> nElementos;
    
    while (nElementos != 0)
    {
        TreeMap<int,int> arbol;
        int elemento;
        
        for (int i =1; i<=nElementos; i++)
        {
            std::cin >> elemento;
            arbol.insert(elemento, i);
        }
        
        int nCasosConsulta;
        std::cin >> nCasosConsulta;
        int dato;
        
        for (int i = 0; i < nCasosConsulta; i++)
        {
            std::cin >> dato;
            resuelve(arbol,dato);
        }
        std::cout << "----" << "\n";
        std::cin >> nElementos;
        
    }
    return 0;
}
