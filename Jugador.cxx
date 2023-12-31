#include "Jugador.h"
//constructor 
Jugador::Jugador( std::string nombre, std::string nColor) {
  nombreJugador = nombre;
  color= nColor;
}
// get color 
std::string Jugador::obtenerColor() {
    return color;
}

//get Nombre del jugador 
std::string Jugador::obtenerNombreJugador() {
    return nombreJugador;
}

// get de obtener la tarjeta 
//std::vector<Carta> Jugador::obtenerTarjeta() {
//    return tarjeta;
//}
// agregar ficha 
void Jugador::agregarFicha(Ficha ficha) {
    fichas.push_back(ficha);
}

std::vector<Ficha> Jugador::obtenerFichas() {
    return fichas;
}

  int Jugador::obeterTotalFichas(){
    return fichas.size();
  }

Ficha Jugador::moverFicha(){
  Ficha aux = fichas.back();
  fichas.pop_back();
  return aux;
}

std::vector<Territorio*>& Jugador::getTerritorios() {
        return territorios;
    }

 void Jugador::setTerritorio(Territorio* nuevoTerritorio) {
        territorios.push_back(nuevoTerritorio);

    }
  int Jugador::contarTerritorios() {
    
    return territorios.size();
}
std::vector<Carta> Jugador::obtenerCartas() {
    return cartasJugador;
}

void Jugador::restarUnidades(int cantidadEliminar,std::string Nterritorio) {
    int fichasEliminadas = 0;
    for (int i = fichas.size() - 1; i >= 0 && fichasEliminadas < cantidadEliminar; i--) {
        fichas.pop_back();
        fichasEliminadas++;
    }

  //elimina las fichas al territorio desde jugador
  for (Territorio* territorio : this->territorios) {
       
if (territorio->getNombre() == Nterritorio) {
          territorio->restarFichas( cantidadEliminar);
        }
    }
}

void Jugador::agregarCarta(Carta carta){
    this->cartasJugador.push_back(carta);
}

void Jugador::eliminarTerritorio(Territorio* territorio) {
    // Buscar y eliminar el territorio del vector de territorios del jugador
    auto it = std::find(territorios.begin(), territorios.end(), territorio);
    if (it != territorios.end()) {
        territorios.erase(it);
    }
}
