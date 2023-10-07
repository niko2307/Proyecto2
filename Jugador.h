#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Ficha.h" 
#include "Carta.h"
#include "Territorio.h"

class Jugador {
public:
    Jugador(std::string nombre, std::string nColor);
    std::string obtenerColor() ;
    std::string obtenerNombreJugador() ;
    void agregarCarta(Carta carta); 
    //std::vector<Carta> obtenerCartas() ;
    void agregarFicha(Ficha ficha); 
    Ficha moverFicha();
    std::vector<Ficha> obtenerFichas() ;
    int obeterTotalFichas();
    void asignarTerritorioActual(Territorio& territorio);
   Territorio obtenerTerritorioActual();
   Jugador& obtenerJugador(int indice);

   private:
    std::string color;
    std::vector<Carta> cartas;
    std::vector<Ficha> fichas;
    std::string nombreJugador;
    Territorio* territorioActual;
   std::vector<Jugador> jugadores;
};

#endif // JUGADOR_H
