//
//  Ejercicio31.cpp
//  Ejercicio1
//


#include <string>
#include <iostream>
#include <vector>
#include "Matriz.h"


//Solución con vector

//void monedas_minimas(std::vector<int> &monedas, int precio, std::vector<int> &solucion,std::vector<int>cantidades){
// 
//     for (int i = 1; i < monedas.size(); i++)
//     {
//        for (int j = precio; j >= 1 && (j/monedas[i]) != 0; j--)
//        {
//            if(monedas[i] < j)
//                solucion[j]= std::min(solucion[j], solucion[j-monedas[i]]+1);
//            else if ( monedas[i] == j)
//                solucion[j] = 1;
//        }
//    
//     }
// }

void monedas_minimas(Matriz<int> &M , std::vector<int> &monedas, int precio,std::vector<int> &cantidades,int nMonedas){
    
    for (int i = 1; i <= nMonedas; i++)
    {
        for (int j = 1; j <= precio ; j++)
        {
            int actual = M[0][1];
            int cantidadElegible = std::min(cantidades[i],(j/monedas[i]));
            
            for (int c = 0; c <= cantidadElegible; c++)
            {
                actual = std::min(actual, (M[i-1][j-(c*monedas[i])])+c);
            }
            M[i][j] = actual;
        }
    }
}

bool resuelveCaso()
{
    
    //  monedas(i,j) = Numero minimo de monedas de tipo hasta i, con las que se puede pagar j.
    //
    //  monedas(i,0) = 0
    //  monedas(0,j) = inf.
    //
    //  monedas(i,j) =  monedas(i-1,j)      xi > j.
    //  monedas(i,j) =  1                   xi = j.
    //  monedas(i,j) =  min{ monedas(i-1), monedas(i-1,j-xi)+1 }
    //
    const int infinidad= 1000001;
    int nMonedas = 0;
    
    std::cin >> nMonedas;
    
    
    if(!std::cin)               // si no tenemos entrada, terminamos
        return false;
    
    std::vector<int> linea1(nMonedas+1,0);
    std::vector<int> linea2(nMonedas+1,0);
    
    
    for (int i = 1; i<=nMonedas; i++)
    {
        int num;
        std::cin >> num;
        linea1[i] = num;
    }
    
    for (int i = 1; i<=nMonedas; i++)
    {
        int num;
        std::cin >> num;
        linea2[i] = num;
    }
    
    int precio;
    std::cin >> precio;
    
    
    Matriz<int> m(nMonedas+1,precio+1,infinidad);
    
    for (int i = 0; i <= nMonedas;i++)
        m[i][0] = 0;
    
    monedas_minimas(m,linea1, precio,linea2,nMonedas);
    
    
    
    if(m[nMonedas][precio]==infinidad)
        std::cout<<"NO"<<std::endl;
    
    else
        std::cout <<"SI "<< m[nMonedas][precio] << std::endl;
    
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}