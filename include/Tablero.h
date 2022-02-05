#ifndef TABLERO_H
#define TABLERO_H
#include "Juego.h"
#include <stdlib.h>
#include <time.h>
#include "Jugadores.h"

class Tablero
{
    public:
        Tablero();//inicializa las pos del tablero, los comodines y las 4 fichas iniciales
        virtual ~Tablero();
        void comodines();//crea comodines
        void setCeldasJC(int f,int c,int jc);//set para las jugadas correctas
        void setCeldasC(int f,int c,int cl);
        void setCeldasEst(int f,int c,int e);
        void setCeldasCM(int f,int c,int cm);
        void setEfectoJ(int f,int c,int j);
        Juego getCeldas(int f,int c);//me devuelta cada celda y de ahi saco lo que ocupo para el juego
        int posFTablero(int x,int y);//me devuelve las pos de la fila
        int posCTablero(int x,int y);//me devuelve las pos de la columna

        void evaluarJC(Jugadores j1,Jugadores j2);//jugadas que puede hacer
        void comodinActivado(int fi,int co,int color,int colorActualCelda);//si vuelve una ficha donde hay comodin lo usa
        void volverFichas(Jugadores j1,Jugadores j2,int fi,int co);
        void reiniciar();
        int pasaTurno(Jugadores j1,Jugadores j2);

        void setNombre(int p,char n);
        char *getNombre();

        void inicializa_Var_efectoJ();
    protected:

    private:
        Juego celdas[10][10];//matriz de objetos de tipo Juego
        char nombre[10];
};

#endif // TABLERO_H
