//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 19 - Agujeros en la manguera.
//
/*
 Resumen de solucion:
 * Recorremos los agujeros y colocamos un parche en el primer agujero que encontremos, si el siguiente agujero es alcanzable
 * por la cantidad de parche restante desde el ultimo agujero visitado entonces puede ser tapado, sino necesitamos un parche nuevo.
 * 
 Coste O(numero de agujeros).
 */

#include <iostream>
#include <vector>

// Metodo que se encarga de la resolucion del caso.
// Recoge la entrada del usuario e inicializa las variables.
// Recorre los agujeros y cuenta el numero minimo de parches necesarios. 
// Coste O(numero de agujeros).

bool resuelveCaso()
{
    unsigned int a, p;
    
    std::cin >> a; // numero de agujeros
    
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    
    std::cin >> p; // longitud parches

    int longitudParche = p; // longitud del parche actual es la longitud del parche que nos dan.
    int agujeroAnterior = 0; // inicializamos el primer agujero.
    int numeroParches = 0;
    std::vector<bool> solucion(a,false); // Vector que contiene true en cada agujero donde empieza un nuevo parche.
    
    for(int i = 0; i < a; i++)
    {
        int agujeroActual;
        std::cin >> agujeroActual;
        
        if (agujeroAnterior == 0) // Si nos encontramos en el primer agujero.
        {
            agujeroAnterior = agujeroActual; // Decimos que el agujero actual ahora es el agujero anterior.
            numeroParches++; // Para tapar un agujero necesitamos como minimo un parche.
            solucion[i] = true;
        }
        
        int distancia = agujeroActual - agujeroAnterior; // Medimos que distancia hay entre el agujero actual y el anterior.
        
        if(distancia > longitudParche) // Si no podemos taparlo con el mismo parche.
        {
            numeroParches++; // Incrementamos el numero de parches necesario.
            longitudParche=p; // La longitud restante del parche es la totalidad del parche.
            solucion[i] = true;
        }
        else{
            longitudParche -=distancia; // Si podemos taparlo entonces le quitamos al parche la distancia entre los dos agujeros.
        }
        
        agujeroAnterior=agujeroActual; // Sustituimos el agujero anterior por el actual.
    }
    
    std::cout << numeroParches << "\n"; // Imprimimos el numero de parches.
    
    return true;
}
// Metodo principal, contiene un bucle que llama a la funcion resuelveCaso.
// Esta devuelve true mientras haya casos por resolver.
// Coste O(numero de agujeros).
int main()
{
    while(resuelveCaso());
    return 0;
}


