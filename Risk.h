#ifndef _RISK_H
#define _RISK_H

#include <vector>
#include <queue>
#include <string>
#include "Jugador.h"
#include "Carta.h"
#include "Continente.h"
#include "Ficha.h"

class Risk {
public:
    // Constructor y funciones básicas
    Risk();
    void iniciarPartida();
    bool estadoPartida();
    bool asignarGanador();
    void crearContinente();
    void CrearCartasJuego();
    std::string resultadoAtaque(std::string Territorioatacante, std::string TerritorioDefensor);
    //void AgregarTropas(Jugador jugador);
    void CrearJugador(std::string nombre, int qJugadores);
    std::string colorJugador();
    
    //void crearBatallon(int numeroJugadores);
    bool moverFichasJugador(int qFichas, std::string continente, std::string territorio);
    bool territoriosLibres();

    // Setter y funciones relacionadas a Risk
    void setGrupo_de_Cartas(int valor);
    int qUnidades(int qJugadores);
    void InicializarTerritoriosColindantes(Risk* risk);

    // Setter y funciones relacionadas a Jugador
    void agregarTerritorioaJugador(std::string nombreIngresado, Territorio* nuevoTerritorio);
    void AgregarTropas(Jugador* jugador, int total);
    int CantidadNuevasTropas(Jugador* jugador);

    // Funciones de información
    std::string infoContinente();
    std::string infoJug();
    std::string infoTerritorios(std::string nameContinente);
    bool estadoTerritorio(std::string nameContinente, std::string nameTerritorio);
    void turnoJugado();
    std::string getNameJugadorEnTurno();
    std::string getColorJugadorEnTurno();
    int indiceContinente(std::string continente);
    int indiceTerritorio(int iContinente, std::string territorio);
    std::string territoriosJugador();
    int getFichasJugadorEnTurno();
    std::string buscarContinenteTerritorio(std::string territorio);
    bool territorioJugador(std::string continente, std::string territorio);
    std::string territoriosColindantes(std::string nombreTerritorio);

    // Funciones de acceso a objetos (GETTERS)
    Territorio* buscarTerritorio(std::string nombreContinente, std::string nombreTerritorio);
    Jugador* getJugador(std::string nombreJugador);
    int getGrupo_de_Cartas();
    bool estadoGanador();
    bool esTurnoJugador(std::string nombreIngresado);
    bool jugadorExiste(std::string nombreIngresado);
    void turnosEnCero();
    Jugador* territorioPerteneceAJugador(Territorio* territorio);

    // Funciones extras
    int LanzarDado();

private:
    std::vector<Jugador> jugadores;
    std::queue<Carta> Cartas;
    std::vector<Continente> continentes;
    bool Partida;
    bool Ganador;
    std::string Nganador;
    int turnoActual;
    int Totalturnos;
    int Grupo_de_Cartas;
};

#endif // RISK_H
