//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 11 - Grafo Bipartito.
//
/*
 Resumen de solucion:
 Recorremos el árbol realizando una búsqueda en profundidad.
 Segun pasamos por cada nodo le ponemos un color distinto al color del nodo del que venimos.
 Si nos encontramos un nodo que ya esta coloreado y es igual al color de nuestro nodo actual, el grafo no es bipartito.
 
 Coste O(numero de vertices + numero de aristas).
 */

#ifndef ARBOLBIPARTITO_H
#define ARBOLBIPARTITO_H

#include "Grafo.h"
#include <vector>

class ArbolBipartito
{
    
private:
    bool _esBipartito;
    
public:
    // Constructor de la clase ArbolBipartito que recibe un grafo y nos indica si es bipartito.
    // Coste O(numero de vertices + numero de aristas).
    ArbolBipartito(const Grafo &g)
    {
        _esBipartito = dfs(g);
        
    }
    
    bool grafoBipartito()
    {
        return _esBipartito;
    }
    
private:
    
    // Metodo que recorre el arbol y nos indica si el arbol es bipartito.
    // Coste O(numero de vertices + numero de aristas).
    void dfsAux(Grafo const& G, int v,std::vector<bool> &marked,bool soyRojo,std::vector<bool> &color,bool &soyBipartito)
    {
        if (soyBipartito) // Si soy bipartito continuo.
        {
            marked[v] = true; // Marco que he pasado por esta casilla.
            color[v] = soyRojo; // Establezco el color para esta casilla.
           
            for (auto w : G.adj(v)) // Por cada uno de los adyacentes de mi nodo actual-
            {
                if(!marked[w]) // Si el nodo no ha sido recorrido ya.
                    dfsAux(G,w,marked,!soyRojo,color,soyBipartito); // Llamamos recursivamente a la funcion para que lo recorra y establecemos otro color.
                else if(color[w] == soyRojo) // Si el nodo ha sido recorrido ya y su color es el mismo que el mio.
                    soyBipartito = false; // No es bipartito.
                
            }
        }
    }
    
    // Metodo que llama a una función auxiliar para recorrer los nodos.
    // Coste O(numero de vertices + numero de aristas).
    
    bool dfs(Grafo const& G)
    {
        bool correcto = true;
        int i = 0;
        std::vector<bool> marked(G.V(),false); // Vector que indica si he pasado por el vertice x o no.
        std::vector<bool> color(G.V(),false); // Vector que indicar el color de cada uno de los vertices.   
        
        // Recorro todos los nodos del arbol, puede haber componentes inconexas y debemos comprobar si estas son bipartitas tambien.
        while(i != G.V()-1)
        {
            if (!marked[i]) // Si no he recorrido este nodo en alguna busqueda.
            {    
                bool soyBipartito = true;
                dfsAux(G,i,marked,true,color,soyBipartito);
                correcto &= soyBipartito; // Correcto termina siendo true si todas las componentes conexas del grafo son bipartitas.
            }
            i++;
            
        }
        
        return correcto;
        
    }
    
};


#endif /* ARBOLBIPARTITO_H */

