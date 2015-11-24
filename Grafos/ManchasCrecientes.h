/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ManchasCrecientes.h
 * Author: Ruben
 *
 * Created on 23 de noviembre de 2015, 14:58
 */

#ifndef MANCHASCRECIENTES_H
#define MANCHASCRECIENTES_H

#include "Grafo.h"
#include "Matriz.h"

class ManchasCrecientes
{
    
private:
    
    unsigned int _nComponentesConexas;
    unsigned int _mayorNumeroManchas;
    std::vector<unsigned int> _numeroManchasPorComponente;
    Matriz<bool> _mapa = Matriz<bool>(1,1);
    unsigned int _filas;
    unsigned int _columnas;
    Grafo _g=Grafo(1);

    
public:
    
    ManchasCrecientes(const Matriz<bool> &m, unsigned int f, unsigned int c)
    {
        _mapa = m;
        _filas = f;
        _columnas = c;
        
        _nComponentesConexas = 0;
        _mayorNumeroManchas = 0;
        
        _numeroManchasPorComponente = std::vector<unsigned int> (f*c);
        
        _g = generaGrafoDeMapa();
        cuentaManchas();
    }
    
    unsigned int mayorNumeroManchas()
    {
        return _mayorNumeroManchas;
    }
    
    void actualizarManchas(int i,int j)
    {
        // Si no hay una mancha en esa posicion ya.
        if (!_mapa[i][j])
        {
            _mapa[i][j] = true;
             // Comprobamos que la casilla derecha existe y es negra y la agregamos al grafo.
            if (j+1 < _columnas) // Si no nos pasamos.
                if (_mapa[i][j+1]) // Si la de la derecha es negra.
                    _g.ponArista((i*_columnas)+j,(i*_columnas)+j+1);

            // Comprobamos que la casilla de abajo existe y es negra y la agregamos al grafo.
            if (i+1 < _filas) // Si no nos pasamos.
                if (_mapa[i+1][j]) // Si la de abajp es negra.
                    _g.ponArista((i*_columnas)+j,((i+1)*_columnas)+j);

            // Comprobamos que la casilla izquierda existe y es negra y la agregamos al grafo.
            if ((j-1) >= 0) // Si no nos pasamos.
                if (_mapa[i][j-1]) // Si la de la izquierda es negra.
                    _g.ponArista((i*_columnas)+j,(i*_columnas)+j-1);

            // Comprobamos que la casilla de arriba existe y es negra y la agregamos al grafo.
            if ((i-1) >= 0) // Si no nos pasamos.
                if (_mapa[i-1][j]) // Si la de arriba es negra.
                    _g.ponArista((i*_columnas)+j,((i-1)*_columnas)+j);
                    
             size_t count = 0;
             std::vector<bool> marked(_g.V());
             dfsAux(_g,(i*_columnas)+j,marked,count);
             _numeroManchasPorComponente.at(_nComponentesConexas) = count;
                
             if (count > _mayorNumeroManchas)
                _mayorNumeroManchas = count;       
        }
    }
private:
    
    Grafo generaGrafoDeMapa()
    {
        Grafo g = Grafo(_filas*_columnas);
             
        for(int i = 0; i < _filas; i++)
        {
            for(int j = 0; j < _columnas; j++)
            {
                if (_mapa[i][j]) // Si la casilla actual es negra.
                {
                    // Comprobamos que la casilla derecha existe y es negra y la agregamos al grafo.
                    if (j+1 < _columnas) // Si no nos pasamos.
                        if (_mapa[i][j+1]) // Si la de la derecha es negra.
                            g.ponArista((i*_columnas)+j,(i*_columnas)+j+1);
                    
                    // Comprobamos que la casilla de abajo existe y es negra y la agregamos al grafo.
                    if (i+1 < _filas) // Si no nos pasamos.
                        if (_mapa[i+1][j]) // Si la de abajp es negra.
                            g.ponArista((i*_columnas)+j,((i+1)*_columnas)+j);
                   
                }
            }
        }
        return g;
    }
    void dfsAux(Grafo const& G, size_t v,std::vector<bool> &marked,size_t &count) 
    {

            ++count;
            marked[v] = true;
            
            for (auto w : G.adj(v)) 
            {
                if(!marked[w])
                    dfsAux(G,w,marked,count);
          
            }
    }
        
    

    void cuentaManchas()
    {
        std::vector<bool> marked(_g.V());
        
        for (unsigned int i = 0; i < _g.V(); i++)
        {
            if (!marked[i] && _mapa[i/_columnas][i%_columnas])
            {
                size_t count = 0;
                dfsAux(_g,i,marked,count);
                _numeroManchasPorComponente.at(_nComponentesConexas) = count;
                
                if (count > _mayorNumeroManchas)
                    _mayorNumeroManchas = count;
               
            }
        }
    }
};






#endif /* MANCHASCRECIENTES_H */

