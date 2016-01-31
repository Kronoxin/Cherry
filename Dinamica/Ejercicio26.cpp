//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 26 - Varillas.
//
/*
 Resumen de solucion:
 
 El problema consta de 4 apartados.
 
 1. Indicar si es posible formar una varilla de longitud exacta L usando las varillas de las que disponemos.
    La idea es, si no estoy en los casos base, compruebo si puedo formar la varilla objetivo usando la varilla actual
 
 2. Numero de formas posibles de formar la varilla objetivo con las varillas disponibles.
    Si no estoy en los casos base, hago la suma del numero de combinaciones posibles usando la varilla actual con el 
    numero de combinaciones sin usar la varilla actual.
 
 3. Numero minimo de varillas necesarias para formar la varilla objetivo.
    Hago el minimo entre el numero de varillas necesarias para formar la varilla objetivo usando mi varilla actual o sin usarla.
 
 4. Minimo coste posible para formar la varilla objetivo.
    Si la longitud de la varilla actual es igual a la longitud objetivo el coste que buscamos es el minimo entre el coste de esa varilla actual
    y el coste que tenemos sin usar esa varilla. Si la longitud de la varilla actual es inferior a la del objetivo calculamos el minimo entre el coste de la varilla actual mas los costes que teniamos y el coste sin usar la varilla actual.
    
 
  Coste O(nVarillas*L) Siendo L la longitud de la varilla.
  Coste memoria O(L);
 */


#include <stdio.h>
#include <iostream>
#include <vector>
#include "Varillas.h"



bool resuelveCaso()
{
    
    
    int nVarillas;
    int longitudFinal;
    
    
    std::cin >> nVarillas;      //leemos el numero de varillas
    
    if(!std::cin)               // si no tenemos entrada, terminamos
        return false;

    
    std::vector<int> varillas(nVarillas+1,0);
    std::vector<int> costes(nVarillas+1,0);
    
    
    std::cin >> longitudFinal;  //longitud total alcanzable
    
    for(int i = 1 ; i<= nVarillas ; i++){
        int a;
        std::cin >> a;
        varillas[i] = a;
        std::cin >> a;
        costes[i] = a;
        
    }
    
    Varillas va(varillas,costes,nVarillas,longitudFinal);
    
    if(va.esPosible(longitudFinal))
        std::cout << "SI " << va.numCombinaciones(longitudFinal) << " " << va.numeroMinVarillas(longitudFinal) << " " << va.costeMinimo(longitudFinal) <<  "\n";
    else
        std::cout << "NO\n";

    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}