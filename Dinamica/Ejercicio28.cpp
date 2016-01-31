//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 28 - Inserción de Paréntesis 2.
//
/*
 Resumen de solucion:
 Hacemos algo similar al ejercicio 27, pero en vez de tener una matriz A, B y C de booleanos tenemos las mismas matrices pero de enteros,
 que van llevando el numero de formas de conseguir A, B y C.
 Hacemos el calculo del numero de formas de conseguir A sumando todas las combinaciones posibles de conseguir sus componentes.
 Ejemplo: a = a * c; a = b * c; a = c * a;
 
 
 
 
 Coste O(nLetrasDeSecuencia^2)
 Coste memoria O(nLetrasDeSecuencia^2).
 */

#include <string>
#include <iostream>
#include <vector>
#include "Matriz.h"

void nFormasA(Matriz<int> &A , Matriz<int> &B, Matriz<int> &C , int i , int d)
{
    int k = i;
    int j = i+d;
    while (k <= i+d-1) {
        A[i][j] = (((A[i][j] + (A[i][k] * (long long)C[k+1][j])%1000000007)%1000000007 + (B[i][k] * (long long)C[k+1][j])%1000000007)%1000000007 + (C[i][k] * (long long)A[k+1][j])%1000000007)%1000000007;
        k++;
    }
}

void nFormasB(Matriz<int> &A , Matriz<int> &B, Matriz<int> &C , int i, int d)
{
    int k = i;
    int j = i+d;
    while (k <= i+d-1) {
        B[i][j] = (((B[i][j] + (A[i][k] * (long long)A[k+1][j])%1000000007)%1000000007 + (A[i][k] * (long long)B[k+1][j])%1000000007)%1000000007 + (B[i][k] * (long long)B[k+1][j])%1000000007)%1000000007;
        k++;
    }
}

void nFormasC(Matriz<int> &A , Matriz<int> &B, Matriz<int> &C , int i, int d)
{
    int k = i;
    int j = i+d;
    while (k <= i+d-1) {
        C[i][j] = (((C[i][j] + (B[i][k] * (long long)A[k+1][j])%1000000007)%1000000007 + (C[i][k] * (long long)B[k+1][j])%1000000007)%1000000007 + (C[i][k] * (long long)C[k+1][j])%1000000007)%1000000007;
        k++;
    }
}

//  nFormas A
//
//  nFormasA(i,j) = 1                           si i=j ; xi=a .
//  nFormasA(i,j) = 0                           si i=j ; xi=b o xi=c.
//
//  nFormasA(i,j)  = SumatorioX : i<=k<j:
//                      nFormasA(i,k) * nFormasC(k+1,j)
//                    + nFormasB(i,k) * nFormasC(k+1,j)
//                    + nFormasC(i,k) * nFormasA(k+1,j)
//
//
//  nFormas B
//
//  nFormasA(i,j) = 1                           si i=j ; xi=b .
//  nFormasA(i,j) = 0                           si i=j ; xi=a o xi=c.
//
//  nFormasA(i,j)  =  SumatorioX : i<=k<j:
//                      nFormasA(i,k) * nFormasA(k+1,j)
//                    + nFormasA(i,k) * nFormasB(k+1,j)
//                    + nFormasB(i,k) * nFormasB(k+1,j)
//
//
//  nFormas C
//
//  nFormasA(i,j) = 1                           si i=j ; xi=c .
//  nFormasA(i,j) = 0                           si i=j ; xi=a o xi=b.
//
//  nFormasA(i,j)  = SumatorioX : i<=k<j:
//                      nFormasB(i,k) * nFormasA(k+1,j)
//                    + nFormasC(i,k) * nFormasB(k+1,j)
//                    + nFormasC(i,k) * nFormasC(k+1,j)
//
//
// Coste O(nLetrasDeSecuencia^2)
// Coste memoria O(nLetrasDeSecuencia^2).
//



int nFormas(std::vector<char> letras, int n)
{
    Matriz<int> A(n,n,0);
    Matriz<int> B(n,n,0);
    Matriz<int> C(n,n,0);
    
    for (int i = 0; i < n; i++)
    {
        if(letras[i] == 'a')
            A[i][i] = 1;
        if(letras[i] == 'b')
            B[i][i] = 1;
        if(letras[i] == 'c')
            C[i][i] = 1;
        
    }
    
    for (int d = 1; d< n; d++)
    {
        for (int i = 0; i < n-d; i++)
        {

            nFormasA(A, B, C, i, d);
            nFormasB(A, B, C, i, d);
            nFormasC(A, B, C, i, d);
            
        }
    }
    return A[0][n-1];
}



bool resuelveCaso()
{
    
    std::string linea;
    
    std::getline(std::cin,linea);     //leemos linea a linea
    
    
    if(!std::cin)               // si no tenemos entrada, terminamos
        return false;
    
    
    std::vector<char> letras(linea.length());
    
    for (int i = 0; i < linea.length(); i++) {
        letras[i] = linea[i];
    }
    
    
    std::cout << nFormas(letras, letras.size()) << std::endl;
    
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}
