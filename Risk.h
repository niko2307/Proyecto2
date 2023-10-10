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
    void crearContinente();
    void CrearTarjetas( std::string tipo,  std::string territorio,  std::string ficha, std::string mision);
    void AgregarTropas(Jugador jugador);
    void CrearJugador(std::string nombre, int qJugadores);
    std::string colorJugador();
    void crearBatallon(int numeroJugadores);
    bool moverFichasJugador(int qFichas, std::string continente, std::string territorio);
    
   
    //setters-Risk
    void setGrupo_de_Cartas(int valor);
    void asignarGanador();

    int qUnidades(int qJugadores);
    void InicializarTerritoriosColindantes(Risk* risk);



    //setters-Jugador
    void agregarTerritorioaJugador(std::string nombreIngresado,Territorio* nuevoTerritorio );
    void AgregarTropas(Jugador* jugador, int total);
    int CantidadNuevasTropas(Jugador* jugador);


    //funciones de informacion

    std::string infoContinente();

    std::string infoJug();
    std::string infoTerritorios(std::string nameContinente);
    bool estadoTerritorio(std::string nameContinente, std::string nameTerritorio);
    void turnoJugado();
    std::string getNameJugadorEnTurno();
    std::string getColorJugadorEnTurno();
    int indiceContinente(std::string continente);
    int indiceTerritorio(int iContinente, std::string territorio);
    bool territoriosLibres();

    std::string territoriosJugador();
    int getFichasJugadorEnTurno();
    std::string buscarContinenteTerritorio(std::string territorio);
   
    std::string territoriosColindantes(std::string nombreTerritorio);
    
   //funciones de acceso a objetos-(GETTERS)
    Territorio* getTerritorio(std::string nombreContinente, std::string nombreTerritorio) ;
    Territorio* buscarTerritorio(std::string nombreContinente, std::string nombreTerritorio);   
    Jugador* getJugador(std::string nombreJugador);
    int getGrupo_de_Cartas();
    bool territorioJugador(std::string continente, std::string territorio);
    
    

    bool estadoGanador();
    bool esTurnoJugador(std::string nombreIngresado);
    bool jugadorExiste(std::string nombreIngresado);
    void atacar(int posAtacante, std::string origen, std::string destino);
    void turnosEnCero();
 
   

private:
    std::vector<Jugador> jugadores;
    std::vector<Carta> Cartas;
    std::vector<Continente> continentes ;
    bool Partida;
    bool Ganador;
    int turnoActual;
    int Totalturnos;
    int Grupo_de_Cartas;
};

#endif // RISK_H