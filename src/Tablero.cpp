#include "Tablero.h"
#include <iostream>
#include <string.h>
using namespace std;
Tablero::Tablero()
{
    int f=0;//variables de las posiciones de la matriz segun sus coordenadas
    int c=0;
    int xI=30;//variables de las coordenadas
    int xD=80;
    int yR=60;
    int yB=110;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            celdas[i][j].setXIzq(xI);
            celdas[i][j].setXDer(xD);
            celdas[i][j].setYArr(yR);
            celdas[i][j].setYAbj(yB);
            xI=xD;
            xD=xD+50;
            celdas[i][j].setPosF(f);
            celdas[i][j].setPosC(c);
            c+=1;
            celdas[i][j].setComodin(2);
            celdas[i][j].setColor(3);
            celdas[i][j].setEstado(-1);
            celdas[i][j].setJugadaC(-1);
        }
        c=0;
        f+=1;
        xI=30;
        xD=80;
        yR=yB;
        yB=yB+50;
    }
    comodines();
    celdas[4][4].setEstado(1);//4 fichas iniciales
    celdas[4][5].setEstado(1);
    celdas[5][4].setEstado(1);
    celdas[5][5].setEstado(1);
    celdas[4][4].setColor(15);//color de ellas
    celdas[4][5].setColor(0);
    celdas[5][4].setColor(0);
    celdas[5][5].setColor(15);
}
int Tablero::posFTablero(int x,int y){
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(x>celdas[i][j].getXIzq() && x<celdas[i][j].getXDer() && y>celdas[i][j].getYArr() && y<celdas[i][j].getYAbj()) return celdas[i][j].getPosF();
}
int Tablero::posCTablero(int x,int y){
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(x>celdas[i][j].getXIzq() && x<celdas[i][j].getXDer() && y>celdas[i][j].getYArr() && y<celdas[i][j].getYAbj()) return celdas[i][j].getPosC();
}
void Tablero::setCeldasJC(int f,int c,int jc){
    celdas[f][c].setJugadaC(jc);
}
void Tablero::setCeldasC(int f,int c,int cl){
    celdas[f][c].setColor(cl);
}
void Tablero::setCeldasEst(int f,int c,int e){
    celdas[f][c].setEstado(e);
}
void Tablero::setCeldasCM(int f,int c,int cm){
    celdas[f][c].setComodin(cm);
}
void Tablero::setEfectoJ(int f,int c,int j){
    celdas[f][c].setEfectoJ(j);
}
Juego Tablero::getCeldas(int f,int c){
    return celdas[f][c];
}
void Tablero::comodines(){
    srand(time(0));
    celdas[1+(rand()%2)][1+(rand()%2)].setComodin(1);
    celdas[1+(rand()%3)][4+(rand()%2)].setComodin(1);
    celdas[1+(rand()%2)][7+(rand()%2)].setComodin(1);
    celdas[4+(rand()%2)][1+(rand()%3)].setComodin(1);
    celdas[4+(rand()%2)][6+(rand()%3)].setComodin(1);
    celdas[7+(rand()%2)][1+(rand()%2)].setComodin(1);
    celdas[6+(rand()%3)][4+(rand()%2)].setComodin(1);
    celdas[7+(rand()%2)][7+(rand()%2)].setComodin(1);
}
void Tablero::evaluarJC(Jugadores j1,Jugadores j2){
    int colorCasilla;
    int colorFicha;
    int valorJcFicha;
    if(j1.getTurno()){
        colorCasilla=15;
        colorFicha=0;
        valorJcFicha=15;
    }
    if(j2.getTurno()){
        colorCasilla=0;
        colorFicha=15;
        valorJcFicha=0;
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            celdas[i][j].setJugadaC(-1);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            /////////////////////////////////////////////////////////////////////////////////////////////
            if(celdas[i][j].getColor()==colorCasilla){//evalua jugadas correctas en horizontal y vertical
                if(celdas[i][j-1].getColor()==colorFicha){//evalua izq
                    for(int c=j-2;c>=0;c--){
                        if(celdas[i][c].getEstado()==-1){
                            celdas[i][c].setJugadaC(valorJcFicha);
                            break;
                        }
                        if(celdas[i][c].getColor()==colorCasilla) break;
                    }
                }
                if(celdas[i-1][j].getColor()==colorFicha){//arriba
                    for(int f=i-2;f>=0;f--){
                        if(celdas[f][j].getEstado()==-1){
                            celdas[f][j].setJugadaC(valorJcFicha);
                            break;
                        }
                        if(celdas[f][j].getColor()==colorCasilla) break;
                    }
                }
                if(celdas[i][j+1].getColor()==colorFicha){//derecha
                    for(int c=j+2;c<=9;c++){
                        if(celdas[i][c].getEstado()==-1){
                            celdas[i][c].setJugadaC(valorJcFicha);
                            break;
                        }
                        if(celdas[i][c].getColor()==colorCasilla) break;
                    }
                }
                if(celdas[i+1][j].getColor()==colorFicha){//abajo
                    for(int f=i+2;f<=9;f++){
                        if(celdas[f][j].getEstado()==-1){
                            celdas[f][j].setJugadaC(valorJcFicha);
                            break;
                        }
                        if(celdas[f][j].getColor()==colorCasilla) break;
                    }
                }
            }
            ///////////////////////////////////////////////////////////////////////////////////
            //evalua DIAGONALES
            if(celdas[i][j].getColor()==colorCasilla){//NorOeste
                if(celdas[i-1][j-1].getColor()==colorFicha){
                    if(i>=j&&j-1>0){//parte de abajo, la parte de la derecha me dice lo importante
                        for(int f=i-2,c=j-2;c>=0;f--,c--){
                            if(celdas[f][c].getEstado()==-1){
                                celdas[f][c].setJugadaC(valorJcFicha);
                                break;
                            }
                            if(celdas[f][c].getColor()==colorCasilla) break;
                        }
                    }//las dos partes
                    if(i<j&&i-1>0){//parte de arriba
                        for(int f=i-2,c=j-2;f>=0;f--,c--){
                            if(celdas[f][c].getEstado()==-1){
                                celdas[f][c].setJugadaC(valorJcFicha);
                                break;
                            }
                            if(celdas[f][c].getColor()==colorCasilla) break;
                        }
                    }
                }
            }
            if(celdas[i][j].getColor()==colorCasilla){//SurOeste
                if(celdas[i+1][j-1].getColor()==colorFicha){
                    for(int f=i+2,c=j-2;f<=9||c>=0;f++,c--){
                        if(f>9)break;//si se sale de los limites
                        if(c<0)break;
                        if(celdas[f][c].getEstado()==-1){
                            celdas[f][c].setJugadaC(valorJcFicha);
                            break;
                        }
                        if(celdas[f][c].getColor()==colorCasilla) break;
                    }
                }
            }
            if(celdas[i][j].getColor()==colorCasilla){//NorEste
                if(celdas[i-1][j+1].getColor()==colorFicha){
                    for(int f=i-2,c=j+2;f>=0||c<=9;f--,c++){
                        if(f<0)break;
                        if(c>9)break;
                        if(celdas[f][c].getEstado()==-1){
                            celdas[f][c].setJugadaC(valorJcFicha);
                            break;
                        }
                        if(celdas[f][c].getColor()==colorCasilla) break;
                    }
                }
            }
            if(celdas[i][j].getColor()==colorCasilla){//SurEste
                if(celdas[i+1][j+1].getColor()==colorFicha){
                    if(i>=j&&i+1<9){//parte de abajo
                        for(int f=i+2,c=j+2;f<=9;f++,c++){
                            if(celdas[f][c].getEstado()==-1){
                                celdas[f][c].setJugadaC(valorJcFicha);
                                break;
                            }
                            if(celdas[f][c].getColor()==colorCasilla) break;
                        }
                    }
                    if(i<j&&j+1<9){//parte de abajo
                        for(int f=i+2,c=j+2;c<=9;f++,c++){
                            if(celdas[f][c].getEstado()==-1){
                                celdas[f][c].setJugadaC(valorJcFicha);
                                break;
                            }
                            if(celdas[f][c].getColor()==colorCasilla) break;
                        }
                    }
                }
            }
            /////////////////////////////////////////////////////////////////////////////////////
        }
    }
}
void Tablero::comodinActivado(int fi,int co,int color,int colorActualCelda){
    for(int k=co-1;k<=co+1;k++){
        if(celdas[fi-1][k].getColor()==colorActualCelda){
            celdas[fi-1][k].setColor(color);
            celdas[fi-1][k].setEstado(1);
            celdas[fi-1][k].setEfectoJ(2);
        }
        if(celdas[fi+1][k].getColor()==colorActualCelda){
            celdas[fi+1][k].setColor(color);
            celdas[fi+1][k].setEstado(1);
            celdas[fi+1][k].setEfectoJ(2);
        }
    }
    if(celdas[fi][co-1].getColor()==colorActualCelda){
        celdas[fi][co-1].setColor(color);
        celdas[fi][co-1].setEstado(1);
        celdas[fi][co-1].setEfectoJ(2);
    }
    if(celdas[fi][co+1].getColor()==colorActualCelda){
        celdas[fi][co+1].setColor(color);
        celdas[fi][co+1].setEstado(1);
        celdas[fi][co+1].setEfectoJ(2);
    }
}
void Tablero::volverFichas(Jugadores j1,Jugadores j2,int fi,int co){//REVISAR DIAGONALES
    int colorActualCelda;
    int colorN;
    if(j1.getTurno()){
        colorActualCelda=0;
        colorN=15;
    }
    if(j2.getTurno()){
        colorActualCelda=15;
        colorN=0;
    }
    //////////////////////////////////////////HORIZONTAL Y VERTICALMENTE///////////////////////////////
    int fl=fi;
    int cl=co;
    if(celdas[fl][cl+1].getColor()==colorActualCelda){
        while(true){//vuelve las fichas del lado izq
            if(celdas[fl][cl+1].getColor()==colorActualCelda&&cl+1<=8){//si es blanco
                if(celdas[fl][cl+2].getColor()==colorN){//si a la par tiene una blanca si no no hace nada
                    for(int i=co;i<=cl+1;i++){
                        if(i>co&&celdas[fl][i].getComodin()==1) comodinActivado(fl,i,colorN,colorActualCelda);
                        setCeldasC(fl,i,colorN);
                        setCeldasEst(fl,i,1);
                        setCeldasJC(fl,i,-1);
                        setEfectoJ(fl,i,1);
                    }
                    break;
                }
            }
            if(celdas[fl][cl+1].getEstado()!=1)break;
            cl+=1;
        }

    }
    cl=co;//
    fl=fi;
    if(celdas[fl+1][cl].getColor()==colorActualCelda){
        while(true){//vuelve arriba
            if(celdas[fl+1][cl].getColor()==colorActualCelda&&fl+1<=8){
                if(celdas[fl+2][cl].getColor()==colorN){
                    for(int i=fi;i<=fl+1;i++){
                        if(i>fi&&celdas[i][cl].getComodin()==1) comodinActivado(i,cl,colorN,colorActualCelda);
                        setCeldasC(i,cl,colorN);
                        setCeldasEst(i,cl,1);
                        setCeldasJC(i,cl,-1);
                        setEfectoJ(i,cl,1);
                    }
                    break;
                }
            }
            if(celdas[fl+1][cl].getEstado()!=1) break;
            fl+=1;
        }
    }
    cl=co;
    fl=fi;
    if(celdas[fl-1][cl].getColor()==colorActualCelda){
        while(true){//vuelve abajo
            if(celdas[fl-1][cl].getColor()==colorActualCelda&&fl-1>=1){
                if(celdas[fl-2][cl].getColor()==colorN){
                    for(int i=fi;i>=fl-1;i--){
                        if(i<fi&&celdas[i][cl].getComodin()==1) comodinActivado(i,cl,colorN,colorActualCelda);
                        setCeldasC(i,cl,colorN);
                        setCeldasEst(i,cl,1);
                        setCeldasJC(i,cl,-1);
                        setEfectoJ(i,cl,1);
                    }
                    break;
                }
            }
            if(celdas[fl-1][cl].getEstado()!=1) break;
            fl=fl-1;
        }
    }
    cl=co;
    fl=fi;
    if(celdas[fl][cl-1].getColor()==colorActualCelda){
        while(true){//vuelve las fichas del lado derecho
            if(celdas[fl][cl-1].getColor()==colorActualCelda&&cl-1>=1){
                if(celdas[fl][cl-2].getColor()==colorN){
                    for(int i=co;i>=cl-1;i--){
                        if(i<co&&celdas[fl][i].getComodin()==1) comodinActivado(fl,i,colorN,colorActualCelda);
                        setCeldasC(fl,i,colorN);
                        setCeldasEst(fl,i,1);
                        setCeldasJC(fl,i,-1);
                        setEfectoJ(fl,i,1);
                    }
                    break;
                }
            }
            if(celdas[fl][cl-1].getEstado()!=1) break;
            cl-=1;
        }
    }
    //////////////////////////////////////DIAGONALES/////////////////////////////////////////////
    cl=co;
    fl=fi;
    if(celdas[fl+1][cl+1].getColor()==colorActualCelda){//NorOeste
        if(fl>=cl){
            while(true){
                if(fl>7)break;
                if(celdas[fl+1][cl+1].getColor()==colorActualCelda){
                if(celdas[fl+2][cl+2].getColor()==colorN){
                    for(int i=fi,j=co;i<=fl+1;i++,j++){
                        if(i>fi&&celdas[i][j].getComodin()==1) comodinActivado(i,j,colorN,colorActualCelda);
                        setCeldasC(i,j,colorN);
                        setCeldasEst(i,j,1);
                        setCeldasJC(i,j,-1);
                        setEfectoJ(i,j,1);
                    }
                    break;
                }
            }
            if(celdas[fl+1][cl+1].getEstado()!=1) break;
            fl+=1;
            cl+=1;
            }
        }
        if(cl>fl){
            while(true){
                if(cl>7)break;
                if(celdas[fl+1][cl+1].getColor()==colorActualCelda){
                if(celdas[fl+2][cl+2].getColor()==colorN){
                    for(int i=fi,j=co;j<=cl+1;i++,j++){
                        if(i>fi&&celdas[i][j].getComodin()==1) comodinActivado(i,j,colorN,colorActualCelda);
                        setCeldasC(i,j,colorN);
                        setCeldasEst(i,j,1);
                        setCeldasJC(i,j,-1);
                        setEfectoJ(i,j,1);
                    }
                    break;
                }
            }
            if(celdas[fl+1][cl+1].getEstado()!=1) break;
            fl+=1;
            cl+=1;
            }
        }
    }
    cl=co;
    fl=fi;
    if(celdas[fl-1][cl+1].getColor()==colorActualCelda){//NorEste
        while(true){
            if(cl>7)break;
            if(fl<2)break;
            if(celdas[fl-1][cl+1].getColor()==colorActualCelda){
                if(celdas[fl-2][cl+2].getColor()==colorN){
                    for(int i=fi,j=co;j<=cl+1;i--,j++){
                        if(j>co&&celdas[i][j].getComodin()==1) comodinActivado(i,j,colorN,colorActualCelda);
                        setCeldasC(i,j,colorN);
                        setCeldasEst(i,j,1);
                        setCeldasJC(i,j,-1);
                        setEfectoJ(i,j,1);
                    }
                    break;
                }
            }
            if(celdas[fl-1][cl+1].getEstado()!=1) break;
            fl-=1;
            cl+=1;
        }
    }
    cl=co;
    fl=fi;
    if(celdas[fl+1][cl-1].getColor()==colorActualCelda){//SurOeste
        while(true){
            if(fl>7)break;
            if(cl<2)break;
            if(celdas[fl+1][cl-1].getColor()==colorActualCelda){
                if(celdas[fl+2][cl-2].getColor()==colorN){
                    for(int i=fi,j=co;j>=cl-1;i++,j--){
                        if(i>fi&&celdas[i][j].getComodin()==1) comodinActivado(i,j,colorN,colorActualCelda);
                        setCeldasC(i,j,colorN);
                        setCeldasEst(i,j,1);
                        setCeldasJC(i,j,-1);
                        setEfectoJ(i,j,1);
                    }
                    break;
                }
            }
            if(celdas[fl+1][cl-1].getEstado()!=1) break;
            fl+=1;
            cl-=1;
        }
    }
    cl=co;
    fl=fi;
    if(celdas[fl-1][cl-1].getColor()==colorActualCelda){//SurEste
        if(fl>=cl){
            while(true){
                if(cl<2)break;
                if(celdas[fl-1][cl-1].getColor()==colorActualCelda){
                    if(celdas[fl-2][cl-2].getColor()==colorN){
                        for(int i=fi,j=co;j>=cl-1;i--,j--){
                            if(i<fi&&celdas[i][j].getComodin()==1) comodinActivado(i,j,colorN,colorActualCelda);
                            setCeldasC(i,j,colorN);
                            setCeldasEst(i,j,1);
                            setCeldasJC(i,j,-1);
                            setEfectoJ(i,j,1);
                        }
                        break;
                    }
                }
                if(celdas[fl-1][cl-1].getEstado()!=1) break;
                fl-=1;
                cl-=1;
            }
        }
        if(cl>fl){
            while(true){
                if(fl<2)break;
                if(celdas[fl-1][cl-1].getColor()==colorActualCelda){
                    if(celdas[fl-2][cl-2].getColor()==colorN){
                        for(int i=fi,j=co;i>=fl-1;i--,j--){
                            if(i<fi&&celdas[i][j].getComodin()==1) comodinActivado(i,j,colorN,colorActualCelda);
                            setCeldasC(i,j,colorN);
                            setCeldasEst(i,j,1);
                            setCeldasJC(i,j,-1);
                            setEfectoJ(i,j,1);
                        }
                        break;
                    }
                }
            if(celdas[fl-1][cl-1].getEstado()!=1) break;
            fl-=1;
            cl-=1;
            }
        }
    }
}
int Tablero::pasaTurno(Jugadores j1,Jugadores j2){
    int cont=0;//contador para las jugadas correctas
    int est=0;//si es 0 no hay nada que hacer
    int contFB=0;//si hay 0 no hay nada que hacer
    int contFN=0;//si hay 0 no hay nada que hacer

    int evalJC;//valor de jugadaCorrecta segun turno
    if(j1.getTurno()) evalJC=15;
    if(j2.getTurno()) evalJC=0;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(celdas[i][j].getJugadaC()==evalJC) cont+=1;//si no tiene jugadas correctas
            if(celdas[i][j].getEstado()==-1) est+=1;
            if(celdas[i][j].getColor()==15) contFB+=1;
            if(celdas[i][j].getColor()==0) contFN+=1;
        }
    }

    if(j1.getTurno() && contFN!=0 && est!=0 && cont==0) return 1;

    if(j2.getTurno() && contFB!=0 && est!=0 && cont==0) return 1;
}
void Tablero::reiniciar(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            setCeldasC(i,j,3);
            setCeldasEst(i,j,-1);
            setCeldasJC(i,j,-1);
        }
    }
    celdas[4][4].setEstado(1);//4 fichas iniciales
    celdas[4][5].setEstado(1);
    celdas[5][4].setEstado(1);
    celdas[5][5].setEstado(1);
    celdas[4][4].setColor(15);//color de ellas
    celdas[4][5].setColor(0);
    celdas[5][4].setColor(0);
    celdas[5][5].setColor(15);
}
Tablero::~Tablero()
{
    //dtor
}
void Tablero::setNombre(int p,char n){
    nombre[p]=n;
}
char *Tablero::getNombre(){
    return nombre;
}
void Tablero::inicializa_Var_efectoJ(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            celdas[i][j].setEfectoJ(0);
        }
    }
}
