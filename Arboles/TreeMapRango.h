//
//  TreeMapRango.h
//
//  Extensión de tablas <clave, valor> como árboles de búsqueda AVL
//  con una operación para consultar las claves en un rango
//

#ifndef TREEMAPRANGO_H_
#define TREEMAPRANGO_H_

#include <vector>

#include "TreeMap_AVL.h"

template <typename Clave, typename Valor, typename Comparador = std::less<Clave>>
class TreeMapRango : public TreeMap<Clave, Valor, Comparador> {
public:
    
    TreeMapRango(Comparador c = Comparador()) : TreeMap<Clave, Valor, Comparador>(c) {};
    
    std::vector<Clave> rango(Clave const& k1, Clave const& k2) const
    {
        std::vector<Clave> lista;
        rango(k1, k2, this->raiz, lista);
        return lista;
    }
    
protected:
    using TreeNode = typename TreeMap<Clave, Valor, Comparador>::TreeNode;
    using Link = TreeNode *;
    
    void rango(Clave const& k1, Clave const& k2, Link a, std::vector<Clave> & lista) const
    {
        // Si el arbol no es vacio.
        if (a != NULL)
        {
            // Si mi clave es mayor que el minimo, voy por la rama izquierda.
            if (!this->menor(a->cv.clave, k1))
                rango(k1, k2, a->iz, lista);
            
            // Si mi clave esta dentro del rango entre k1 y k2, la agrego.
            if (!this->menor(a->cv.clave, k1) && !this->menor(k2,a->cv.clave))
                lista.push_back(a->cv.clave);
            // Si mi clave es menor que el maximo k2 voy por la rama derecha.
            if (!this->menor(k2, a->cv.clave))
                rango(k1, k2, a->dr, lista);
            
            
        }
        
    }
    
    
};



#endif /* TREEMAPRANGO_H_ */
