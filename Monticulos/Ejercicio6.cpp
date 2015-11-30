//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio6 - ¿Es un monticulo?
//
/*  Resumen de solucion:
    Recorremos todos los nodos y nos vamos quedando con la altura de cada rama.
    Al volver al padre comparamos las alturas del hijo izquierdo y el derecho y confirmamos que la diferencia sea menor o igual a 1
    Tambien comprobamos que el padre sea mayor que sus hijos y que si el hijo izquierdo existe el hijo derecho tambien debe existir.
    
    O(numero de nodos del arbol).
 */

#include <algorithm>
#include <iostream>

#include "BinTree.h"


// Lee un árbol binario de la entrada estándar
// O(numero de nodos del arbol * log numero de nodos en el arbol en cada iteracion).
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
// Funcion que devuelve true si un arbol es hoja y false en caso contrario.
// O(1).
bool esHoja(BinTree<int> const& arbol){
    // Un arbol es hoja si no es vacio y no tiene hijo derecho ni izquierdo
    return !arbol.empty() && arbol.left().empty() && arbol.right().empty();
}

// Funcion auxiliar que recorre el arbol y nos devuelve si es completo, semicompleto y minimo.
// O(numero de nodos del arbol).
void esMonticuloAux(BinTree<int> const &arbol,bool &esCompleto,bool &esSemi, bool &esMin, unsigned int &profundidad)
{
    
    // Si es vacio o es hoja, es completo
    if (arbol.empty())
    {
        esCompleto = true;
        esSemi = true;
        esMin = true;
        profundidad = 0;
    }
    else
    {
        bool esCompletoIzquierda, esCompletoDerecha, esSemiIzquierda, esSemiDerecha, esMinIzquierda, esMinDerecha;
        unsigned int pIzquierda, pDerecha;
        
		// Recorremos las ramas izquierda y derecha.
        esMonticuloAux(arbol.left(),esCompletoIzquierda,esSemiIzquierda,esMinIzquierda,pIzquierda);
        esMonticuloAux(arbol.right(),esCompletoDerecha,esSemiDerecha,esMinDerecha,pDerecha);
        
		// Si el arbol es hoja, es minimo.
        if (esHoja(arbol))
            esMin = true;

        // Si tiene hijo izquierdo.
        else if (!arbol.left().empty())
        {
			// Es minimo si la raiz del hijo izquierdo es menor o igual que la raiz del arbol.
            esMin = arbol.left().root() >= arbol.root();
            // Tambien tiene que cumplir que si tiene hijo derecho este debe ser menor que la raiz del arbol
            if (!arbol.right().empty())
                esMin = esMin && (arbol.right().root() >= arbol.root());
        }
		// Si no lo tiene
        else
			// El hijo derecho debe ser menor que el padre.
            esMin = arbol.right().root() >= arbol.root();
        
        
        // Es minimo si es minima la raiz y lo son las ramas izquierdas y derechas.
        esMin = esMin && esMinIzquierda && esMinDerecha;
			// Si es completo por la izquierda y por la derecha.
            if (esCompletoIzquierda && esCompletoDerecha)
            {
				// Si estan a la misma altura, es completo y es semiCompleto.
                if (pIzquierda == pDerecha)
                {
                    esCompleto = true;
                    esSemi = true;
                    profundidad = pIzquierda +1;
                }
				// Si la rama izquierda tiene mas altura que la derecha entonces no es completo pero puede ser semicompleto.
                else if(pIzquierda == pDerecha +1)
                {
                    esCompleto = false;
                    esSemi = true;
                    profundidad = pIzquierda +1;
                    
                }
				// Si no, ni es completo ni es semicompleto.
                else{
                    esCompleto = false;
                    esSemi = false;
                    profundidad = std::max(pIzquierda,pDerecha)+1;
                }
            }
			// Si es completo por la izqueirda y es semicompleto por la derecha y estan a la misma altura sigue siendo semicompleto.
            else if (esCompletoIzquierda && esSemiDerecha && pIzquierda == pDerecha)
            {
                esCompleto = false;
                esSemi = true;
                profundidad = pIzquierda +1;
            }
			// Si es completo por la derecha y semicompleto por la izquierda y la altura de la rama izquierda es mayor que la de la rama derecha sigue siendo semicompleto.
            else if (esSemiIzquierda && esCompletoDerecha && pIzquierda == pDerecha+1)
            {
                esCompleto = false;
                esSemi = true;
                profundidad = pIzquierda +1;
            }
            // Si no, ni es completo ni semicompleto.
            else
            {
                esCompleto = false;
                esSemi = false;
                profundidad = std::max(pIzquierda,pDerecha)+1;
            }
        
    }
}
// Funcion que devuelve si es un monticulo de minimos.
// O(numero de nodos del arbol).
bool esMonticulo (BinTree<int> const &arbol)
{
    bool esCompleto = true;
    bool esSemi = true;
    bool esMin= true;;
    unsigned int profundidad = 0;
	// LLamamos a una funcion auxiliar que recorre el arbol y nos devuelve si es completo, semicompleto y minimo.
    esMonticuloAux(arbol, esCompleto,esSemi, esMin, profundidad);
    
    return esSemi && esMin;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
// O(numero de nodos del arbol * log numero de nodos en el arbol en cada iteracion).
void resuelveCaso() 
{
    auto arbol = leerArbol();
    
    if(esMonticulo(arbol)){
        std::cout << "SI\n" ;
    }else{
        std::cout << "NO\n";
    }
}

//Funcion que pide los valores de entrada y resuelve los casos.
// O(numero de casos * numero de nodos del arbol * log numero de nodos en el arbol en cada iteracion).
int main() {
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}
