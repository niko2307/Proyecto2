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
bool Territorio::ChekFicha(std::string jugador) {
    for (Ficha& ficha : fichas) {
        if (ficha.obtenerColor() == jugador) {

            std::cout<<"la ficha pertenece al color del jugador"<<jugador<<"=="<<ficha.obtenerColor()<<std::endl;
            return true;
        }
    }
    return false;
}
// set de reclamado 


std::string Territorio::getReclamado() {
    return reclamado;
}

// contar las fichas 
int Territorio::ContarFichas(std::string Colorjugador) {
    int contador = 0;
    for ( Ficha& ficha : fichas) {
        if (ficha.obtenerColor() == Colorjugador) {
            contador++;
        }
    }
    return contador;
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
      this->TerritoriosColindantes.push_back(Territorio);
    }

bool Territorio::esColindante(Territorio* otroTerritorio) {
    for (Territorio* colindante : TerritoriosColindantes) {
        if (colindante->getNombre() == otroTerritorio->getNombre()) {
            return true;
        }
    }
    return false;
}

void Territorio::restarFichas(int cantidadEliminar) {
    int fichasEliminadas = 0;
    for (int i = this->fichas.size() - 1; i >= 0 && fichasEliminadas < cantidadEliminar; i--) {
        this->fichas.pop_back();
        fichasEliminadas++;
    }
}

Ficha Territorio::obtenerFicha(std::string jugador) {
    for (Ficha& ficha : fichas) {
        if (ficha.obtenerColor() == jugador) {
            return ficha;
        }
    }
    // Si no se encuentra la ficha, se devuelve una ficha vacía
    return Ficha("", "");
}
void Territorio::setReclamar(std::string jugador) {
    reclamado = jugador;
}