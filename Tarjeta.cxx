#include "Carta.h"

Carta::Carta(  std::string tipoCarta,  std::string territorio,  std::string ficha,  std::string mision){
    this->tipoCarta = tipoCarta;
    this->territorio = territorio;
    this->ficha = ficha;
    this->mision = mision;

    
}
// get tipo carta
std::string Carta::obtenerTipoCarta() {
    return tipoCarta;
}
//set tipo de carta
void Carta::establecerTipoCarta(std::string nuevoTipo) {
    tipoCarta = nuevoTipo;
}
// get territorio
std::string Carta::obtenerTerritorio() {
    return territorio;
}
//set territorio
void Carta::establecerTerritorio(std::string nuevoTerritorio) {
    territorio = nuevoTerritorio;
}
// get ficha 
std::string Carta::obtenerFicha() {
    return ficha;
}
//set ficha
void Carta::establecerFicha(std::string nuevaFicha) {
    ficha = nuevaFicha;
}
//get msion
std::string Carta::obtenerMision() {
    return mision;
}
//set mision
void Carta::establecerMision(std::string nuevaMision) {
    mision = nuevaMision;
}
