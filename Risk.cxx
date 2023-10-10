#include "Risk.h"
#include "Territorio.h"
#include <iostream>
#include <random>
Risk::Risk() {
  Partida=false;
  Ganador=false;
  turnoActual=0;
  Totalturnos=0;
}

int Risk::LanzarDado() {
    // Implementación para lanzar un dado y retornar el número aleatorio de 1 a 6
    // esto retorna unb numero de ese rango de aletorios 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 6);
    return distribution(gen);
}
//pone la bandera de partida en verdadero
void Risk::iniciarPartida() {
  Partida=true; 
}

bool Risk::estadoPartida(){
  return Partida;
}

void Risk::asignarGanador() {
    // Implementación para asignar un ganador y terminar la partida
}

bool Risk::estadoGanador(){
  return Ganador;
}

//pone el contador de turnos en cero para volver a empezar desde el jugador 0
void Risk::turnosEnCero(){
  Totalturnos = 0;
}

void Risk::crearContinente() {
  
  //vamos a crear los contienentes aca 
    //contienete de America del norte 
    Continente continente1 ("america del norte");
    
    continente1.AddTerritorio("alaska");
    continente1.AddTerritorio("alberta");
    /*
    continente1.AddTerritorio("america central");
    continente1.AddTerritorio("estados unidos orientales");
    continente1.AddTerritorio("groenlandia");
    continente1.AddTerritorio("territorio noroccidental");
    continente1.AddTerritorio("ontario");
    continente1.AddTerritorio("quebec");
    continente1.AddTerritorio("estados unidos occidentales");
    */

  //Continente de europa 
   Continente continente2 ("europa");
    continente2.AddTerritorio("gran bretana");
    /*
    continente2.AddTerritorio("islandia");
    continente2.AddTerritorio("europa del norte");
    continente2.AddTerritorio("escandinavia");
    continente2.AddTerritorio("europa del sur");
    continente2.AddTerritorio("ucrania");
    continente2.AddTerritorio("europa occidental");
    */

  //Continente de America del sur 
    Continente continente3 ("america del sur");
    continente3.AddTerritorio("argentina");
    /*
    continente3.AddTerritorio("brasil");
    continente3.AddTerritorio("colombia");
    continente3.AddTerritorio("peru");
    */

  //continente de Africa 
    Continente continente4 ("africa");
    continente4.AddTerritorio("congo");
    /*
    continente4.AddTerritorio("africa oriental");
    continente4.AddTerritorio("egipto");
    continente4.AddTerritorio("madagascar");
    continente4.AddTerritorio("africa del norte");
    continente4.AddTerritorio("africa del sur");
    */
  //continete de Oceania
   Continente continente5 ("australia");
    continente5.AddTerritorio("australia oriental");
    /*
    continente5.AddTerritorio("indonesia");
    continente5.AddTerritorio("nueva guinea");
    continente5.AddTerritorio("australia occidental");
    */

    //continente de Asia 
    Continente continente6 ("asia");
    continente6.AddTerritorio("afghanistan");
    /*
    continente6.AddTerritorio("china");
    continente6.AddTerritorio("india");
    continente6.AddTerritorio("irkutsk");
    continente6.AddTerritorio("japon");
    continente6.AddTerritorio("kamchatka");
    continente6.AddTerritorio("medio oriente");
    continente6.AddTerritorio("mongolia");
    continente6.AddTerritorio("siam");
    continente6.AddTerritorio("siberia");
    continente6.AddTerritorio("ural");
    continente6.AddTerritorio("yakutsk");
    */
   // Agregar los continentes al tablero del juego
    continentes.push_back(continente1);
    continentes.push_back(continente2);
    continentes.push_back(continente3);
    continentes.push_back(continente4);
    continentes.push_back(continente5);
    continentes.push_back(continente6);
  
}

void Risk::CrearTarjetas(std::string tipo, std::string territorio,  std::string ficha,  std::string mision) {
    // Implementación para crear una carta de juego con los detalles proporcionados
}
//
void Risk::AgregarTropas(Jugador* jugador, int total) {
    Ficha batallon(colorJugador(), "infanteria");
    while(total!=0){
    jugador->agregarFicha(batallon);
    total--;
  }

}

//aumenta la cantiad de turnos realizados, para poder avanzar al siguiente turno
//esta funcion reliza el avanzar en los jugadores mostradondo el nombre del jugador 

void Risk::turnoJugado(){
  Totalturnos+=1;
  turnoActual=Totalturnos%jugadores.size();
}




//retorna el nombre de un continente disponible 
std::string Risk::infoContinente(){
  std::string retorno ="";
  int contador=0;
  for(int i=0; i<6; i++){
    if(continentes[i].getTerritoriosOcupados()!=continentes[i].cantidadTerritorios()){
      retorno+="\t"+std::to_string(contador+1)+". "+ continentes[i].obtenerNombre()+"\n";
      contador++;
    }
  
  }
  return retorno;
}

//guarda en una variable los territorios de un continente
//si el nombre del continente no existe, retorna ""
std::string Risk::infoTerritorios(std::string nameContinente){
  std::string retorno ="";
  int qTerritorios =0, cont=0;
  
  for(int i=0; i<6; i++){
    if(continentes[i].obtenerNombre()==nameContinente){
      
      qTerritorios = continentes[i].cantidadTerritorios();
      
      for(int terri=0; terri<qTerritorios; terri++){
        if(continentes[i].reclamado(terri)==""){
            retorno+="\t"+std::to_string(cont+1)+". "+continentes[i].getNombreTerritorio(terri)+"\n";
            cont++;
           }
        }
      i=6;
    }else retorno ="";
    
  }
  return retorno;
}
//retorna una cadena de caracteres con salida en pantalla donde se indican los continentes
//disponibles para consultar los territorios disponibles para conquistar.
bool Risk::estadoTerritorio(std::string nameContinente, std::string nameTerritorio){
   for(int i=0; i<6; i++){
    if(continentes[i].obtenerNombre()==nameContinente){
      return continentes[i].territorioValido(nameTerritorio);
    }
  }
  return false;
}

//recibo el nombre de un jugador y lo guardo en el vector de jugadores
void Risk::CrearJugador(std::string nombre, int qJugadores){

  int total = qUnidades(qJugadores);
  Jugador aux(nombre, colorJugador());
  Ficha batallon(colorJugador(), "infanteria");
  //agrega qUnidades de infanteria al jugador
  while(total!=0){
    aux.agregarFicha(batallon);
    total--;
  }
  //guardo el jugador
  jugadores.push_back(aux);
  
}

//retorna el color que se le debe asignar a un jugador
std::string Risk::colorJugador(){
  switch(jugadores.size()+1){
    case 1:return "verde";
    case 2:return "azul";
    case 3:return "rojo";
    case 4:return "amarillo"; 
    case 5:return "negro";
    case 6:return "gris";
  }
  return NULL;
}

//identifica las unidad ed de batallón inicial
int Risk::qUnidades(int qJugadores){
  switch(qJugadores){
    case 3: return 35;
    case 4: return 30;
    case 5: return 25;
    case 6: return 20;
  }
    return -1;
}

//función de depuración 
std::string Risk::infoJug(){
  std::string retorno = "";

  retorno = jugadores[turnoActual].obtenerNombreJugador() + " : "+ std::to_string(jugadores[turnoActual].obeterTotalFichas());
  return retorno;
}

//retorna el nombre del jugador en turno
std::string Risk::getNameJugadorEnTurno(){
  return jugadores[turnoActual].obtenerNombreJugador();
}

//retorna el color del juagdor en turno
std::string Risk::getColorJugadorEnTurno(){
  return jugadores[turnoActual].obtenerColor();
}
//retorna la cantidad de fichas que tiene el jugador en turno
int Risk::getFichasJugadorEnTurno(){
  return jugadores[turnoActual].obeterTotalFichas();
}


//mueve una cantidad de fichas de un jugador a un territorio de un continente en especifico
//y permite ocupar ese territorio por el jugador
bool Risk::moverFichasJugador(int qFichas, std::string continente, std::string territorio){
  int iContinente = indiceContinente( continente);
  int iTerritorio = indiceTerritorio(iContinente, territorio);

  if(jugadores[turnoActual].obeterTotalFichas()>=qFichas){
    for(int i=0; i<qFichas; i++){
      continentes[iContinente].ocuparTerritorio(jugadores[turnoActual].moverFicha(), iTerritorio, jugadores[turnoActual].obtenerNombreJugador() );
   }
    return true;
  }else
    return false;
 
}

//busca en el vector de continentes el indice de un continente 
int Risk::indiceContinente(std::string continente){
  for(int i=0; i<continentes.size(); i++){
    if(continentes[i].obtenerNombre()==continente)
      return i;
  }
  return -1;
}

//busca en el vector de territorio todos los indices
int Risk::indiceTerritorio(int iContinente, std::string territorio){
  for(int i=0; i<continentes[iContinente].cantidadTerritorios(); i++){
    if(continentes[iContinente].getNombreTerritorio(i)==territorio){
        return i;
    }    
  }
  return -1;
}

//indica si todos los territorios de todos los continentes han sido ocupados
bool Risk::territoriosLibres(){
  int qContiOcupados=0;
  for(int i=0; i<continentes.size(); i++){
    if(continentes[i].getTerritoriosOcupados()==continentes[i].cantidadTerritorios())
      qContiOcupados++;
  }

  if(qContiOcupados==continentes.size())
    return false;
  return true;
 }

//retorna una cadena de caracteres con la salida a la pantalla de los territorios que le pertenecen al usuairo en turno
//usada para mostrar en fortificar y decirle al usuario cuales son los territorios con la cantidad de fichas que tiene en cada uno

std::string Risk::territoriosJugador(){
  std::string retorno="";
  int contador =0;

  for(int i=0; i<continentes.size(); i++){
    for(int terri=0; terri<continentes[i].cantidadTerritorios(); terri++){
      if(continentes[i].reclamado(terri)==jugadores[turnoActual].obtenerNombreJugador()){
        retorno+=std::to_string(contador+1)+". "+continentes[i].getNombreTerritorio(terri)+ " - F: "+std::to_string(continentes[i].getFichasEnTerritorio(terri))+"\n";
        contador++;
     }
    }
  }
  return retorno;
}

//busca y regresa el nombre del contiente del territorio que ingresó el usuario
//usada en reforzar para poder validar el continente al cual pertecene el territorio y usar
//la función declarada en Risk::moverFichasJugadory validar despúes que el territorio de ese continente
//le pertenece al jugador en turno.
std::string Risk::buscarContinenteTerritorio(std::string territorio){
  for(int conti=0; conti<continentes.size(); conti++){

    for(int terri=0; terri<continentes[conti].cantidadTerritorios(); terri++){

      if(continentes[conti].getNombreTerritorio(terri)==territorio)
        return continentes[conti].obtenerNombre();
    }

  }
  return "";
}

//revisa que el territorio ingresado corresponda al jugador que se encuentra en turno
//usada en reforzar para que solo pueda ingresar el nombre de un territorio que le pertenece al jugador que está reforzando 
bool Risk::territorioJugador(std::string continente, std::string territorio){
  int conti = indiceContinente(continente);
  int iTerritorio = indiceTerritorio(conti, territorio);

  if(continentes[conti].reclamado(iTerritorio)==jugadores[turnoActual].obtenerNombreJugador())
    return true;
  return false;
}


//compara con los jugadores de la partida el nombre ingresado 
//retorna true, cuando el nombre ingresado es el mismo del jugador actual
bool Risk::esTurnoJugador(std::string nombreIngresado){
  for(int i =0; i<jugadores.size(); i++){
    if(jugadores[i].obtenerNombreJugador()==nombreIngresado){
      if(jugadores[turnoActual].obtenerNombreJugador()==nombreIngresado)
      return true;
    }
  }
  return false;
}

void Risk::agregarTerritorioaJugador(std::string nombreIngresado,Territorio* nuevoTerritorio ){
for(int i =0; i<jugadores.size(); i++){
    if(jugadores[i].obtenerNombreJugador()==nombreIngresado){
      jugadores[turnoActual].setTerritorio(nuevoTerritorio);
     
    }
  }
}

//busca los nombres de los jugadores y retorna true cuando el nombre del jugador existe
//en la partida actual
bool Risk::jugadorExiste(std::string nombreIngresado){
  for(int i=0; i<jugadores.size(); i++){
    if(jugadores[i].obtenerNombreJugador()== nombreIngresado)
      return true;
  }
  return false;
}

Territorio* Risk::buscarTerritorio(std::string nombreContinente, std::string nombreTerritorio) {
    for (Continente& continente : continentes) {
        if (continente.obtenerNombre() == nombreContinente) {
           return continente.buscarTerritorio(nombreTerritorio);
       
        }

    }
    return nullptr;
}
Jugador* Risk::getJugador(std::string nombreJugador) {
    for (Jugador& jugador : jugadores) {
        if (jugador.obtenerNombreJugador() == nombreJugador) {
            return &jugador;
        }
    }
    return NULL;
}


// Getter
int Risk::getGrupo_de_Cartas() {
    return Grupo_de_Cartas;
}

// Setter
void Risk::setGrupo_de_Cartas(int valor) {
    Grupo_de_Cartas = valor;
}


int Risk::CantidadNuevasTropas(Jugador* jugador) {
    int nuevasUnidades = 10;
    int territoriosOcupados = jugador->contarTerritorios();
    int continentesOcupados = 0;
    int cartasIntercambiadas = 0;
    int cartasTerritoriosOcupados = 0;
    std::vector<Carta> cartasJugador = jugador->obtenerCartas();
    int cantidadCartas = cartasJugador.size();

    // Obtener unidades por territorios
    nuevasUnidades += territoriosOcupados / 3;

    // Obtener unidades por continentes
    for (int i = 0; i < continentes.size(); i++) {
        bool continenteOcupado = true;
        std::vector<Territorio> territoriosContinente = continentes[i].obtenerTerritorios();
        for (int j = 0; j < territoriosContinente.size(); j++) {
            if (!territoriosContinente[j].ChekFicha(jugador->obtenerNombreJugador())) {
                continenteOcupado = false;
                break;
            }
        }
        if (continenteOcupado) {
            if (continentes[i].obtenerNombre() == "America del Sur" || continentes[i].obtenerNombre() == "Australia") {
                nuevasUnidades += 2;
            } else if (continentes[i].obtenerNombre() == "Africa") {
                nuevasUnidades += 3;
            } else if (continentes[i].obtenerNombre() == "America del Norte" || continentes[i].obtenerNombre() == "Europa") {
                nuevasUnidades += 5;
            } else if (continentes[i].obtenerNombre() == "Asia") {
                nuevasUnidades += 7;
            }
            continentesOcupados++;
        }
    }


    // Obtener unidades por cartas
    if (cantidadCartas >= 3) {
        int infanteria = 0;
        int caballeria = 0;
        int artilleria = 0;
        int comodin = 0;
         std::vector<Carta> cartasUtilizadas; // Para almacenar las cartas utilizadas en los tríos
   

        for (int i = 0; i < cantidadCartas; i++) {
            std::string tipoCarta = cartasJugador[i].obtenerTipoCarta();
            if (tipoCarta == "Infantería") {
                infanteria++;
            } else if (tipoCarta == "Caballería") {
                caballeria++;
            } else if (tipoCarta == "Artillería") {
                artilleria++;
            } else if (tipoCarta == "Comodín") {
                comodin++;
            }
          cartasUtilizadas.push_back(cartasJugador[i]);
 
        }
        

        //calcula la cantidad de cartas extra dependiendo del grupo de cartas en el que estemos 
          int unidadesAdicionales = 4 + (Grupo_de_Cartas - 1) * 2;
      if (Grupo_de_Cartas > 6) {
          unidadesAdicionales += (Grupo_de_Cartas - 6) * 5;
      }

      // Verificar los tríos y eliminar las cartas utilizadas
    std::queue<Carta> cartasUtilizadasQueue; // Cola para almacenar las cartas utilizadas en los tríos
    if (infanteria >= 3 || caballeria >= 3 || artilleria >= 3) {
        nuevasUnidades += unidadesAdicionales;
        // Agregar las cartas utilizadas a la cola
        for (int i = 0; i < cartasUtilizadas.size(); i++) {
            cartasUtilizadasQueue.push(cartasUtilizadas[i]);
        }
    } else if ((infanteria >= 1 && caballeria >= 1 && artilleria >= 1) || (infanteria >= 2 || caballeria >= 2 || artilleria >= 2)) {
        if (comodin >= 1) {
            nuevasUnidades += unidadesAdicionales;
            // Agregar las cartas utilizadas a la cola
            for (int i = 0; i < cartasUtilizadas.size(); i++) {
                cartasUtilizadasQueue.push(cartasUtilizadas[i]);
            }
        }
    }


    std::queue<Carta> cartasTemporales;

// Guardar toda la información en el nuevo queue
while (!cartasUtilizadasQueue.empty()) {
    Carta cartaActual = cartasUtilizadasQueue.front();
    cartasUtilizadasQueue.pop();
    cartasTemporales.push(cartaActual);
}

    //hace la comprobacion de un territorio jugador con el territorio de la carta
while (!cartasTemporales.empty()) {
    Carta cartaActual = cartasTemporales.front();
    cartasTemporales.pop();
    bool territorioEnJugador = false;
    const std::vector<Territorio*>& territoriosJugador = jugador->getTerritorios();
    for (int j = 0; j < territoriosJugador.size(); j++) {
        if (territoriosJugador[j]->getNombre() == cartaActual .obtenerTerritorio()) {
            territorioEnJugador = true;
            break;
        }
    }
    if (territorioEnJugador) {
        cartasTerritoriosOcupados++;
    }
}


      //agrega las cartas extra dependiendo de las cartas utilizadas que pertenexcan a un territorio que el jugador posee
        nuevasUnidades += cartasTerritoriosOcupados * 2;

// Eliminar las cartas utilizadas del jugador
    while (!cartasUtilizadasQueue.empty()) {
         Carta cartaUtilizada = cartasUtilizadasQueue.front();
        for (int i = 0; i < cartasJugador.size(); i++) {
            if (cartasJugador[i].obtenerTerritorio() == cartaUtilizada.obtenerTerritorio() &&
        cartasJugador[i].obtenerTerritorio() == cartaUtilizada.obtenerTerritorio()) {
                cartasJugador.erase(cartasJugador.begin() + i);
                cantidadCartas--;
                break;
            }
        }
        cartasUtilizadasQueue.pop();
    }




    }
    

    return nuevasUnidades;
}


void ubicarTropas(int qFichas, std::string continente, std::string territorio){











}