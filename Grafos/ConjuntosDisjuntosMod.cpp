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

#include "ConjuntosDisjuntosMod.h"

ConjuntosDisjuntosMod::ConjuntosDisjuntosMod(size_t N) : size(N), _count(size), id(size, -1) {}
// Coste O(1).
size_t ConjuntosDisjuntosMod::buscar(size_t p) const {
    if (id[p] < 0) // es una raíz
        return p;
    else
        return id[p] = int(buscar(id[p]));
}

// unir los conjuntos que contengan a p y q
// Coste O(1).
void ConjuntosDisjuntosMod::unir(size_t p, size_t q) {
    auto i = buscar(p);
    auto j = buscar(q);
    if (i == j) return;
    if (id[i] < id[j]) { // i es la raíz del mayor árbol
        id[i] += id[j]; id[j] = int(i);
    } else {
        id[j] += id[i]; id[i] = int(j);
    }
    _count--;
}

// muestra el array por la salida o
void ConjuntosDisjuntosMod::print(std::ostream& o) const {
    o << _count << ": ";
    for (auto i = 0; i < size; ++i)
        o << id[i] << " ";
}


std::ostream& operator<<(std::ostream & o, ConjuntosDisjuntosMod const& a){
    a.print(o);
    return o;
}
