#include <vector>
#include <queue>
#include "arbolhuffman.h"
#include <string>



template<class T>
ArbolHuffman<T>::ArbolHuffman() {
    raiz = nullptr;
}

template<class T>
ArbolHuffman<T>::~ArbolHuffman() {

}

template<class T>
 NodoHuffman<T>* ArbolHuffman<T>::construirArbol(std::vector<std::pair<T, int>>& frecuencias) {
    // Creamos nodos iniciales para cada símbolo con sus frecuencias
    std::priority_queue<NodoHuffman<T>*, std::vector<NodoHuffman<T>*>, decltype(&CompararFrecuencia)> colaPrioridad(&CompararFrecuencia);

    for (typename std::vector<std::pair<T, int>>::const_iterator it = frecuencias.begin(); it != frecuencias.end(); ++it) {
        const std::pair<T, int>& par = *it;
        NodoHuffman<T>* nodo = new NodoHuffman<T>(par.first, par.second);
        colaPrioridad.push(nodo);
    }

    // Construimos el árbol de Huffman combinando los nodos con menor frecuencia
    while (colaPrioridad.size() > 1) {
        NodoHuffman<T>* izquierdo = colaPrioridad.top();
        colaPrioridad.pop();
        NodoHuffman<T>* derecho = colaPrioridad.top();
        colaPrioridad.pop();

        // Creamos un nuevo nodo con frecuencia combinada y lo agregamos a la cola
        int frecuenciaCombinada = izquierdo->getFrecuencia() + derecho->getFrecuencia();
        NodoHuffman<T>* nodoCombinado = new NodoHuffman<T>(T(), frecuenciaCombinada);
        nodoCombinado->setIzquierdo(izquierdo);
        nodoCombinado->setDerecho(derecho);
        colaPrioridad.push(nodoCombinado);
    }

    // El último nodo en la cola es la raíz del árbol de Huffman
    raiz = colaPrioridad.top();
}



template<class T>
std::string ArbolHuffman<T>::codificar( std::string& texto) {
    std::string codigo;

    // Recorre el texto caracter por caracter
    for (char caracter : texto) {
        // Llama a una función que busca el código Huffman del caracter en el árbol
        std::string codigoCaracter = obtenerCodigoCaracter(caracter);

        // Agrega el código del caracter al resultado
        codigo += codigoCaracter;
    }

    // Agregamos un mensaje de éxito
    codigo += "\n¡Codificación exitosa!\n";

    return codigo;
}

template<class T>
std::string ArbolHuffman<T>::obtenerCodigoCaracter(char caracter) {
    std::string codigo;
    NodoHuffman<T>* nodoActual = raiz;

    // Realiza un recorrido descendente en el árbol para encontrar el código del caracter
    while (nodoActual) {
        if (nodoActual->esHoja() && nodoActual->getCaracter() == caracter) {
            break; // Hemos encontrado el código del caracter
        }

        // Si el bit actual es 0, nos movemos hacia el hijo izquierdo; si es 1, hacia el hijo derecho
        if (caracter & 1) {
            nodoActual = nodoActual->getDerecho();
        } else {
            nodoActual = nodoActual->getIzquierdo();
        }

        // Quitamos el bit procesado del caracter
        caracter >>= 1;
    }

    return codigo;
}



template<class T>
bool ArbolHuffman<T>:: CompararFrecuencia( NodoHuffman<T>* lhs,  NodoHuffman<T>* rhs) {
    return lhs->getFrecuencia() > rhs->getFrecuencia();
}