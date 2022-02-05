#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <winbgim.h>
#include <cstdio>
#include "Tablero.h"
class Archivos
{
    public:
        Archivos();
        virtual ~Archivos();
        void reglas();
        void info();
        void guardar(Tablero t,Jugadores j1,Jugadores j2);
        void cargar(Tablero &t,Jugadores &j1,Jugadores &j2,string n,bool &nomb);

    protected:

    private:
};

#endif // ARCHIVOS_H
