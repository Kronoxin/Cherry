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
#include "../TADS/HashMap.h"

class ArbolBipartito
{
    
private:
    bool _esBipartito;
    
public:
    
    ArbolBipartito(const Grafo &g)
    {
        _esBipartito = dfs(g);
        
    }
    
    bool grafoBipartito()
    {
        return _esBipartito;
    }
    
private:
    
    void dfsAux(Grafo const& G, int v,std::vector<bool> &marked,bool soyRojo,std::vector<bool> &color,bool &soyBipartito, HashMap<int,int> &nodos)
    {
        if (soyBipartito)
        {
            marked[v] = true;
            color[v] = soyRojo;
            nodos.erase(v);
           
            for (auto w : G.adj(v))
            {
                if(!marked[w])
                    dfsAux(G,w,marked,!soyRojo,color,soyBipartito,nodos);
                else if(color[w] == soyRojo)
                    soyBipartito = false;
                
            }
        }
    }
    
    bool dfs(Grafo const& G)
    {
        bool correcto = true;
        HashMap<int, int> nodos;
        
        for (int i = 0; i < G.V(); i++)
        {
            nodos.insert(i,i);
        }
        
        while(!nodos.empty())
        {
            std::vector<bool> marked(G.V());
            std::vector<bool> color(G.V());
            bool soyBipartito = true;
            int nodo = (nodos.begin()).key();
            dfsAux(G,nodo,marked,true,color,soyBipartito,nodos);
            correcto &= soyBipartito;
            
        }
        
        return correcto;
        
    }
    
};


#endif /* ARBOLBIPARTITO_H */

