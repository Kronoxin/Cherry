/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Grafo.h"

int main()
{
    std::string fichero = "Ejercicio10.txt";
    Grafo grafo = Grafo(fichero);
    
    
    grafo.print();   
    std::cout << "hola";
    
    return 0;
}