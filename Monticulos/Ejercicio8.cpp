//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio 8 - Ordenando a los pacientes en urgencias.
//

/*  Resumen de solucion:
 Tenemos una cola de prioridad que utiliza un monticulo de maximos, y un hashmap con una cola para asociar la gravedad con los pacientes que tengan esa gravedad. De esa forma mantenemos el orden de llegada de los pacientes con la misma gravedad y ademas mantenemos ordenadas las gravedades.
 
Coste O((log numero de elementos de la cola de prioridad) * numero de inserciones que se hagan de pacientes).
 */

#include <stdio.h>
#include "PriorityQueue.h"
#include "Queue.h"
#include "HashMap.h"
#include <string>


class ColaUrgencias {
private:
    PriorityQueue<int,std::greater<int>> _prioridades;
    HashMap<int, Queue<std::string>> _pacientes;
    unsigned int _nPacientes=0;
    
public:
    
    ColaUrgencias(int t = TAM_INICIAL) : _prioridades(t){};
    
    void insertar(std::string nombre, int gravedad);
    bool esVacia() const;
    std::string nombrePrimero() const;
    void quitarPrimero();
    
    
};
// Inserta un paciente en la cola.
// Coste O(log n). Debido a la posible insercion en la cola con prioridad.
void ColaUrgencias::insertar(std::string nombre, int gravedad)
{
    // Si la cola con prioridad no contiene esa gravedad ya, la añade.
    // O(log numero de elementos de la cola de prioridad).
    if (!_pacientes.contains(gravedad))
        _prioridades.push(gravedad);
    
    // Accedemos al HashMap de pacientes insertando el nombre en la cola, permitimos que haya nombres repetidos.
    // Acceso al valor del HashMap tiene coste constante, la insercion en una cola es constante tambien.
    _pacientes[gravedad].push_back(nombre);
    // Incrementamos el numero de pacientes que hay.
    _nPacientes++;
}

// Devolvemos el nombre del paciente con mayor gravedad que entro antes que otro con la misma gravedad.
// Coste O(1). El acceso al hashmap es constante y el acceso al primer elemento de la cola tambien.
std::string ColaUrgencias::nombrePrimero() const
{
    
    return _pacientes.at(_prioridades.top()).front();
}

// Quitamos al paciente con mas prioridad que mas tiempo lleva en la cola.
// Coste O(1). El acceso al hashmap es de coste constante, el acceder al primer elemento de la cola tambien, y el sacarlo tambien.
void ColaUrgencias::quitarPrimero()
{
    // Quitamos al paciente con mas prioridad que mas tiempo lleva en la cola.
    _pacientes[_prioridades.top()].pop_front();
    
    // Si ya no hay mas pacientes con esa prioridad la quitamos del monticulo.
    if (_pacientes[_prioridades.top()].size() == 0)
    {
        int clave = _prioridades.top();
        _prioridades.pop();
        //si la lista se vacia, lo eliminamos del HashMap
        _pacientes.erase(clave);
    }
    
    _nPacientes--;
}

// Comprobamos si nos quedan mas pacientes en la cola.
// Coste O(1). Comparacion entre dos enteros, coste constante.
bool ColaUrgencias::esVacia() const
{
    return _nPacientes == 0;
}

// Solicitamos los casos de prueba y los vamos resolviendo.
// Coste O((log numero de elementos de la cola de prioridad) * numero de inserciones que se hagan de pacientes).

int main()
{
    int nElems;
    std::cin >> nElems;
    
    while(nElems != 0)
    {
        ColaUrgencias cola;
        
        for (int i=0; i < nElems; i++)
        {
            char opcion;
            std::cin >> opcion;
        
            if (opcion == 'I')
            {
                std::string nombre;
                std::cin >> nombre;
                int gravedad;
                std::cin >> gravedad;
                cola.insertar(nombre, gravedad);
            
            }
            else
            {   // Si no intentamos sacar un paciente que no esta.
                if (!cola.esVacia())
                {
                    std::cout << cola.nombrePrimero() << "\n";
                    cola.quitarPrimero();
                }
            }
        }
        std::cout << "----" << "\n";
        std::cin >> nElems;
    }
    
}

