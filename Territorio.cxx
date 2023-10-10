#include "Territorio.h"
#include "Continente.h"
#include <iostream>
Territorio::Territorio( std::string nuevoNombre){
    this->nombre = nuevoNombre;
}
//adicionar ficha 
void Territorio::addFicha(Ficha ficha) {
    fichas.push_back(ficha);
}
// eliminar ficha 
void Territorio::deleteFicha( std::string jugador) {
    // Implementación para eliminar la ficha del jugador
}

// mirar la ficha 
bool Territorio::ChekFicha( std::string jugador) {
    // Implementación para verificar si existe la ficha del jugador
    return false; 
}
// set de reclamado 
void Territorio::setReclamar( std::string jugador) {
    reclamado = jugador;
}

std::string Territorio::getReclamado() {
    return reclamado;
}

// contar las fichas 
int Territorio::ContarFichas( std::string jugador) {
    // Implementación para contar las fichas del jugador
    return 0; 
}
// get de cantidad de fichas 
int Territorio::GetQFichas() {
    return fichas.size();
}

std::string Territorio::getNombre(){
  return nombre;
}

std::vector<Territorio*> Territorio::getTerritoriosColindantes() {
      return this->TerritoriosColindantes;
    }

void Territorio::setTerritoriosColindantes(Territorio* Territorio) {
      TerritoriosColindantes.push_back(Territorio);
    }

