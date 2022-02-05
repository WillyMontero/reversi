#ifndef JUEGO_H
#define JUEGO_H
class Juego
{
    public:
        Juego();
        virtual ~Juego();
        void setEstado(int _est);
        int getEstado();
        void setColor(int _col);
        int getColor();
        void setComodin(int _c);
        int getComodin();
        void setXIzq(int _xIzq);
        int getXIzq();
        void setXDer(int _xDer);
        int getXDer();
        void setYArr(int _yArr);
        int getYArr();
        void setYAbj(int _YAbj);
        int getYAbj();
        void setPosF(int _posF);
        int getPosF();
        void setPosC(int _posC);
        int getPosC();
        void setJugadaC(int j);
        int getJugadaC();
        void setEfectoJ(int j);
        int getEfectoJ();

    protected:

    private:
        int xIzq;//coordenadas para el tablero
        int xDer;
        int yArr;
        int yAbj;

        int comodin;//1 si 2 no
        int posF;//posicion en matriz de 0,0 a 9,9
        int posC;

        int estado;//libre = -1 u ocupado = 1
        int color;// 15=blanco 0=negro 3=ninguno
        int jugadaC;//jugada correcta blancas=15, negras=0 no hay nada=-1

        int efectoJ;
};

#endif // JUEGO_H
