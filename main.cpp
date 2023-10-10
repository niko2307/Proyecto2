#include <iostream>
#include <fstream>
#include <string>
#include "Risk.h"
#include "arbolhuffman.h"

using namespace std;

string ingresarComando();
void mensajeBienvenida();
int identificarComando(string cadena);
string separarEspacio(string cadena, bool parametro);
bool qParametros(string respuesta);
void crearArchivo(const string& nombreArchivo);
void leerArchivo(const string& nombreArchivo);
void mostrarAyudaComando(const string& comando);
void infoInicializar(void);
void infoTurno(void);
void infoSalir(void);
void infoGuardar(void);
void infoGuardarComprimido(void);
void infoCostoConquista(void);
void infoConquistaMasBarata(void);

//entrega 2
void inicializarJuego(Risk* risk);
void fortificar(Risk* risk, bool inicializar);
void turno (Risk* risk);

int main() {
  //instancia para la clase risk
  Risk risk;
  risk.crearContinente();
    //guarda la cadena ingresada por el usuario
    string respuesta;
    //mensaje de bienvenida
    mensajeBienvenida();
    //bandera para terminar el programa
    bool salir = false;
    //valor= variable usada en el switch case
    //qJugadores= cantidad de jugadores en la partida
    int valor, qJugadores;
    //turno= turno ingresado por el usuario
    //turnoPrueba= variable de turno para pruebas
    string turnoAux;
    //indica si hay algún ganador
    int ganador = -1;
     ArbolHuffman<char> arbolHuffman;

    do {
        respuesta = ingresarComando();
        valor = identificarComando(respuesta);

        switch (valor) {
            //inicializar con archivo
            case 1:
                {
                    string nombreArchivo = separarEspacio(respuesta, true);
                    std::string textoDecodificado = arbolHuffman.decodificar(nombreArchivo);
                    leerArchivo(nombreArchivo);
                }
                break;
            //inicializar
            case 2:
                if(!risk.estadoPartida()){
                  inicializarJuego(&risk);
                  fortificar(&risk, true);
                  risk.turnosEnCero();
                  cout<<"\n-** El juego se ha inicializado correctamente. **-\n"<<endl;
                }else
                  cout<<"Esta partida ya ha sido inicializada"<<endl;

                break;
              //turno id_jugador
            case 3:
                turnoAux = separarEspacio(respuesta, true);

                if(!risk.estadoPartida()){
                    cout<<"-** Esta partida no ha sido inicializada correctamente **-\n";
                }else if (risk.estadoGanador()){
                    cout<<"-** Esta partida ya tuvo un ganador **-\n";
                }else if(risk.esTurnoJugador(turnoAux)){

                    turno (&risk);

                }else if (risk.jugadorExiste(turnoAux)){
                    cout<<"-** No es el turno del jugador <"<< turnoAux<<"> **-\n"; 
                }else
                    cout<<"-** El jugador <"<< turnoAux<<"> no forma parte de esta partida. **-\n";
                                   

                cout << "id_jugador " << turnoAux << endl;
                
                break;
              //salir
            case 4:
                salir = true;
                break;
                // guardar <nombre_archivo>
                 
            case 5: 
                {
                   string nombreArchivo = separarEspacio(respuesta, true);
                   std::string codigoCodificado = arbolHuffman.codificar(nombreArchivo);
                   
                   crearArchivo(nombreArchivo);
                   
                }
                break;
                // guardar_comprimido <nombre_archivo>
            case 6: 
                {
                    string nombreArchivo = separarEspacio(respuesta, true);
                    string nombreArchivoComprimido = nombreArchivo + ".zip";
                    crearArchivo(nombreArchivoComprimido);
                }
                break;
              //costo_conquista <territorio>
            case 7:
                cout << "comando exitoso\n" << "costo_conquista <territorio>\n";
                break;
              //conquista_mas_barata
            case 8:
                cout << "comando exitoso\n" << "conquista_mas_barata\n";
                break;

            case 9:
                cout << "comando exitoso" << endl;
                break;

            
            case 10:
                cout << "help <comando>: Proporciona información de ayuda para los comandos de Risk.\n\nComandos disponibles:\n";

              cout << "inicializar - Inicializa un nuevo juego" << endl;
  cout << "turno - Muestra el turno" << endl; 
  cout << "salir - Salir del programa" << endl;
  cout << "guardar -  Guarda el progreso" << endl;
  cout << "guardar_comprimido - Guarda el progreso en un formato .zip" << endl;
  cout << "costo_conquista - Muestra el costo de conquista de un territorio" << endl;
  cout << "conquista_mas_barata - Muestra costo de conquista mas barato" << endl;        
                break;

          case 11:
            mostrarAyudaComando(respuesta.substr(respuesta.find(' ')));
            break;

            default:
                cout << "\"" << respuesta << "\"" << " no se reconoce como un comando interno o parametros incorrectos.\n\n";
                break;
        }

    } while (salir == false);

    return 0;
}

//permite crear un archivo

void crearArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        cout << "La partida ha sido guardada correctamente.\n";
       
       
        archivo.close();
    } else {
        cout << "La partida no ha sido guardada correctamente";
    }
}

//permite leer la información de un archivo

void leerArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        cout << "Contenido del archivo \"" << nombreArchivo << "\":\n";
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "\"" << nombreArchivo << "\"" <<" no contiene información válida para inicializar el juego.\n";
    }
}

string separarEspacio(string cadena, bool parametro) {
    string comando = cadena;
    size_t separar = cadena.find(' ');

    if (separar != string::npos) {
        if (parametro == false) {
            comando = cadena.substr(0, separar);
        } else {
            comando = cadena.substr(separar + 1);
        }
    }
    return comando;
}

void mostrarAyudaComando(const string& comando) {
  string com = separarEspacio(comando, true);
  cout << endl;
    if (com == "inicializar") {
        cout << "inicializar <nombre_archivo>\n\n";
      infoInicializar();     
    } else if (com == "turno") {
        cout << "turno <id_jugador>\n\n";
      infoTurno();
    } else if (com == "salir") {
        cout << "salir <>\n\n";
      infoSalir();
    } else if (com == "guardar") {
        cout << "guardar <nombre_archivo>\n\n";
      infoGuardar();
    } else if (com == "guardar_comprimido") {
        cout << "guardar_comprimido <nombre_archivo>\n\n";
      infoGuardarComprimido();
    } else if (com == "costo_conquista") {
        cout << "costo_conquista <territorio>\n\n";
      infoCostoConquista();
    } else if (com == "conquista_mas_barata") {
        cout << "conquista_mas_barata <>\n\n";
      infoConquistaMasBarata();
    } else if (com == "help") {
        cout << "help <comando>\n\n";
    }  else {
        cout << "El comando \"" << com << "\" no tiene una descripción de ayuda.\n";
    }
}

void mensajeBienvenida() {
  system("cls");
    cout << "!Bienvenido a RISK?\nanimate a jugar :)\n";
}

string ingresarComando() {
    string cadena;
    cout << "\n$";
    getline(cin, cadena);
    return cadena;
}

//permite identificar si solo se ingréso un comando con un solo parametro 
bool qParametros(string respuesta) {
    int espacios = 0;
    string p2 = separarEspacio(separarEspacio(respuesta, true), 0);

    for (int i = 0; i < respuesta.length(); i++) {
        if (respuesta[i] == ' ') {
            espacios++;
        }
    }

    if (espacios == 1 && p2 != "") {
        return true;
    }

    return false;
}


//recibe la primera parte del comando ingresado por el usuario y identificar a cual tipo corresponde
int identificarComando(string cadena){
    //guarda lo que ingresa el usuario
    string respuesta = separarEspacio(cadena, false);
    int valor=0;

    if (respuesta == "inicializar" && qParametros(cadena) == true) { 
        valor=1;
    } else if(respuesta == "inicializar"){
        valor=2;
    } else if (respuesta == "turno" && qParametros(cadena) == true) {   
        valor=3;   
    } else if (respuesta == "salir") { 
        valor=4;
    } else if (respuesta == "guardar" && qParametros(cadena) == true) {
        valor=5;
    } else if (respuesta == "guardar_comprimido" && qParametros(cadena) == true) {
        valor=6;
    } else if (respuesta == "costo_conquista" && qParametros(cadena) == true) {
        valor=7;
    } else if (respuesta == "conquista_mas_barata") {
        valor=8;
    } else if (respuesta == "help" && qParametros(cadena) == true && separarEspacio(cadena, true)=="help"){
        valor=9;
    } else if (respuesta.substr(0, respuesta.find(' ')) == "help" && qParametros(cadena) == false){
        valor = 10;
    } else if (respuesta.substr(0, respuesta.find(' ')) == "help" && qParametros(cadena) == true) {
      valor = 11;
    }
    return valor;
}

void infoInicializar(void){
  cout << "Realiza las operaciones necesarias para inicializar el juego.\n\n El comando pregunta la cantidad de jugadores, para cada jugador su nombre o identificador, y luego, por turnos, pregunta a cada jugador en qué territorio desea ubicar sus unidades de ejército. \n\nEn cada turno, el jugador sólo puede indicar un único territorio a ocupar.\n" << endl;
}

void infoTurno(void){
  cout<<"Realiza las operaciones descritas dentro del turno de un jugador (obtener nuevas unidades, atacar y fortificar).\n\n El comando informa al jugador cuántas unidades adicionales puede reclamar luego pregunta en cuáles de sus territorios las quiere asignar y en qué cantidad.\n\n A continuación pregunta la configuración del ataque, desde cuál territorio y hacia cuál territorio, verificando las condiciones ya descritas.\n\n Luego informa los valores obtenidos con los dados, y la cantidad de unidades que se ganan o pierden. \n\nEste proceso se repite hasta que alguno de los dos territorios se quede sin unidades, o hasta que el atacante decida detenerse. \n\nFinalmente, el comando pregunta al jugador los territorios vecinos que desea seleccionar para la fortificación, así como la cantidad de unidades que se trasladarán de uno al otro.\n" << endl;
}

void infoSalir(void){
  cout<<"Termina la ejecución de la aplicación \n" << endl; 
}

void infoGuardar(void){ 
  cout<<"El estado actual del juego es guardado en un archivo de texto. \n\nEl archivo contiene la cantidad de jugadores, y para cada jugador almacena su nombre, su color de jugador, la cantidad de países que ocupa, el identificador de cada país junto con la cantidad de unidades de ejército en él, la cantidad de tarjetas que posee y el identificador de cada tarjeta.\n" << endl;

}

void infoGuardarComprimido(void){
  cout<< "El estado actual del juego es guardado en un archivo binario (con extensión .bin) con la información (nombre del jugador, cantidad de países que ocupa, identificador de cada país, cantidad de unidades de ejército en paises, tarjetas que posee, identificador de cada tarjeta) comprimida.\n" << endl;
}

void infoCostoConquista(void){
  cout<<"Calcula el costo y la secuencia de territorios a ser conquistados para lograr controlar el territorio dado por el usuario. \n\nEl territorio desde donde debe atacar debe ser aquel que el jugador tenga controlado más cerca al dado por el jugador. \n\nEsta información se analiza desde el punto de vista del jugador que tiene el turno de juego.\n" << endl;

}

void infoConquistaMasBarata(void){
  cout<<"En todos los territorios posibles, revisa cual puede implicar un menor número de unidades de ejército perdidas.\n\n Esta información se analiza desde el punto de vista del jugador que tiene el turno de juego." << endl;
}

void inicializarJuego(Risk* risk){
  int cantidadJugadores=0;
  string nombreJug="", continente="", territorio = "", auxTerritorios= "";
  bool continenteValido=true, territorioValido = true;
  //cambio el estado de la partida a true
  risk->iniciarPartida();
  //pide la cantidad de jugadores
  //hasta que esté entre 3 y 6
  do{
    cout<<"ingrese la cantidad de jugadores (3-6)"<<endl;
    cantidadJugadores = stoi(ingresarComando());
  }while(cantidadJugadores<3 || cantidadJugadores>6);

system("cls");
  for(int i=0; i<cantidadJugadores; i++){
    cout<<"Ingrese el nombre del jugador "<< i+1<<" : \n";
    nombreJug = ingresarComando();
    //creo un jugador en risk
    risk->CrearJugador(nombreJug, cantidadJugadores);
  }
  //verificar que se hace correctamente la incersión de datos
  
  cout<<risk->infoJug()<<endl;

  system ("cls");

  cout<<"\t -** Reclamar territorio **-"<<endl;
  do{
    cout<<"\n  Turno de: "<<risk->getNameJugadorEnTurno()<<"\n  Color: "<<risk->getColorJugadorEnTurno()<<"\n  FichasDisponibles: "<<risk->getFichasJugadorEnTurno()<<endl;
  //iniciarlizar tablero 
    cout<<"\tContinentes disponibles:"<<endl;
    
    cout<<risk->infoContinente()<<endl;
    
  
    do{
      cout<<"\tNombre del continente:"<<endl;
      continente = ingresarComando();
    
      auxTerritorios=risk->infoTerritorios(continente);
          
        if(auxTerritorios!=""){
            cout<<auxTerritorios;
            continenteValido=true;
        }else{
          cout<<"\tNo se reconoce el continente ingresado"<<endl;
          continenteValido=false;
        }
      
    }while(!continenteValido);
  
    do{
      cout<<"\tNombre del Territorio:"<<endl;
      territorio = ingresarComando();
    
      if(risk->estadoTerritorio(continente , territorio)){
          territorioValido=true;
      }else{
        cout<<"\tNo se reconoce el territorio ingresado"<<endl;
        territorioValido=false;
      }
      
    }while(!territorioValido);

    //mueve una ficha de un jugador al territorio del continente ingresado
    cout<<risk->infoJug()<<endl;

    //guardar el puntero hacia el territorio dentro del jugador para poder acceder a la informacion mas facil 
    Territorio* Nterritorio = risk->buscarTerritorio(continente,territorio);
    risk->agregarTerritorioaJugador(risk->getNameJugadorEnTurno(),Nterritorio);

    risk->moverFichasJugador(1, continente, territorio);

    cout<<risk->infoJug()<<endl;
    risk->turnoJugado();  
    system("cls");
  }while(risk->territoriosLibres());
}

void fortificar(Risk* risk, bool inicializar){
    string territorio = "", continente= "";
    int qFichas =0;

    cout<<"\n\t--**Ubicar Fichas disponibles**--"<<endl;

  do{
    cout<<"\n  Turno de Jugador: "<<risk->getNameJugadorEnTurno()
        <<"\n  Color: "<<risk->getColorJugadorEnTurno()
        <<"\n  Fichas disponibles: "<<risk->getFichasJugadorEnTurno()
        <<"\nTerritorios disponibles: \n"<<endl;

    cout<<risk->territoriosJugador();


    do{
        cout<<"Nombre territorio:\n";
        territorio = ingresarComando();
        continente = risk->buscarContinenteTerritorio(territorio);

        cout<<"continente: "<<continente<<endl;
        
        if(continente=="" || !risk->territorioJugador(continente, territorio)){
            cout<<"\n-** Nombre de territorio no valido **-\n\n";
        }

    }while(continente=="" || !risk->territorioJugador(continente, territorio));
    
    do{
        cout<<"Numero de fichas a mover: "<<endl;
        qFichas = stoi(ingresarComando());
    }while(qFichas>risk->getFichasJugadorEnTurno());
    

    risk->moverFichasJugador(qFichas, continente, territorio);

    if(inicializar && risk->getFichasJugadorEnTurno()==0)
        risk->turnoJugado();
        system("cls");
  }while(risk->getFichasJugadorEnTurno()!=0);

}


void turno (Risk* risk){
  //std::vector<Territorio*> territoriosJ =risk->getJugador(risk->getNameJugadorEnTurno())->getTerritorios();
       
       int qtropas=risk->NuevasTropas(risk->getJugador(risk->getNameJugadorEnTurno())) ;
     std::cout<<"jugador "<<risk->getNameJugadorEnTurno()<<"\n cantidad de tropas disponibles : "<<qtropas<<std::endl;
      //risk->ubicarNuevasTropas(int qtropas );


    if(risk->getFichasJugadorEnTurno()>0){

         // fortificar(risk, false);
    }else
        cout <<" ¡No se puede fortificar!\n  ¡Fichas insuficientes!";


    risk->turnoJugado();
}


