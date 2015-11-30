
//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 2 - ¿Es un arbol AVL?
//
/* Resumen de solucion:
 Usando la misma idea que en el arbol equilibrado, seguimos comprobando si es equilibrado y ademas vamos calculando los maximos
 de los hijos izquierdos y los minimos de los hijos derechos para al subir al nodo padre comprobar que se cumplan los requisitos
 del arbol AVL.
 
 
 */

#include <algorithm>
#include <iostream>

#include "BinTree.h"


// lee un árbol binario de la entrada estándar
BinTree<int> leerArbol() {
    
    int raiz;
    std::cin >> raiz;
    
    if (raiz == -1) { // es un árbol vacío
        return {};
    } else {    // leer recursivamente los hijos
        
        auto iz = leerArbol();
        auto dr = leerArbol();
        return {iz, raiz, dr};
    }
}


// Recorre el arbol y comprueba si esta balanceado, si no lo esta la variable esAVL se vuelve false.
// El arbol es AVL si el maximo de los hijos izquierdos del arbol es menor que la raiz y el minimo de los hijos
// derechos del arbol es mayor que la raiz.

// Coste de la funcion O(n) siendo n el numero de nodos del arbol.


int esAVLAux(BinTree<int> const& arbol,int &maximo, int &minimo, bool &esAVL)
{
    if(arbol.empty())
        // Si el arbol es vacio, la altura es 0.
        return 0;
    
    else
    {
        int nivelIzquierdo, nivelDerecho;
        // Inicializamos asi las variables para que el minimo al comparar en por la rama derecha no sea 0, si no que sea superior al
        // valor del nodo padre, de modo que si hay un numero mas pequeño nos quedaremos con el.
        // Si se inicializara a 0, siempre nos daria que el minimo de la rama derecha es 0, por tanto no seria correcto.
        
        int maxIzquierdo = arbol.root()-1, maxDerecho = arbol.root();
        int minIzquierdo = arbol.root(), minDerecho = arbol.root()+1;
        
        // Si es avl, seguimos iterando por las ramas.
        if(esAVL)
        {
            // Bajamos un nivel.
            nivelIzquierdo = esAVLAux(arbol.left(),maxIzquierdo,minIzquierdo,esAVL);
            nivelDerecho = esAVLAux(arbol.right(),maxDerecho,minDerecho,esAVL);
        
            // Al subir comprobamos que el maximo de la rama izquierda sea menor que nuestra raiz y el minimo por la derecha sea mayor.
            // Tambien comprobamos si es equilibrado el arbol por motivos de eficiencia.
            
            if (!(maxIzquierdo < arbol.root() && minDerecho > arbol.root()) || std::abs(nivelIzquierdo - nivelDerecho)>1)
                esAVL = false;
            
            // Obtenemos el maximo y el minimo de ambas ramas.
            
            maximo = std::max(maxIzquierdo,std::max(maxDerecho,arbol.root()));
            minimo = std::min(minIzquierdo,std::min(minDerecho,arbol.root()));
        }
        
        // Devolvemos la altura del arbol
        return std::max(nivelIzquierdo,nivelDerecho)+1;
        
    }
}

// Dado un arbol, devuelve true o false si es AVL.
// Coste de la funcion O(n) siendo n el numero de nodos del arbol.

bool esAVL(BinTree<int> const& arbol)
{
    bool esAVL = true;
    int min,max;
    
    // Si el arbol no es vacio, comprobamos si es AVL.
    if(!arbol.empty())
    {
        min = arbol.root();
        max = arbol.root();
        esAVLAux(arbol,max,min,esAVL); // Llamada inicial para resolver esAVL.
    }
    
    // Si es vacio, es AVL.
    
    
    return esAVL;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    auto arbol = leerArbol();
    
    if(esAVL(arbol)){
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
