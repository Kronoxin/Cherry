//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 9 - Pájaros en  vuelo.
//

/*  Resumen de solucion:
Tenemos una cola de prioridad de maximos para representar a la fila de pajaros jovenes y otro de minimos para representar a los mayores.
Al insertar una pareja comparamos los pajaros con el que esta en el medio, si el pajaro a insertar es menor lo insertaremos en el de maximos y si es mayor en el de minimos.
Comprobamos el caso en el que hayamos insertado los 2 en el mismo sitio, ya que tendremos que hacer una rotacion para mantener la longitud adecuada en el banco de pajaros.

Coste O(log numero de pajaros en la cola de prioridad).
*/

#ifndef bancopAuxs_h
#define bancopAuxs_h

#include "PriorityQueue.h"

class bancoPajaros{
    
    private:
        PriorityQueue<int,std::greater<int>> _menores;
        PriorityQueue<int,std::less<int>> _mayores;
    
    public:
        bancoPajaros(int vertice){ _mayores.push(vertice);}
    
        // Devolvemos el menor de los mayores, que es el pajaro que esta en el medio
        int vertice() const
        {
            return _mayores.top();
        }
    
        // Metodo que inserta los pajaros en el banco de pajaros.
        void  insertar(int p1, int p2)
        {
            int pAux,vertice;
            // Obtenemos el pajaro que esta en el medio.
            vertice=_mayores.top();
            // Si el pajaro uno y el dos son menores que el vertice tenemos que insertarlos en los menores y pasar el mayor de los menores al menor de los mayores.
            if(p1 < vertice && p2 < vertice)
            {
                _menores.push(p1);
                _menores.push(p2);
                _menores.pop(pAux);
                _mayores.push(pAux);

            }
            // Si el pajaro uno y el dos son mayores que el vertice tenemos que insertarlos en los mayores y pasar el menor de los mayores al menor de los mayores.
            else if (p1 > vertice && p2 > vertice)
            {
                _mayores.push(p1);
                _mayores.push(p2);
                _mayores.pop(pAux);
                _menores.push(pAux);
            }
            // si p1 es menor que el vertice y p2 mayor, insertamos p1 en los menores y p2 en los mayores.
            else if (p1 < vertice && p2 > vertice)
            {
                _menores.push(p1);
                _mayores.push(p2);
            }
            // si p1 es mayor que el vertice y p2 es menor que el vertice, metemos p2 a los menores y p1 a los mayores.
            else
            {
                _menores.push(p2);
                _mayores.push(p1);
            }
        }
};



#endif /* bancopAuxs_h */