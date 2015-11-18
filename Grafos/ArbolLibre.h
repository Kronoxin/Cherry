/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolLibre.h
 * Author: Ruben
 *
 * Created on 16 de noviembre de 2015, 18:19
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
    
    ArbolLibre(const Grafo &g)
    {
        _esCiclico = false;
        _esConexo = dfs(g,0,_esCiclico) == g.V();
        _esLibre = !_esCiclico && _esConexo;
        
    }
    
    bool grafoLibre(){
        return _esLibre;
    }
    
private:
    
    void dfsAux(Grafo const& G, size_t v,std::vector<bool> &marked,size_t &count,size_t p, bool &hayCiclo) 
    {
        if (!hayCiclo)
        {
            ++count;
            //marked.at(v) = true;
            marked[v] = true;
            
            for (auto w : G.adj(v)) 
            {
                
                if (w != p) 
                {
                    //if(!marked.at(w))
                    if(!marked[w])
                        dfsAux(G,w,marked,count,v,hayCiclo);
                    else
                        hayCiclo = true;
                }
            }
        }
    }

    size_t dfs(Grafo const& G, size_t v, bool & esCiclico)
    {
        std::vector<bool> marked(G.V());
      //bool *marked = new bool[G.V()];
        size_t count = 0;
        dfsAux(G,v,marked,count,v,esCiclico);

        return count;

    }
};


#endif /* ARBOLLIBRE_H */

