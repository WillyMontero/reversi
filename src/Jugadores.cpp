#include "Jugadores.h"
Jugadores::Jugadores()
{
}
void Jugadores::setNombre(int p,char n){
    nombre[p]=n;
}
char *Jugadores::getNombre(){
    return nombre;
}
void Jugadores::setPuntos(int p){
    puntos=p;
}
int Jugadores::getPuntos(){
    return puntos;
}
void Jugadores::setTurno(bool t){
    turno=t;
}
bool Jugadores::getTurno(){
    return turno;
}
Jugadores::~Jugadores()
{
    //dtor
}
