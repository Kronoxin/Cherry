//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 5 - Referencias cruzadas.
//
/*
Clase que hereda de TreeMapAVL e implementa el operador[] asi como el metodo print especializado para este ejercicio.
*/


#ifndef TreeMapPalabra_h
#define TreeMapPalabra_h

#include <vector>

#include "TreeMap_AVL.h"

template <typename Clave, typename Valor, typename Comparador = std::less<Clave>>
class TreeMapPalabra : public TreeMap<Clave, Valor, Comparador> {
public:

	TreeMapPalabra(Comparador c = Comparador()) : TreeMap<Clave, Valor, Comparador>(c) {}

	// Implementacion del operador[] que devuelve una referencia al valor guardado en la clave que recibe.
	// Coste O(numero de nodos del arbol).
	Valor& operator[](Clave const &clave)
	{
		return insertarAux(clave, this->raiz);

	}


protected:
	using TreeNode = typename TreeMap<Clave, Valor, Comparador>::TreeNode;
	using Link = TreeNode *;

	// Metodo auxiliar que sirve para buscar e insertar en caso de no encontrar el nodo con la clave que nos dan.
	// Coste O(numero de nodos del arbol).
	Valor& insertarAux(Clave const &cv, Link & a)
	{

		if (a == nullptr)
		{
			Valor valor;
			a = new TreeNode({cv,valor});
		}

		else if (this->menor(cv, a->cv.clave))
		{
			Valor &valor = insertarAux(cv, a->iz);
			this->reequilibraDer(a);
			return valor;
		}

		else if (this->menor(a->cv.clave, cv))
		{
			Valor &valor = insertarAux(cv, a->dr);
			this->reequilibraIzq(a);
			return valor;
		}
		// Si son iguales, devolvemos el valor de a.

		return a->cv.valor;

	}


};


#endif /* TreeMapPalabra_h */
