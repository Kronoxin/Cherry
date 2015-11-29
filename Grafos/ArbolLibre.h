//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 10 - Árboles libres.
//
/*
 Resumen de solucion:
 Recorremos el grafo realizando una búsqueda en profundidad.
 Vamos contando el numero de nodos por los que pasamos para comprobar que el grafo sea conexo.
 Si algun nodo esta conectado con otro nodo que ya hayamos marcado distinto de su nodo padre el grafo
 es cícliclo.
 
 Coste O(numero de vertices + numero de aristas).
 */

#ifndef ARBOLLIBRE_H
#define ARBOLLIBRE_H

#include "Grafo.h"
#include <vector>

class ArbolLibre{
    
private:
    bool _esLibre;
    bool _esCiclico;
    bool _esConexo;
    
public:
    // Constructor de la clase ArbolLibre, llama al metodo que recorre el grafo y comprueba si es un arbol libre.
    // Coste O(numero de vertices + numero de aristas).
    ArbolLibre(const Grafo &g)
    {
        _esCiclico = false;
        // Coste O(numero de vertices + numero de aristas).
        _esConexo = dfs(g,0,_esCiclico) == g.V();
        // Si el arbol es conexo y no es ciclico, es libre.
        _esLibre = !_esCiclico && _esConexo;
        
    }
    
    bool grafoLibre(){
        return _esLibre;
    }
    
private:
    
    // Metodo que recorre el grafo y nos indica el numero de nodos visitados y si existe un ciclo.
    // Coste O(numero de vertices + numero de aristas).
    void dfsAux(Grafo const& G, size_t v,std::vector<bool> &marked,size_t &count,size_t p, bool &hayCiclo) 
    {
        // Si no hay ciclo seguimos comprobando.
        if (!hayCiclo)
        {
            ++count; // Llevamos la cuenta de los nodos por los que pasamos.
            marked[v] = true;
            
            for (auto w : G.adj(v)) 
            {  
                if (w != p) // Si nuestro destino no es el nodo padre continuamos.
                {
                    if(!marked[w]) // Si no hemos marcado ese nodo seguimos con el recorrido.
                        dfsAux(G,w,marked,count,v,hayCiclo);
                    else // Si nos encontramos un nodo marcado distinto del nodo padre entonces hay un ciclo.
                        hayCiclo = true;
                }
            }
        }
    }
    
    // Metodo que llama a una función auxiliar para recorrer los nodos.
    // Coste O(numero de vertices + numero de aristas).
    size_t dfs(Grafo const& G, size_t v, bool & esCiclico)
    {
        std::vector<bool> marked(G.V());
        size_t count = 0;
        dfsAux(G,v,marked,count,v,esCiclico);

        return count;

    }
};


#endif /* ARBOLLIBRE_H */

