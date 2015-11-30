//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio1 - ¿Está el árbol equilibrado?
//
/*  Resumen de solucion:
    Recorremos todos los nodos y nos vamos quedando con la altura de cada rama.
    Al volver al padre comparamos las alturas del hijo izquierdo y el derecho y confirmamos que la diferencia sea menor o igual a 1
    En caso contrario la variable booleana se establece a falsa debido a que el arbol no es balanceado.
 
 */

#include <algorithm>
#include <iostream>

#include "BinTree.h"


// lee un árbol binario de la entrada estándar
BinTree<char> leerArbol() {
    
    char raiz;
    std::cin >> raiz;
    
    if (raiz == '.') { // es un árbol vacío
        return {};
    } else {    // leer recursivamente los hijos
        
        auto iz = leerArbol();
        auto dr = leerArbol();
        return {iz, raiz, dr};
    }
}

// Recorre el arbol y comprueba si esta balanceado, si no lo esta la variable esEquilibrado se vuelve false.
// Coste de la funcion O(n) siendo n el numero de nodos del arbol.

unsigned int equilibradoAux(BinTree<char> const& arbol, bool &esEquilibrado)
{
    if (!arbol.empty() && esEquilibrado)
    {
        unsigned int alturaIzquierda, alturaDerecha;
        
        alturaIzquierda = equilibradoAux(arbol.left(), esEquilibrado);
        alturaDerecha = equilibradoAux(arbol.right(), esEquilibrado);
        
        if (abs(alturaIzquierda-alturaDerecha) > 1)
            esEquilibrado = false;
        
        
        return std::max(alturaIzquierda,alturaDerecha)+1;
    }
    
    else
        return 0;
}
// Dado un arbol, devuelve true o false si está o no equilibrado
// Coste de la funcion O(n) siendo n el numero de nodos del arbol.

bool equilibrado(BinTree<char> const& arbol)
{
    bool correcto = true;
    
    equilibradoAux(arbol,correcto);
    
    return correcto;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    auto arbol = leerArbol();
    
    if(equilibrado(arbol)){
        std::cout << "SI\n" ;
    }else{
        std::cout << "NO\n";
    }
}



int main() {
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}
