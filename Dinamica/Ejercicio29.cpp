//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 29 - De aventura por el Amazonas.
//
/*
 Resumen de solucion:
 Tenemos que obtener el coste minimo para llegar desde i hasta j, pero debemos asegurarnos que viajar desde i hasta un k y desde k hasta j
 tambien tenga coste mínimo.
 
 
 Coste O(nPoblados^2)
 Coste memoria O(nPoblados^2)
 
 */


#include <string>
#include <iostream>
#include "Matriz.h"

void imprime(const Matriz<int> &a,int nPoblados){
    
    for (int i = 0 ; i< nPoblados ; i++)
    {
        for (int j = i; j < nPoblados; j++)
        {
            if( i != j)
            {
                std::cout << a[i][j];
                if( j != nPoblados -1)
                    std::cout << " ";
                else
                    std::cout << "\n";
            }
        }
    }
    
}

/*
    canoas(i,j) = el precio minimo que nos cuesta llegar desde i hasta j.
    canoas(i,j) = min{ precio[i,j] , min: i<k<j { canoas(i,k) + canoas(k,j)}
    
    casos base:
    canoas(i,i+1) = precio[i,i+1];
 
    Coste O(nPoblados^2)
    Coste memoria O(nPoblados^2)
 
 */

void canoas(const Matriz<int> &costes, int nPoblados, Matriz<int> &solucion )
{
    for (int d = 1; d <= nPoblados-1 ; d++)
    {
        for (int i = 0; i <= nPoblados-d; i++)
        {
            for (int  k = i; k <= i+d-1; k++)
                solucion[i][i+d] = std::min(solucion[i][i+d] , solucion[i][k] + solucion[k][i+d]);
        }
    }
}


bool resuelveCaso()
{
    int nPoblados;
     
    std::cin >> nPoblados;
     
 
 
    if(!std::cin)               // si no tenemos entrada, terminamos
        return false;
 
     Matriz<int> costes(nPoblados,nPoblados,0);
     
     for (int i = 0 ; i< nPoblados ; i++)
     {
         for (int j = i; j < nPoblados; j++)
         {
             
             if( i == j)
             {
                 costes[i][j] = 0;
             }
             else
             {
                 int c;
                 std::cin >> c;
                 costes[i][j] = c;
             }

             
         }
     }
     
     Matriz<int> solucion = costes;
     canoas(costes, nPoblados,solucion);
     imprime(solucion,nPoblados);
 
 
 
 return true;
 
 }
 
 
 int main()
 {
 while(resuelveCaso());
 return 0;
 }
