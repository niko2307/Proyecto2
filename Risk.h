#ifndef RISK_H
#define RISK_H

#include <vector>
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

    std::string infoJug();
    std::string infoTerritorios(std::string nameContinente);
    bool estadoTerritorio(std::string nameContinente, std::string nameTerritorio);
    void turnoJugado();
    std::string getNameJugadorEnTurno();
    std::string getColorJugadorEnTurno();
    bool moverFichasJugador(int qFichas, std::string continente, std::string territorio);
    int indiceContinente(std::string continente);
    int indiceTerritorio(int iContinente, std::string territorio);
    bool territoriosLibres();

    std::string territoriosJugador();
    int getFichasJugadorEnTurno();
    std::string buscarContinenteTerritorio(std::string territorio);
    bool territorioJugador(std::string continente, std::string territorio);

    bool estadoGanador();
    bool esTurnoJugador(std::string nombreIngresado);
    bool jugadorExiste(std::string nombreIngresado);

    void atacar(int posAtacante, std::string origen, std::string destino);

    void turnosEnCero();



private:
    std::vector<Jugador> jugadores;
    std::vector<Carta> Cartas;
    std::vector<Continente> continentes;
    bool Partida;
    bool Ganador;
    int turnoActual;
    int Totalturnos;
};

#endif // RISK_H