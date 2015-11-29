//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 12 - Arborescencias.
//
/*
 Resumen de solucion:
 Para encontrar la raiz damos la vuelta a las aristas del grafo, de forma que si existe una raiz esta sera alcanzable desde
 cualquier nodo y su numero de adyacentes en el grafo inverso sera 0.
 Una vez encontrada la raiz hacemos dfs para comprobar que sea conexo y que exista un solo camino para llegar a cada uno de los nodos.
 Es arborescencia si tiene una raiz y desde ella podemos acceder a todos los nodos de una unica forma.
 
 Coste O(numero de vertices + numero de aristas).
 */

#ifndef ARBORESCENCIA_H
#define ARBORESCENCIA_H


#include "GrafoDirigido.h"
#include <vector>

class Arborescencia
{
    
private:
    bool _esLibre;
    bool _esCiclico;
    bool _esConexo;
    
    bool _esArborescencia;
    int _raiz;
    
public:
    // Constructor de la clase Arborescencia.
    // Busca una raiz en el grafo y si la encuentra comprueba que sea conexo y no ciclico.
    // Coste O(numero de vertices + numero de aristas).
    
    Arborescencia(const GrafoDirigido &g)
    {
        _raiz = -1;
        buscaRaiz(g,_raiz); // Buscamos la raiz.
        
        _esArborescencia = false;
        _esCiclico = false;
        
        
        if(_raiz >= 0) // Si la raiz es mayor o igual que cero la raiz existe.
        {
            int count = dfs(g,_raiz,_esCiclico); // comprobamos que sea ciclico y conexo.
            _esArborescencia = !_esCiclico && count == g.V(); // Es arborescencia si es conexo y no es ciclico.
        }
        
    }
    
    bool grafoArborescente(){
        return _esArborescencia;
    }
    
    int raiz()
    {
        return _raiz;
    }
    
private:
    // Metodo que recorre el grafo y nos indica si existe un nodo por el cual podamos ir por mas de un camino y el numero de nodos por los que hemos pasado.
    // Coste O(numero de vertices + numero de aristas).
    void dfsAux(GrafoDirigido const& G, size_t v,std::vector<bool> &marked, bool &hayCiclo,int &count)
    {
        if (!hayCiclo)
        {
            marked[v] = true;
            count++;
            
            for (auto w : G.adj(v))
            {
                
                    if(!marked[w])
                        dfsAux(G,w,marked,hayCiclo,count);
                    else
                        hayCiclo = true;
            }
        }
    }
    
    // Metodo que llama a una función auxiliar para recorrer los nodos.
    // Coste O(numero de vertices + numero de aristas).
    int dfs(GrafoDirigido const& G, size_t v, bool & esCiclico)
    {
        std::vector<bool> marked(G.V(),false);
        int count = 0;
        dfsAux(G,v,marked,esCiclico, count);
        return count;
        
    }
    // Metodo que recorre el grafo y nos indica si existe una raiz y cual es.
    // Si no existe la raiz su valor es -1.
    // Coste O(numero de vertices + numero de aristas).
    void buscaRaizAux(const GrafoDirigido &g,size_t v, int &raiz, std::vector<bool> & marked)
    {
        marked[v] = true;
        if ((g.adj(v).size() == 0)) // Si el numero de adyacentes del vertice actual es 0, entonces es raiz.
            raiz = v;
        else
        {
            for (auto w : g.adj(v)) // Recorremos los adyacentes de v.
            {
                if(!marked[w]) // Si no los hemos visitado ya entramos en la funcion recursiva con el nodo adyacente.
                    buscaRaizAux(g,w,raiz,marked);
                
            }
        }
    }
    // Metodo que recibe el grafo dirigido y busca la raiz en el grafo inverso.
    // Coste O(numero de vertices + numero de aristas).
    
    void buscaRaiz(const GrafoDirigido &g, int &raiz)
    {
        std::vector<bool> marked(g.V());
        buscaRaizAux(g.reverse(),0,raiz,marked);
    }
     
    
};




#endif /* ARBORESCENCIA_H */

