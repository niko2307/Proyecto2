#ifndef __Risk__H__
#define __Risk__H__

#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include "Jugador.h" 
#include "Carta.h" 
#include "Continente.h" 
#include "Ficha.h"

class Risk {
public:
    Risk();

    //funciones para el juego
    void iniciarPartida();
    bool estadoPartida();
    void asignarGanador();
    void crearContinente();
    void CrearTarjetas( std::string tipo,  std::string territorio,  std::string ficha, std::string mision);
    void AgregarTropas(Jugador jugador);
    void CrearJugador(std::string nombre, int qJugadores);
    void crearBatallon(int numeroJugadores);
    int qUnidades(int qJugadores);
    int NuevasTropas(Jugador* jugador);
    bool moverFichasJugador(int qFichas, std::string continente, std::string territorio);
    bool territoriosLibres();
    void ubicarNuevasTropas(int qtropas);
    void agregarTerritorioaJugador(std::string nombreIngresado,Territorio* nuevoTerritorio );
    
    //setters
    void setGrupo_de_Cartas(int valor);


    //funciones de informacion
    std::string infoContinente();
    std::string infoJug();
    std::string infoTerritorios(std::string nameContinente);
    std::string colorJugador();
    std::string getNameJugadorEnTurno();
    std::string getColorJugadorEnTurno();
    std::string territoriosJugador();
    int getFichasJugadorEnTurno();
    std::string buscarContinenteTerritorio(std::string territorio);
   
   //funciones de acceso a objetos
    Territorio* getTerritorio(std::string nombreContinente, std::string nombreTerritorio) ;
    bool estadoTerritorio(std::string nameContinente, std::string nameTerritorio);
    int indiceContinente(std::string continente);
    int indiceTerritorio(int iContinente, std::string territorio);
    Territorio* buscarTerritorio(std::string nombreContinente, std::string nombreTerritorio);   
    Jugador* getJugador(std::string nombreJugador);
    int getGrupo_de_Cartas();
    bool territorioJugador(std::string continente, std::string territorio);

   //FUNCIONES DE CONTROL DE JUEGO
    void turnoJugado();
    bool estadoGanador();
    bool esTurnoJugador(std::string nombreIngresado);
    bool jugadorExiste(std::string nombreIngresado);
    void turnosEnCero();
    int LanzarDado();




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