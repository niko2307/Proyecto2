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
    //getters
    std::string obtenerColor() ;
    //std::vector<Carta> obtenerCartas() ;
    int obeterTotalFichas();
    std::vector<Ficha> obtenerFichas() ;
    std::vector<Territorio*>& getTerritorios();  
    std::string obtenerNombreJugador() ;
    


    void agregarCarta(Carta carta); 
    void agregarFicha(Ficha ficha); 
    void setTerritorio(Territorio* nuevoTerritorio);
    Ficha moverFicha();
    
    
    void asignarTerritorio(Territorio& territorio);
   
   Jugador& obtenerJugador(int indice);

   private:
    std::string color;
    std::vector<Carta> cartas;
    std::vector<Ficha> fichas;
    std::vector<Territorio *>territorios;
    std::string nombreJugador;
    //Territorio* territorioActual;

   //std::vector<Jugador> jugadores;
};

#endif // JUGADOR_H
