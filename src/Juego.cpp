#include "Juego.h"
Juego::Juego()
{
    //
}
void Juego::setEstado(int _est){
    estado=_est;
}
int Juego::getEstado(){
    return estado;
}
void Juego::setColor(int _col){
    color=_col;
}
int Juego::getColor(){
    return color;
}
void Juego::setComodin(int _c){
    comodin=_c;
}
int Juego::getComodin(){
    return comodin;
}
void Juego::setXIzq(int _xIzq){
    xIzq=_xIzq;
}
int Juego::getXIzq(){
    return xIzq;
}
void Juego::setXDer(int _xDer){
    xDer=_xDer;
}
int Juego::getXDer(){
    return xDer;
}
void Juego::setYArr(int _yArr){
    yArr=_yArr;
}
int Juego::getYArr(){
    return yArr;
}
void Juego::setYAbj(int _YAbj){
    yAbj=_YAbj;
}
int Juego::getYAbj(){
    return yAbj;
}
void Juego::setPosF(int _posF){
    posF=_posF;
}
int Juego::getPosF(){
    return posF;
}
void Juego::setPosC(int _posC){
    posC=_posC;
}
int Juego::getPosC(){
    return posC;
}
void Juego::setJugadaC(int j){
    jugadaC=j;
}
int Juego::getJugadaC(){
    return jugadaC;
}
void Juego::setEfectoJ(int j){
    efectoJ=j;
}
int Juego::getEfectoJ(){
    return efectoJ;
}
Juego::~Juego()
{
    //dtor
}
