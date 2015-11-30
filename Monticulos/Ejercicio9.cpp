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

#include <stdio.h>
#include "PriorityQueue.h"
#include "bancoPajaros.h"

/* 
	Bucle principal, pide la entrada y resuelve el problema mediante una clase auxiliar.
	Coste O(log numero de pajaros en la cola de prioridad).
*/

int main()
{
    unsigned int nElems;
    

    int a,b;
    
    std::cin >> a;
    std::cin >> nElems;
    // Mientras no nos lleguen dos 0s.
    while (a !=0 && nElems!=0)
    {

        bancoPajaros bancoP(a);
        // Por cada pareja de elementos los vamos insertando.    
        for (int i = 0 ; i< nElems; i++)
        {
            std::cin >> a >> b;
            bancoP.insertar(a,b);
            // Imprimimos el ave que esta en el medio.
            std::cout << bancoP.vertice();
            
            if(i != nElems-1)
            {
                std::cout << " ";
            }
        }
        
        std::cout << "\n";
        
        std::cin >> a;
        std::cin >> nElems;
    }
}