#ifndef JUGADORES_H
#define JUGADORES_H
#include <string>
using namespace std;

class Jugadores
{
    public:
        Jugadores();
        virtual ~Jugadores();
        void setNombre(int p,char n);
        char *getNombre();
        void setPuntos(int p);
        int getPuntos();
        void setTurno(bool t);
        bool getTurno();

    protected:

    private:
        char nombre[8];
        int puntos;
        bool turno;
};

#endif // JUGADORES_H
