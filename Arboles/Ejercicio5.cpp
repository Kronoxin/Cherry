//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 5 - Referencias cruzadas.
//
/*
 Resumen de solucion:
 Guardamos las palabras en un treemap para que queden ordenadas y añadimos al nodo un atributo del tipo vector de enteros que guarda las lineas en las que aparece dicha palabra. Si la palabra ya existia antes, añade al vector el numero de linea nuevo.
 
 */

#include <stdio.h>
#include "TreeMapPalabra.h"
#include <sstream>
#include <vector>
#include <cctype>


// Imprime los elementos segun el formato requerido por el enunciado.
// O(nElementos del arbol)

void imprime(TreeMapPalabra<std::string,std::vector<int>> &arbol)
{
	TreeMapPalabra<std::string,std::vector<int>,std::less<std::string>>::Iterator it = arbol.begin();

	while (it != arbol.end())
	{

		std::cout << it.operator*().clave;

		for (int i = 0; i < it.operator*().valor.size(); i++)
			std::cout << " " << it.operator*().valor[i];

		std::cout << "\n";

		it++;

	}
	std::cout << "----" << "\n";
}
// Modifica la palabra recibida transformando sus letras en minuscula.
// O(numero de letras de la palabra * coste de la funcion std::tolower())
void pasarAMinuscula(std::string &palabra)
{
    for (int i =0; i < palabra.length(); i++)
        palabra[i] = std::tolower(palabra[i]);
	
    
}

// Funcion principal que recoge la informacion por la entrada estandar, la guarda en el arbol y llama al metodo imprime.
// El coste es O(numero de palabras del parrafo * log(numero de elementos del arbol))
int main()
{

    
    int nLineas;
    
    std::cin >> nLineas;
    
    std::string lineaActualString;
    std::string palabra = "";
    // Se recorre cada linea, y cada palabra de cada linea.
    // El coste es O(numero de palabras del parrafo * log(numero de elementos del arbol))
    while (nLineas != 0)
    {
        std::cin.ignore();
        TreeMapPalabra<std::string,std::vector<int>> arbol;
        
        
        for (int i=1; i <= nLineas;i++)
        {
            std::getline(std::cin, lineaActualString);
            
            std::istringstream iss(lineaActualString);
            std::string palabra;
            
            // Por cada palabra en la linea se hace una insercion.
            
            while(iss >> palabra)
            {
				// Si la palabra tiene mas de 2 letras.
                if (palabra.length() > 2)
                {
                    // Pasamos la palabra a minuscula.
                    pasarAMinuscula(palabra);
                    
                    // Buscamos el vector de lineas asociado a la palabra en el arbol, si no lo encuentra lo inicializa con un vector vacio.
                    std::vector<int> &vector = arbol[palabra];

					if (!vector.empty())
					{
						if (vector[vector.size()-1] != i)
							vector.push_back(i);
					}
					else
						vector.push_back(i);
               
                }
            }
        }
        
        imprime(arbol);
        std::cin >> nLineas;
    }
    
    return 0;
}
