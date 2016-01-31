//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 32 - El Carpintero Ebanisto
//
//
/*
 Resumen de solucion:
 Es una idea parecida al ejercicio de las canoas, solo que en este, añadimos el coste de cada corte en el cálculo del mínimo.
 
 Coste O(nCortes^2)
 Coste memoria O(nCortes^2);
 */

#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include "Matriz.h"



//  esfuerzoMin(i,j) = Esfuerzo minimo para cortar una tabla de longitud Xj - Xi en j-i-1 trozos.
//
//
//  esfuerzoMin(i,j) =  -                                                           xi >= xj.
//  esfuerzoMin(i,j) =  0                                                           xj = xi+1.
//  esfuerzoMin(i,j) =  min{ esfuerzoMin(i,k) + esfuerzoMin(k,j)}  + 2(xj-xi)     i+1 <= k < j
//
// Coste O(nCortes^2)
// Coste memoria O(nCortes^2);


int esfuerzo_minimo(std::vector<int> &puntosDeCorte, int nCortes, Matriz<int> &solucion, int infinidad)
{
    for ( int d=2 ; d <= nCortes+2; d++){
        
        for (int i=0; i < (nCortes+2)-d; i++)
        {
            int j = i + d;
            int min = infinidad;
            int l = i+1;
            for (int k =l ; k < j; k++)
            {
                min = std::min(min,(solucion[i][k]+solucion[k][j])+(2*(puntosDeCorte[j]-puntosDeCorte[i])));
            }
            solucion[i][j] = min;
        }
    }
    
    return solucion[0][nCortes+1];
}

bool resuelveCaso()
{
    const int infinidad= INT_MAX;
    int longitudTablon;
    int nCortes;
    
    std::cin >> longitudTablon;
    std::cin >> nCortes;
    
    
    
    if(longitudTablon == 0 && nCortes == 0)               // si no tenemos entrada, terminamos
        return false;
    
    
    std::vector<int> puntosDeCorte(nCortes+2,0);
    puntosDeCorte[0] = 0;
    puntosDeCorte[nCortes+1] = longitudTablon;
    
    for (int i = 1; i<=nCortes; i++) {
        int num;
        std::cin >> num;
        puntosDeCorte[i] = num;
    }
    
    
    Matriz<int> solucion(nCortes+2,nCortes+2,0);
    
    std::cout << esfuerzo_minimo(puntosDeCorte,nCortes,solucion, infinidad) << std::endl;
    
    
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}