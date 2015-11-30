//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 15 - Deteccion de manchas negras crecientes.
//
/*
 Resumen de solucion:
 Recibimos una matriz de booleanos donde true indica que hay una mancha.
 Recorremos la matriz y unimos los vertices de los conjuntos disjuntos.
 Coste O((f*c)^2).
 */

#ifndef MANCHASCRECIENTES_H
#define MANCHASCRECIENTES_H

#include "Grafo.h"
#include "Matriz.h"
#include "ConjuntosDisjuntosMod.h"

class ManchasCrecientes
{
    
private:
    
    unsigned int _mayorNumeroManchas;
    
    Matriz<bool> _mapa = Matriz<bool>(1,1);
    unsigned int _filas;
    unsigned int _columnas;
    
    ConjuntosDisjuntosMod _conjuntos = ConjuntosDisjuntosMod(1);
    
    
public:
    // Constructor de la clase ManchasCrecientes.
    // Genera conjuntos disjuntos en base a la matriz de booleanos que recibe.
    // Identifica el mayor numero de manchas pertenecientes a una sola componente conexa.
    // Coste O((f*c)^2)
    
    ManchasCrecientes(const Matriz<bool> &m, unsigned int f, unsigned int c)
    {
        _mapa = m;
        _filas = f;
        _columnas = c;

        _mayorNumeroManchas = 0;

        // Coste O(f*c).
        _conjuntos = ConjuntosDisjuntosMod(f*c);
       
        generaGrafoDeMapa(); // Genera conjuntos disjuntos en base al mapa de booleanos de manchas. Coste O((f*c)^2).
        cuentaManchas(); // Cuenta el numero de manchas. Coste O(f*c).
        
    }
    
    unsigned int mayorNumeroManchas()
    {
        return _mayorNumeroManchas;
    }
    // Inserta la nueva mancha y une los conjuntos que queden conectados con ella.
    // Coste O(f*c)
      
    void actualizarManchas(int i,int j)
    {
        
        // Si no hay una mancha en esa posicion ya.
        if (!_mapa[i][j])
        {
            _mapa[i][j] = true;
            
            // Comprobamos que la casilla derecha existe y es negra y la agregamos al grafo.
            if (j+1 < _columnas) // Si no nos pasamos.
                if (_mapa[i][j+1]) // Si la de la derecha es negra.
                    _conjuntos.unir((i*_columnas)+j,(i*_columnas)+j+1);
            
            
            // Comprobamos que la casilla de abajo existe y es negra y la agregamos al grafo.
            if (i+1 < _filas) // Si no nos pasamos.
                if (_mapa[i+1][j]) // Si la de abajp es negra.
                    _conjuntos.unir((i*_columnas)+j,((i+1)*_columnas)+j);
            
            // Comprobamos que la casilla izquierda existe y es negra y la agregamos al grafo.
            if ((j-1) >= 0) // Si no nos pasamos.
                if (_mapa[i][j-1]) // Si la de la izquierda es negra.
                    _conjuntos.unir((i*_columnas)+j,(i*_columnas)+j-1);
            
            // Comprobamos que la casilla de arriba existe y es negra y la agregamos al grafo.
            if ((i-1) >= 0) // Si no nos pasamos.
                if (_mapa[i-1][j]) // Si la de arriba es negra.
                    _conjuntos.unir((i*_columnas)+j,((i-1)*_columnas)+j);

     
     
            int count = _conjuntos.setSize(_conjuntos.buscar((i*_columnas)+j));
            if (count > _mayorNumeroManchas)
                _mayorNumeroManchas = count;
        }
        
    }
    
private:
    // Genera los conjuntos disjuntos. Coste O((f*c)^2).
    void generaGrafoDeMapa()
    {
        
        for(int i = 0; i < _filas; i++)
        {
            for(int j = 0; j < _columnas; j++)
            {
                if (_mapa[i][j]) // Si la casilla actual es negra.
                {
                    // Comprobamos que la casilla derecha existe y es negra y la agregamos al grafo.
                    if (j+1 < _columnas) // Si no nos pasamos.
                        if (_mapa[i][j+1]) // Si la de la derecha es negra.
                            _conjuntos.unir((i*_columnas)+j,(i*_columnas)+j+1);
                    
                    // Comprobamos que la casilla de abajo existe y es negra y la agregamos al grafo.
                    if (i+1 < _filas) // Si no nos pasamos.
                        if (_mapa[i+1][j]) // Si la de abajp es negra.
                            _conjuntos.unir((i*_columnas)+j,((i+1)*_columnas)+j);
                    
                }
            }
        }
    }
    
    // Cuenta el mayor numero de manchas y actualiza cual es el mayor.
    // Coste O(f*c).
    void cuentaManchas()
    {
        
        for (unsigned int i = 0; i < _filas*_columnas; i++)
        {
            if (_mapa[i/_columnas][i%_columnas])
            {
                size_t count = 0;
                
                count = _conjuntos.setSize(_conjuntos.buscar(i));
                
                if (count > _mayorNumeroManchas)
                {
                    _mayorNumeroManchas = count;
                }
            }
        }
    }
};






#endif /* MANCHASCRECIENTES_H */

