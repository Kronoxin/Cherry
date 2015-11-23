/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arborescencia.h
 * Author: Ruben
 *
 * Created on 18 de noviembre de 2015, 12:32
 */

#ifndef ARBORESCENCIA_H
#define ARBORESCENCIA_H


#include "GrafoDirigido.h"
#include <vector>

class Arborescencia{
    
private:
    bool _esLibre;
    bool _esCiclico;
    bool _esConexo;
    
    bool _esArborescencia;
    int _raiz;
    
public:
    
    Arborescencia(const GrafoDirigido &g){
        _raiz = -1;
        buscaRaiz(g,_raiz);
        
        _esArborescencia = false;
        _esCiclico = false;
        
        
        if(_raiz >= 0)
        {
            int count = dfs(g,_raiz,_esCiclico);
            _esArborescencia = !_esCiclico && count == g.V();
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
    
    void dfsAux(GrafoDirigido const& G, size_t v,std::vector<bool> &marked,size_t p, bool &hayCiclo)
    {
        if (!hayCiclo)
        {
            marked[v] = true;
            
            for (auto w : G.adj(v))
            {
                
                    if(!marked[w])
                        dfsAux(G,w,marked,count,v,hayCiclo);
                    else
                        hayCiclo = true;
            }
    }
    
    
    void dfs(GrafoDirigido const& G, size_t v, bool & esCiclico)
    {
        std::vector<bool> marked(G.V());
        dfsAux(G,v,marked,v,esCiclico);
        
    }
    
    void buscaRaizAux(const GrafoDirigido &g,size_t v, int &raiz, std::vector<bool> & marked)
    {
        marked[v] = true;
        if ((g.adj(v).size() == 0))
            raiz = v;
        else
        {
            for (auto w : g.adj(v))
            {
                if(!marked[w])
                    buscaRaizAux(g,w,raiz,marked);
                
            }
        }
    }
    
    void buscaRaiz(const GrafoDirigido &g, int &raiz)
    {
        std::vector<bool> marked(g.V());
        buscaRaizAux(g.reverse(),0,raiz,marked);
    }
    
    
    
};




#endif /* ARBORESCENCIA_H */

