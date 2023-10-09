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

// agregar la targeta 
void Jugador::agregarCarta(Carta carta ) {
    cartas.push_back(carta);
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
    return cartas;
}
