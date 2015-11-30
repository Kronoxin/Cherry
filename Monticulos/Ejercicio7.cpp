//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 7 - Lo que cuesta sumar.
//

/*  Resumen de solucion:
	Usamos una cola de prioridad donde la raiz es el numero mas pequeño. Vamos sumando las operaciones segun sacamos los elementos de la cola de dos en dos y añadimos la suma 
	al final de la cola. LLevamos una variable de esfuerzo con la suma acumulada de las operaciones.


*/

#include <stdio.h>
#include "PriorityQueue.h"

// Cargamos los elementos en la cola de prioridad.
// Coste O(numero de elementos a cargar * log numero de elementos en la cola)
PriorityQueue<long long int> cargarCola(long long int n)
{
	long long int elemento;
	PriorityQueue<long long int> cola;

	for (long long int i = 0; i < n; i++)
	{
		std::cin >> elemento;
		cola.push(elemento);
	}
	return cola;
}

// Pedimos los datos y resolvemos el problema.

int main()
{
	long long int n;
	std::cin >> n;
	// Mientras no nos llegue un 0 por la entrada estandar.
	while (n != 0)
	{		
		// Cargamos la cola.
		PriorityQueue<long long int> cola = cargarCola(n);
		// Inicializamos el esfuerzo.
		long long int esfuerzo = 0;
		// Mientras quede mas de un elemento en la cola.
		while (cola.size() > 1)
		{
			long long int a, b;
			// Sacamos a.
			cola.pop(a);
			// Sacamos b.
			cola.pop(b);
			// Incrementamos el esfuerzo con la suma de ambos.
			esfuerzo += a + b;
			// Añadimos la suma de a y b a la cola.
			cola.push(a + b);	
		}

		std::cout << esfuerzo << "\n";
		std::cin >> n;
	}
	return 0;
}