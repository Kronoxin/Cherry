/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include "PriorityQueue.h"
/*
//QuickSort Invertido - De Mayor a menor
void particion ( std::vector<long long> &v, int a, int b, int & p) {

    int i, j;
    long long aux;
    i = a+1;
    j = b;
    while ( i <= j ) 
    {
        if ( (v[i] < v[a]) && (v[j] > v[a]) ) 
        {
            aux = v[i]; 
            v[i] = v[j]; 
            v[j] = aux;
            i = i + 1; 
            j = j - 1;
        }
        else 
        {
            if ( v[i] >= v[a] ) 
                i = i + 1;
            if ( v[j] <= v[a] ) 
                j = j - 1;
        }
    }
    p = j;
    aux = v[a]; 
    v[a] = v[p]; 
    v[p] = aux;

}

void quickSortAux( std::vector<long long> &v, int a, int b) {
	int p;
        
	if ( a <= b )
        {
		particion(v, a, b, p);
		quickSortAux(v, a, p-1);
		quickSortAux(v, p+1, b);
	}
}
void quickSort ( std::vector<long long> &v, int n) {
    quickSortAux(v, 0, n-1);
}
*/
long resuelve(const std::vector<long> &pilas, long volMin){
    
    /*
     * 15 12 10 8 
     * 8  10 12 15
     * 
     * 
     *   */
    
    long i = 0;
    long j = pilas.size()-1;
    long nCoches = 0;
    while (i < j) 
    {
        if(pilas[i] + pilas[j] >= volMin)
        {
            i++;
            j--;
            nCoches++;
        }
        else
        {
            j--;
        }
    }
    return nCoches;

}

void resuelveCaso()
{
    long nCasos;
    long nPilas;
    long voltajeMin;
    
    std::cin >> nCasos; // numero de casos de prueba
   
    
    
    for(long i = 0; i < nCasos; i++)
    {
        std::cin >> nPilas; //numero de pilas
        std::cin >> voltajeMin; // voltaje mínimo
        std::vector<long> pilas(nPilas);
        PriorityQueue<long,std::greater<long>> pilasMon(nPilas);
        for(long i = 0; i < nPilas; i++)
        {

            long a;
            
            std::cin >> a;
            pilasMon.push(a);

            
        }
        //quickSort(pilas,pilas.size());
        for (long a = 0; a < nPilas;a++)
        {
            pilas[a] = pilasMon.top();
            pilasMon.pop();
        }
        
        std::cout << resuelve(pilas,voltajeMin) << std::endl;
    }
}



int main()
{
    resuelveCaso();
    return 0;
}