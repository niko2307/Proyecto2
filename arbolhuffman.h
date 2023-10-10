#ifndef ARBOLHUFFMAN_H
#define ARBOLHUFFMAN_H
#include <string>

#include "NodoHuffman.h"

template<class T>
class ArbolHuffman {
private:
    NodoHuffman<T>* raiz;

public:
    ArbolHuffman();
    ~ArbolHuffman();
    NodoHuffman<T>*construirArbol( std::vector<std::pair<T, int>>& frecuencias);
    std::string codificar( std::string& texto);
    std::string obtenerCodigoCaracter(char caracter);
    std::string decodificar(std::string &codigo);
    void recorridoPreorden(NodoHuffman<T> *nodoActual);
    void recorridoPreorden();
    bool CompararFrecuencia(NodoHuffman<T> *lhs, NodoHuffman<T> *rhs);
};

#include "arbolHuffman.hxx"

#endif // ARBOLHUFFMAN_H
