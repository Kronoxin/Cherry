//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 15 - Deteccion de manchas negras crecientes.
//
/*
 Resumen de solucion:
 Recibimos una matriz de booleanos donde true indica que hay una mancha.
 Recorremos la matriz y unimos los vertices de los conjuntos disjuntos.
 Coste O(f*c).
 */


#ifndef ConjuntosDisjuntosMod_h
#define ConjuntosDisjuntosMod_h

#include "ConjuntosDisjuntos.h"

class ConjuntosDisjuntosMod
{
public:
    // crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
    // Coste O(numero de elementos).
    ConjuntosDisjuntosMod(size_t N);
    
    size_t count() const { return _count; }
    
    //  devuelve el identificador del conjunto que contiene a p
    // Coste O(1)
    size_t buscar(size_t p) const;
    
    // unir los conjuntos que contengan a p y q
    // Coste O(numero de elementos)
    void unir(size_t p, size_t q);
    
    // muestra el array por la salida o
    void print(std::ostream& o = std::cout) const;
    
    // devuelve el tamaño de un conjunto(set).
    
    size_t setSize (size_t p)
    {
        if (id[p] < 0)
            return id[p]*-1;
        else
            return id[p];
    }
    
protected:
    size_t size;             // los elementos son 0 .. size-1
    size_t _count;           // número de conjuntos disjuntos
    mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i
    
};
  
#endif /* ConjuntosDisjuntosMod_h */
