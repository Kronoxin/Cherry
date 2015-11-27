//
//  ConjuntosDisjuntosMod.h
//  Ejercicio1
//
//  Created by Rubén Gómez on 27/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//


#ifndef ConjuntosDisjuntosMod_h
#define ConjuntosDisjuntosMod_h

#include "ConjuntosDisjuntos.h"

class ConjuntosDisjuntosMod
{
public:
    // crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
    ConjuntosDisjuntosMod(size_t N);
    
    size_t count() const { return _count; }
    
    //  devuelve el identificador del conjunto que contiene a p
    size_t buscar(size_t p) const;
    
    // unir los conjuntos que contengan a p y q
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
