#ifndef __Risk__H__
#define __Risk__H__

#include <vector>
#include <iostream>
#include <string>
#include "Jugador.h" 
#include "Carta.h" 
#include "Continente.h" 
#include "Ficha.h"

class Risk {
public:
    Risk();
    int LanzarDado();
    void iniciarPartida();
    bool estadoPartida();
    void asignarGanador();
    void crearContinente();
    void CrearTarjetas( std::string tipo,  std::string territorio,  std::string ficha, std::string mision);
    void AgregarTropas(Jugador jugador);
    std::string infoContinente();
    void CrearJugador(std::string nombre, int qJugadores);
    std::string colorJugador();
    void crearBatallon(int numeroJugadores);
    int qUnidades(int qJugadores);

//GETTERS

    std::string infoJug();
    std::string infoTerritorios(std::string nameContinente);
    Territorio* getTerritorio(std::string nombreContinente, std::string nombreTerritorio) ;
    bool estadoTerritorio(std::string nameContinente, std::string nameTerritorio);
    void turnoJugado();
    
    std::string getNameJugadorEnTurno();
    std::string getColorJugadorEnTurno();
    bool moverFichasJugador(int qFichas, std::string continente, std::string territorio);
    int indiceContinente(std::string continente);
    int indiceTerritorio(int iContinente, std::string territorio);
    bool territoriosLibres();

   int NuevasTropas(Jugador* jugador);
    int getGrupo_de_Cartas();
    void setGrupo_de_Cartas(int valor);

    std::string territoriosJugador();
    void agregarTerritorioaJugador(std::string nombreIngresado,Territorio* nuevoTerritorio );
    int getFichasJugadorEnTurno();
    std::string buscarContinenteTerritorio(std::string territorio);
    bool territorioJugador(std::string continente, std::string territorio);
    Territorio* buscarTerritorio(std::string nombreContinente, std::string nombreTerritorio);    bool estadoGanador();
    bool esTurnoJugador(std::string nombreIngresado);
    bool jugadorExiste(std::string nombreIngresado);
    Jugador* getJugador(std::string nombreJugador);
    void turnosEnCero();



protected:
    std::vector<Jugador> jugadores;
    std::vector<Carta> Cartas;
    std::vector<Continente> continentes;
    bool Partida;
    bool Ganador;
    int turnoActual;
    int Totalturnos;
    int Grupo_de_Cartas;
};

#endif // RISK_H