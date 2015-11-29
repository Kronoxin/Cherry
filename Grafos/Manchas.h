//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 14 - Deteccion de manchas negras.
//
/*
 Resumen de solucion:
 Recibimos una matriz de booleanos donde true indica que hay una mancha.
 Recorremos la matriz desde la posicion 0,0 a la n-1,n-1 y creamos aristas que conectan una mancha con otra mancha a su derecha y debajo suya.
 Recorremos el grafo generado y contamos el numero de manchas que hay en cada componente, si este es mayor al maximo, lo actualizamos. 
 
 Coste O(filas*columnas).
 */


#ifndef MANCHAS_H
#define MANCHAS_H

#include "Grafo.h"
#include "Matriz.h"

class Manchas
{
    
private:
    
    unsigned int _nComponentesConexas;
    unsigned int _mayorNumeroManchas;
    std::vector<unsigned int> _numeroManchasPorComponente;

    
public:
    // Constructor de la clase Manchas.
    // Crea un grafo a partir de la matriz de manchas y cuenta el numero de manchas que hay en cada componente.
    // Indica cual es mayor numero de manchas, pertenecientes a la misma componente conexa, del grafo.
    // Coste O(filas*columnas + filas*columnas) ==> Coste O(2(filas*columnas)) ==> Coste O(filas*columnas).
    Manchas(const Matriz<bool> &m, unsigned int f, unsigned int c)
    {
        _nComponentesConexas = 0;
        _mayorNumeroManchas = 0;
        
        _numeroManchasPorComponente = std::vector<unsigned int> (f*c);
        // Generamos el grafo en base al mapa.
        Grafo g = generaGrafoDeMapa(m,f,c);
        // Contamos las manchas del grafo y obtenemos el mayor numero de manchas.
        cuentaManchas(g,m,c);
    }
    
    unsigned int mayorNumeroManchas()
    {
        return _mayorNumeroManchas;
    }
private:
    // Metodo que devuelve un grafo generado en base a la matriz de booleanos con las manchas.
    // Coste O(filas*columnas)
    Grafo generaGrafoDeMapa(const Matriz<bool> &m, unsigned int f, unsigned int c)
    {
        Grafo g = Grafo(f*c);
             
        for(int i = 0; i < f; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if (m[i][j]) // Si la casilla actual es negra.
                {
                    // Comprobamos que la casilla derecha existe y es negra y la agregamos al grafo.
                    if (j+1 < c) // Si no nos pasamos.
                        if (m[i][j+1]) // Si la de la derecha es negra.
                            g.ponArista((i*c)+j,(i*c)+j+1);
                    
                    // Comprobamos que la casilla de abajo existe y es negra y la agregamos al grafo.
                    if (i+1 < f) // Si no nos pasamos.
                        if (m[i+1][j]) // Si la de abajo es negra.
                            g.ponArista((i*c)+j,((i+1)*c)+j);
                   
                }
            }
        }
        return g;
    }
    // Metodo que recorre el grafo y cuenta el numero de vertices que se visitan.
    // Coste O(numero de vertices + numero de aristas)
    
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
        
    // Metodo que cuenta cuantas manchas hay y modifica el atributo _mayorNumeroManchas con el mayor numero de manchas del grafo.
    // Coste O(numero de vertices + numero de aristas)

    void cuentaManchas(Grafo const& G,const Matriz<bool> &m,int c)
    {
        std::vector<bool> marked(G.V());
        
        for (unsigned int i = 0; i < G.V(); i++)
        {
            if (!marked[i] && m[i/c][i%c]) // Si no hemos recorrido ya este vertice en alguno de los recorridos y la casilla es una mancha.
            {
                size_t count = 0;
                dfsAux(G,i,marked,count); // Contamos los vertices alcanzables desde ese vertice. Coste O(numero de vertices + numero de aristas)
                _numeroManchasPorComponente.at(_nComponentesConexas) = count; // Actualizamos el numero de manchas en esa componente conexa.
                
                if (count > _mayorNumeroManchas) // Si hemos alcanzado mas manchas en este componente que en las demas.
                    _mayorNumeroManchas = count;
                // incrementamos el numero de componentes conexas.
                _nComponentesConexas++;
               
            }
        }
    }
};



#endif /* MANCHAS_H */

