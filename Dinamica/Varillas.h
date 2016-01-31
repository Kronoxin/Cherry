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

#ifndef Varillas_h
#define Varillas_h

#include "Matriz.h"
#include <vector>
#include <iostream>
#include <stdexcept>

class Varillas
{
public:
    
    Varillas(std::vector<int> varillas, std::vector<int> costes, int nVarillas, int L)
    {
        
        numMinVarillas = std::vector<int> (L+1, infinidad);
        combinaciones = std::vector<int> (L+1, 0);
        precios = std::vector<int> (L+1, infinidad);
        posibles = std::vector<bool>(L+1,false);
        numMinVarillas[0] = 0;
        combinaciones[0] = 1;
        precios[0] = 0;
        
        calcularPosibles(varillas, nVarillas, L, posibles);
        calcularNumMinVarillas(varillas, nVarillas, L, numMinVarillas);
        calcularCombinaciones(varillas, nVarillas, L, combinaciones);
        calcularPrecios(varillas, nVarillas, L, precios, costes);
        
        
    }
    
    bool esPosible(int longitud)
    {
        if (longitud > combinaciones.size()-1)
            throw std::invalid_argument("La longitud requerida no ha sido previamente calculada.");
        else
            return posibles[longitud];
    }
    
    int numCombinaciones(int longitud)
    {
        if (longitud > combinaciones.size()-1)
            throw std::invalid_argument("La longitud requerida no ha sido previamente calculada.");
        else
            return combinaciones[longitud];
    }
    
    int numeroMinVarillas(int longitud)
    {
        if (longitud > numMinVarillas.size()-1)
            throw std::invalid_argument("La longitud requerida no ha sido previamente calculada.");
        else
            return numMinVarillas[longitud];
    }
    
    int costeMinimo(int longitud)
    {
        if (longitud > numMinVarillas.size()-1)
            throw std::invalid_argument("La longitud requerida no ha sido previamente calculada.");
        else
            return precios[longitud];
    }
    
    
private:
    const long long int infinidad = 1000001;
    
    std::vector<int> numMinVarillas;
    std::vector<int> combinaciones;
    std::vector<int> precios;
    std::vector<bool> posibles;
    
    void imprimeMatriz(Matriz<int> &m){
        for(int i = 0; i < m.numfils() ;i++){
            std::cout <<"[";
            for( int j = 0 ; j < m.numcols() ; j++){
                std::cout <<" " << m[i][j];
            }
            std::cout <<" ]\n";
        }
    }
    void imprimeVector(const std::vector<int> &v)
    {
        
        std::cout << "[";
        
        for(int i = 0; i < v.size(); i++)
            std::cout << " " << v[i];
        
        std::cout << "]\n";
        
    }
    
    // posibles(i,j) = se puede formar una varilla j con varillas de i.
    // posibles(0,0) = true;
    // posibles(i,0) i >= 1 = false;
    // posibles(0,j) = false;
    //
    // posibles(i,j) = true             si v[i] == j
    // posibles(i,j) = posibles(i-1,j)  si v[i] > j
    // posibles(i,j) = posibles(i-1,j) || posibles(i-1,j-v[i]) si v[i] < j
    // Coste O(nVarillas*L) Siendo L la longitud de la varilla.
    // Coste memoria O(L);
    
    void calcularPosibles(std::vector<int> &v, int nVarillas, int L, std::vector<bool> &solucion)
    {
        for (int i = 1; i <= nVarillas; i++)
        {
            for (int j= L; j >= 1; j--)
            {
                if (v[i] == j)
                    solucion[j] = true;
                else if (v[i] < j)
                    solucion[j] = solucion[j] || solucion[j-v[i]];
            }
        }
    }
    
    //  varillas(i,j) = numero de varillas mínimo que de longitud l que suman una longitud j.
    //  varillas(0,0) = 0
    //  varillas(0,L) = inf;
    //  varillas(l,o)= 0;
    //
    //  varillas(i,j) = varillas(i-1,j)                             si l > j;
    //  varillas(i,j) = min(varillas(i-1,j) , varillas(i-1, j-l))   si l<=j
    // Coste O(nVarillas*L) Siendo L la longitud de la varilla.
    // Coste memoria O(L);

    void calcularNumMinVarillas(std::vector<int> &v, int nVarillas, int L,std::vector<int> &solucion)
    {
    
        for (int i = 1; i <= nVarillas; i++)
            for (int j = L; j >= 1 ; j--)
                if(v[i] <= j)
                    solucion[j]= std::min(solucion[j], solucion[j-v[i]]+1);
    }
    
    
    
    // combinaciones(i,j) = numero de formas de sumar la longitud j con varillas de l0....li.
    //
    //  combinaciones(0,0) = 1;
    //  combinaciones(0,j) = 0;
    //  combinaciones(i,0) = 1;
    //
    //  combinaciones(i,j) = combinaciones( i-1, j)                             si li > j.
    //  combinaciones(i,j) = combinaciones( i-1, j) + combinaciones(i-1, j-li)  si li <= j.
    //
    // Coste O(nVarillas*L) Siendo L la longitud de la varilla.
    // Coste memoria O(L);
    
    void calcularCombinaciones(std::vector<int> &v, int nVarillas, int L,std::vector<int> &solucion)
    {
        for (int i = 1; i <= nVarillas; i++)
        {
            for (int j = L; j >= 1 ; j--)
            {
                if (v[i] <= j)
                    solucion[j]= solucion[j] + solucion[j-v[i]];
                
            }
        }
    }
    
    
    //  costes(i,j) = coste de formar la longitud j con varillas de l0....li.
    //
    //  costes(0,0) = 0;
    //  costes(0,j) = 0;
    //  costes(i,0) = 0;
    //
    //  costes(i,j) = costes( i-1, j)                                       si li > j.
    //  costes(i,j) = min( p[i] , costes( i-1, j) )                         si li = j.
    //  costes(i,j) = min( p[i] + costes( i-1, j-li) , costes( i-1, j) )    si li < j.
    // Coste O(nVarillas*L) Siendo L la longitud de la varilla.
    // Coste memoria O(L);
    
    void calcularPrecios(std::vector<int> &v, int nVarillas, int L,std::vector<int> &solucion,std::vector<int> &costes)
    {

        for (int i = 1; i <= nVarillas; i++)
        {
            for (int j = L; j >= 1 ; j--)
            {
                
               if( v[i] == j)
                   solucion[j]= std::min(costes[i], solucion[j]);
                
               else if (v[i] < j)
                   solucion[j] = std::min(costes[i] + solucion[j-v[i]], solucion[j]);
                
            }
        }
    }
    


};


#endif /* Varillas_h */
