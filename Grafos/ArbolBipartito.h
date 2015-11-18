/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolBipartito.h
 * Author: Ruben
 *
 * Created on 18 de noviembre de 2015, 9:55
 */

#ifndef ARBOLBIPARTITO_H
#define ARBOLBIPARTITO_H

#include "Grafo.h"
#include <vector>

class ArbolBipartito{
    
private:
    bool _esBipartito;
    
public:
    
    ArbolBipartito(const Grafo &g)
    {
        _esBipartito = dfs(g,g.V());
        
    }
    
    bool grafoBipartito()
    {
        return _esBipartito;
    }
    
private:
    
    void dfsAux(Grafo const& G, size_t v,std::vector<bool> &marked,size_t &count,bool soyRojo,std::vector<bool> &color,bool &soyBipartito) 
    {
        if (!soyBipartito)
        {
            ++count;
            marked[v] = true;
            color[v] = soyRojo;
            
            for (auto w : G.adj(v)) 
            {                
                    if(!marked[w])
                        dfsAux(G,w,marked,count,!soyRojo,color,soyBipartito);
                    else if(color[w] == soyRojo)
                        soyBipartito = false;
                
            }
        }
    }

    bool dfs(Grafo const& G, size_t v)
    {
        std::vector<bool> marked(G.V());
        std::vector<bool> color(G.V());
        bool soyBipartito = true;
      //bool *marked = new bool[G.V()];
        size_t count = 0;
        dfsAux(G,v,marked,count,true,color,soyBipartito);

        return soyBipartito;

    }
};


#endif /* ARBOLBIPARTITO_H */

