#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <winbgim.h>
#include "Tablero.h"
#include "Jugadores.h"
#include "Juego.h"

class Interfaz
{
    public:
        Interfaz();
        virtual ~Interfaz();
        //
        void imprimirInterfaz();
        void all();
        void refresca();
        void titulo(int n);
        //botones los parametros son para los colores de ellos
        void botonRegresar(int n);
        void botonSalir(int n);
        void botonJugar(int n);
        void botonCargar(int n);
        void botonAcercaD(int n);
        void botonInfo(int n);
        void botonReglas(int n);
        void botonGuardar();
        void botonReiniciar();
        //jugadores
        void rifaTurno(Jugadores &j1,Jugadores &j2);
        void pideNombres(Jugadores &j1,Jugadores &j2);
        void jugadores(Jugadores j1,Jugadores j2);//muestra el nombre de los jugadores
        void puntaje(Tablero t,Jugadores j1,Jugadores j2);//muestra el puntaje en tiempo real
        void turno(Jugadores j1,Jugadores j2);//listo
        void ganador(Tablero t,Jugadores j1,Jugadores j2);
        void ganador2(Tablero t,Jugadores j1,Jugadores j2);
        void msjPasaTurno(Jugadores j);
        //efectos
        void tablero();//estetica
        void cambiarColorTablero(int n);
        void pintarTablero(int n,Tablero t);//cambia el color al tablero el t es para acomodar el tablero
        void efectosComodines(int cm,Tablero t);
        void efectoBotones(bool jc,bool aCD,bool aC,bool jr);
        void efectoGuardar();
        void mostrarJugadas(int c);//pone si o no en la parte grafica
        //actualiza
        void actualizaTablero(Tablero t);//actualiza jugadas
        void muestraJC(Tablero t,Jugadores j1,Jugadores j2,int c);
        void refrescaJC(Tablero t,Jugadores j1,Jugadores j2);
        //Guardar y cargar
        void nombreGuardar(Tablero &t);
        string nombreCargar();//retorna el nombre digitado
        void msjPartidaNoEncontrada();
        void msjPartidaEncontrada();
        void msjNoPartidaG();
};
#endif // INTERFAZ_H
