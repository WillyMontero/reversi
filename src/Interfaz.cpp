#include "Interfaz.h"
#include <time.h>
#include <stdio.h>//para la conversion de int a char
#include <iostream>
#include <string.h>
using namespace std;
Interfaz::Interfaz()
{
    //ctor
}
void Interfaz::imprimirInterfaz(){
    initwindow(800,600);
    setbkcolor(7);
}
void Interfaz::refresca(){
    cleardevice();
}
void Interfaz::titulo(int n){
    setcolor(n);
    settextstyle(4,HORIZ_DIR,6);//LETRA GRANDE
    outtextxy(235,50,"REVERSI");
    settextstyle(8,0,1);//define el tipo de letra
    setcolor(0);
}
//botones
void Interfaz::botonJugar(int n){
    setcolor(n);
    rectangle(255,210,345,240);
    outtextxy(270,215,"Jugar");
}
void Interfaz::botonCargar(int n){
    setcolor(n);
    rectangle(255,250,345,280);
    outtextxy(262,255,"Cargar");
}
void Interfaz::botonAcercaD(int n){
    setcolor(n);
    rectangle(370,210,500,240);
    outtextxy(375,215,"Acerca de..");
}
void Interfaz::botonInfo(int n){
    setcolor(n);
    rectangle(385,250,470,280);
    outtextxy(400,255,"Info");
}
void Interfaz::botonReglas(int n){
    setcolor(n);
    rectangle(385,290,470,320);
    outtextxy(395,295,"Reglas");
}
void Interfaz::botonRegresar(int n){
    setcolor(n);
    rectangle(30,25,130,55);
    outtextxy(35,30,"Regresar");
}
void Interfaz::botonSalir(int n){
    setcolor(n);
    rectangle(660,490,730,520);
    outtextxy(665,495,"Salir");
}
void Interfaz::botonGuardar(){
    setcolor(0);
    rectangle(565,490,650,520);
    outtextxy(570,495,"Guardar");
}
void Interfaz::botonReiniciar(){
    setcolor(0);
    rectangle(565,450,675,480);
    outtextxy(570,455,"Reiniciar");
}
void Interfaz::all(){//ventana de inicio
    refresca();
    titulo(0);
    botonSalir(0);
    botonJugar(0);
    botonCargar(0);
    botonAcercaD(0);
    tablero();
}
//jugadores
void Interfaz::rifaTurno(Jugadores &j1,Jugadores &j2){
    int t;//variable para saber quien empieza
    srand(time(0));
    t=rand()%10+1;

    if(t<=5){
        j1.setTurno(true);
        j2.setTurno(false);
    }
    if(t>5){
        j2.setTurno(true);
        j1.setTurno(false);
    }
}
void Interfaz::pideNombres(Jugadores &j1,Jugadores &j2){
    char nom[8];//variables para el nombre de los jugadores
    char tecla;
    setcolor(1);
    for(int i=0;i<8;i++) nom[i]=' ';
    outtextxy(255,310,"Nombres de los jugadores: ");
    outtextxy(290,340,"Jugador 1: ");
    for(int i=0;i<8;i++){
        tecla = getch();
        if(tecla==8){
            outtextxy(415,340,"        ");
            i=-1;
            for(int i=0;i<8;i++){
                nom[i]=' ';
                j1.setNombre(i,' ');
            }
            continue;
        }
        if(tecla==13) break;
        nom[i]=tecla;
        j1.setNombre(i,tecla);
        moveto(415,340);
        outtext(j1.getNombre());
    }
    for(int i=0;i<8;i++)nom[i]=' ';
    setcolor(1);
    outtextxy(290,370,"Jugador 2: ");
    for(int i=0;i<8;i++){
        tecla = getch();
        if(tecla==8){
            moveto(415,370);
            outtext("        ");
            i=-1;
            for(int i=0;i<8;i++){
                nom[i]=' ';
                j2.setNombre(i,' ');
            }
            continue;
        }
        if(tecla==13) break;
        nom[i]=tecla;
        j2.setNombre(i,tecla);
        moveto(415,370);
        outtext(j2.getNombre());
    }
}
void Interfaz::jugadores(Jugadores j1,Jugadores j2){
    setcolor(0);
    settextstyle(4,HORIZ_DIR,2);
    outtextxy(560,20,"JUGADORES");
    settextstyle(3,HORIZ_DIR,1);
    setcolor(4);
    outtextxy(620,104,"-VS-");
    setcolor(0);
    settextstyle(8,0,3);
    outtextxy(595,68,j1.getNombre());
    outtextxy(595,134,j2.getNombre());
    settextstyle(8,0,1);
}
void Interfaz::puntaje(Tablero t,Jugadores j1,Jugadores j2){
    int contP1=0;
    int contP2=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(t.getCeldas(i,j).getEstado()==1){//si hay ficha o no
                if(t.getCeldas(i,j).getColor()==0){
                    contP2+=1;
                }
                if(t.getCeldas(i,j).getColor()==15){
                    contP1+=1;
                }
            }
        }
    }
    settextstyle(8,0,1);
    j1.setPuntos(contP1);
    j2.setPuntos(contP2);
    char p[1];
    setcolor(0);
    sprintf(p, "%d",j1.getPuntos());//conversion de int a char
    rectangle(730,60,770,100);
    outtextxy(740,72,"  ");//evita error de puntaje
    outtextxy(740,72,p);
    sprintf(p, "%d",j2.getPuntos());
    rectangle(730,125,770,165);
    outtextxy(740,137,"  ");
    outtextxy(740,137,p);
}
void Interfaz::ganador(Tablero t,Jugadores j1,Jugadores j2){
    int contEsd=0;
    int contFB=0;
    int contFN=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(t.getCeldas(i,j).getEstado()==1){//si hay ficha o no
                contEsd+=1;
                if(t.getCeldas(i,j).getColor()==0) contFN+=1;
                if(t.getCeldas(i,j).getColor()==15) contFB+=1;
            }
        }
    }
    if(contEsd==100&&contFB>50){
        setcolor(0);
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(560,250,"GANADOR");
        outtextxy(580,280,j1.getNombre());
    }
    if(contEsd==100&&contFN>50){
        setcolor(0);
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(560,250,"GANADOR");
        outtextxy(580,280,j2.getNombre());
    }
    if(contFN==50&&contFB==50){
        setcolor(0);
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(560,250,"EMPATE!!");
    }
    if(contFB==0&&contFN>0){//si el otro se queda sin fichas
        setcolor(0);
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(560,250,"GANADOR");
        outtextxy(580,280,j2.getNombre());
    }
    if(contFN==0&&contFB>0){
        setcolor(0);
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(560,250,"GANADOR");
        outtextxy(580,280,j1.getNombre());
    }
    if(contEsd==4){
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(560,250,"                     ");
        outtextxy(580,280,"                     ");
    }
    settextstyle(8,0,1);
}
void Interfaz::ganador2(Tablero t,Jugadores j1,Jugadores j2){
    int contFB=0;
    int contFN=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(t.getCeldas(i,j).getEstado()==1){//si hay ficha o no
                if(t.getCeldas(i,j).getColor()==0) contFN+=1;
                if(t.getCeldas(i,j).getColor()==15) contFB+=1;
            }
        }
    }
    if(contFB>contFN){
        setcolor(0);
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(560,250,"GANADOR");
        outtextxy(580,280,j1.getNombre());
    }
    if(contFN>contFB){
        setcolor(0);
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(560,250,"GANADOR");
        outtextxy(580,280,j2.getNombre());
    }
    if(contFN==contFB){
        setcolor(0);
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(560,250,"EMPATE!!");
    }
    settextstyle(8,0,1);
}
void Interfaz::turno(Jugadores j1,Jugadores j2){//turno real de los jugadores
    if(j1.getTurno()){
        setcolor(7);
        for(int i=0;i<15;i++) circle(565,148,i);
        setcolor(15);
        for(int i=0;i<15;i++) circle(565,83,i);
    }
    else{
        setcolor(7);
        for(int i=0;i<15;i++) circle(565,83,i);
        setcolor(0);
        for(int i=0;i<15;i++) circle(565,148,i);
    }
}
void Interfaz::msjPasaTurno(Jugadores j){
    setcolor(4);
    outtextxy(580,305,j.getNombre());
    outtextxy(550,335,"Pasa el turno porque");
    outtextxy(550,365,"No tiene jugada.");
    Sleep(2000);
    setcolor(7);
    outtextxy(580,305,j.getNombre());
    outtextxy(550,335,"Pasa el turno porque");
    outtextxy(550,365,"No tiene jugada.");
}
//efectos
void Interfaz::mostrarJugadas(int c){
    setcolor(0);
    outtextxy(570,190,"Mostrar");
    outtextxy(570,210,"Jugadas?");
    rectangle(670,195,700,225);
    if(c%2==1) outtextxy(675,200,"SI");
    if(c%2==0) outtextxy(675,200,"NO");
}
void Interfaz::efectoGuardar(){
    setcolor(0);
    srand(time(0));
    for(int i=565;i<750;i++){
        rectangle(i,530,i+1,550);
        Sleep(4+(rand()%5));
    }
    setcolor(7);
    for(int i=565;i<750;i++) rectangle(i,530,i+1,550);
    setcolor(0);
    outtextxy(565,530,"Juego Guardado!");
    Sleep(1000);
    outtextxy(565,530,"               ");
}
void Interfaz::tablero(){//tablero de estetica
    setcolor(0);
    int izq=40;
    int der=80;
    int arr=340;
    int abj=520;
    int c1=385;
    setfillstyle(USER_FILL,8);
    bar(40,340,200,520);
    for(int i=0;i<4;i++){
        rectangle(izq,arr,der,abj);
        line(40,c1,200,c1);
        izq=der;
        der=der+40;
        c1=c1+45;
    }
    for(int i=0;i<15;i++){
        circle(140,410,i);
        circle(100,450,i);
    }
    for(int i=0;i<15;i++){
        setcolor(15);
        circle(100,410,i);
        circle(140,450,i);
    }
}
void Interfaz::pintarTablero(int n,Tablero t){//tablero donde se juega
    //cleardevice();//si se quita no parpadea el juego cuando se cambia de color
    int c1=0;
    int c2=0;
    //cambio de color del tablero
    if(n==1){
        c1=0;
        c2=8;
    }
    if(n==2){
        c1=12;
        c2=4;
    }
    if(n==3){
        c1=10;
        c2=2;
    }
    if(n==4){
        c1=9;
        c2=1;
    }
    if(n==5){
        c1=0;
        c2=5;
    }
    if(n==6){
        c1=0;
        c2=6;
    }
    setfillstyle(USER_FILL,c1);//bar del tablero
    bar(26,57,534,564);
    setfillstyle(USER_FILL,c2);
    bar(30,60,530,560);
    setcolor(0);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            rectangle(t.getCeldas(i,j).getXIzq(),t.getCeldas(i,j).getYArr(),t.getCeldas(i,j).getXDer(),t.getCeldas(i,j).getYAbj());
}
void Interfaz::efectosComodines(int cm,Tablero t){
    int c;
    if(cm%2==0)c=15;
    else c=3;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(t.getCeldas(i,j).getComodin()==1){
                setcolor(c);
                rectangle(t.getCeldas(i,j).getXIzq(),t.getCeldas(i,j).getYArr(),t.getCeldas(i,j).getXDer(),t.getCeldas(i,j).getYAbj());
            }
        }
    }
}
void Interfaz::cambiarColorTablero(int n){
    int c=0;//cambio de color del tablero
    int c1=0;
    int c2=0;
    if(n==1){
        c=8;
        c1=7;
        c2=4;
    }
    if(n==2){
        c=4;
        c1=8;
        c2=2;
    }
    if(n==3){
        c=2;
        c1=4;
        c2=1;
    }
    if(n==4){
        c=1;
        c1=2;
        c2=5;
    }
    if(n==5){
        c=5;
        c1=1;
        c2=6;
    }
    if(n==6){
        c=6;
        c1=5;
        c2=7;
    }
    setfillstyle(INTERLEAVE_FILL,c);
    bar(310,10,350,50);
    setcolor(c1);
    outtextxy(280,23,"<-");
    setcolor(c2);
    outtextxy(360,23,"->");
}
void Interfaz::efectoBotones(bool jc,bool aCD,bool aC,bool jr){//efectos de los botones y titulo
    if(jc==false&&aCD==false&&mousex()>235&&mousex()<595&&mousey()>55&&mousey()<100) titulo(15);//rectangle(235,55,595,100); titulo
    else if(jc==false&&aCD==false) titulo(0);
    if(aC==false&&jc==false&&mousex()>650&&mousex()<730&&mousey()>490&&mousey()<520)botonSalir(4);//boton salir
    else if(aC==false&&jc==false) botonSalir(0);
    if((aC==true&&mousex()>30&&mousex()<130&&mousey()>25&&mousey()<55))botonRegresar(4);//boton regresar
    else if(aC==true||jr==true) botonRegresar(0);
    if(aC==false&&jc==false&&mousex()>255&&mousex()<345&&mousey()>210&&mousey()<240) botonJugar(15);//boton jugar
    else if(aC==false&&jc==false) botonJugar(0);
    if(aC==false&&jc==false&&mousex()>255&&mousex()<345&&mousey()>250&&mousey()<280) botonCargar(15);//boton guardar
    else if(aC==false&&jc==false) botonCargar(0);
    if(jc==false&&aCD==false&&mousex()>370&&mousex()<500&&mousey()>210&&mousey()<240) botonAcercaD(15);//boton acercade
    else if(jc==false&&aC==false&&aCD==false) botonAcercaD(0);
    if(jc==false&&aC==true&&aCD==false&&mousex()>385&&mousex()<470&&mousey()>250&&mousey()<280) botonInfo(15);//boton info
    else if(jc==false&&aC==true&&aCD==false) botonInfo(0);
    if(jc==false&&aC==true&&aCD==false&&mousex()>385&&mousex()<470&&mousey()>290&&mousey()<320) botonReglas(15);//boton reglas
    else if(jc==false&&aC==true&&aCD==false) botonReglas(0);
}
//actualiza Juego
void Interfaz::actualizaTablero(Tablero t){//imprime los cambios al jugar
    ///////////////IMPRIME LAS FICHAS////////////////////////////////////////////////////////
    for(int i=0;i<10;i++){//EFECTO AL VOLVER LAS FICHAS
        for(int j=0;j<10;j++){
            setcolor(t.getCeldas(i,j).getColor());
            if(t.getCeldas(i,j).getEfectoJ()==1){
                for(int k=0;k<20;k++){
                    circle(t.getCeldas(i,j).getXIzq()+25,t.getCeldas(i,j).getYArr()+25,k);
                    Sleep(18);
                }
            }
        }
    }
    for(int i=0;i<10;i++){//EFECTO AL HABER USADO UN COMODIN
        for(int j=0;j<10;j++){
            if(t.getCeldas(i,j).getEfectoJ()==2){
                setcolor(14);
                for(int k=0;k<20;k++){
                    circle(t.getCeldas(i,j).getXIzq()+25,t.getCeldas(i,j).getYArr()+25,k);
                    Sleep(16);
                }
            }
        }
    }
    for(int i=0;i<10;i++){//AL FINAL DE CUALQUIER EFECTO LA DEJA DEL COLOR NUEVO
        for(int j=0;j<10;j++){
            setcolor(t.getCeldas(i,j).getColor());
            if(t.getCeldas(i,j).getColor()==0){//las negras
                for(int k=0;k<20;k++) circle(t.getCeldas(i,j).getXIzq()+25,t.getCeldas(i,j).getYArr()+25,k);
            }
            if(t.getCeldas(i,j).getColor()==15){//las blancas
                for(int k=0;k<20;k++) circle(t.getCeldas(i,j).getXIzq()+25,t.getCeldas(i,j).getYArr()+25,k);
            }
        }
    }
}
void Interfaz::muestraJC(Tablero t,Jugadores j1,Jugadores j2,int c){//imprime u oculta las jugadas correctas
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            ///////////////IMPRIME JUGADAS CORRECTAS SEGUN TURNO//////////////////////////////////////
            if(j1.getTurno()){
                for(int k=0;k<10;k++){
                    for(int l=0;l<10;l++){
                        if(t.getCeldas(k,l).getJugadaC()==15&&t.getCeldas(k,l).getEstado()==-1){
                            if(c%2==0)setcolor(getpixel(t.getCeldas(k,l).getXIzq()+3,t.getCeldas(k,l).getYArr()+3));
                            else setcolor(15);
                            circle(t.getCeldas(k,l).getXIzq()+25,t.getCeldas(k,l).getYArr()+25,10);
                        }
                    }
                }
            }

            /////////////////////////////////////////////////////////////////////////////////////////
            if(j2.getTurno()){
                for(int k=0;k<10;k++){
                    for(int l=0;l<10;l++){
                        if(t.getCeldas(k,l).getJugadaC()==0&&t.getCeldas(k,l).getEstado()==-1){
                            if(c%2==0)setcolor(getpixel(t.getCeldas(k,l).getXIzq()+3,t.getCeldas(k,l).getYArr()+3));
                            else setcolor(0);
                            circle(t.getCeldas(k,l).getXIzq()+25,t.getCeldas(k,l).getYArr()+25,10);
                        }
                    }
                }
            }
            ///////////////////////////////////////////////////////////////////////////////////////
        }

    }
}
void Interfaz::refrescaJC(Tablero t,Jugadores j1,Jugadores j2){//borra las jugadas correctas anteriores
    if(!j1.getTurno()){
        for(int k=0;k<10;k++){
            for(int l=0;l<10;l++){
                if(t.getCeldas(k,l).getJugadaC()==15&&t.getCeldas(k,l).getEstado()==-1){
                    setcolor(getpixel(t.getCeldas(k,l).getXIzq()+3,t.getCeldas(k,l).getYArr()+3));
                    circle(t.getCeldas(k,l).getXIzq()+25,t.getCeldas(k,l).getYArr()+25,10);
                }
            }
        }
    }
    if(!j2.getTurno()){
        for(int k=0;k<10;k++){
            for(int l=0;l<10;l++){
                if(t.getCeldas(k,l).getJugadaC()==0&&t.getCeldas(k,l).getEstado()==-1){
                    setcolor(getpixel(t.getCeldas(k,l).getXIzq()+3,t.getCeldas(k,l).getYArr()+3));
                    circle(t.getCeldas(k,l).getXIzq()+25,t.getCeldas(k,l).getYArr()+25,10);
                }
            }
        }
    }
}
//guardar y cargar
void Interfaz::nombreGuardar(Tablero &t){
    char nom[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};//variables para el nombre del juego
    char tecla;
    for(int i=0;i<10;i++) t.setNombre(i,' ');
    setcolor(0);
    outtextxy(565,530,"Nombre del juego: ");
    for(int i=0;i<10;i++){
        tecla = getch();
        if(tecla == 8){
            moveto(565, 555);
            outtext("          ");
            i = -1;
            for(int i = 0; i < 10; i++){
                nom[i] = ' ';
                t.setNombre(i,' ');
                continue;
            }
        }
        if(tecla==13) break;

        nom[i]=tecla;
        t.setNombre(i,tecla);
        moveto(565,555);
        outtext(nom);
    }
    outtextxy(565,530,"                  ");
    outtextxy(565,555,"          ");
    string nombreJuego(nom);//convierte de char a string
}
string Interfaz::nombreCargar(){
    char nom[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};//variables para el nombre del juego
    char tecla;
    int cont;
    setcolor(1);
    outtextxy(260,300,"Nombre del juego: ");
    for(int i=0;i<10;i++){
        tecla = getch();
        if(i>0 && tecla == 8){
            moveto(260,320);
            outtext("          ");
            i = -1;
            for(int i = 0; i < 10; i++){
                nom[i] = ' ';
                continue;
            }
        }

        if(tecla==13) break;

        nom[i]=tecla;
        moveto(260,320);
        outtext(nom);
    }
    outtextxy(260,300,"                  ");
    outtextxy(260,320,"          ");

    string n(nom);
    return n;
}
void Interfaz::msjPartidaNoEncontrada(){
    setcolor(4);
    outtextxy(260,300,"Partida no encontrada..");
    Sleep(2000);
    setcolor(7);
    outtextxy(260,300,"Partida no encontrada..");
}
void Interfaz::msjPartidaEncontrada(){
    setcolor(1);
    outtextxy(260,300,"Partida cargada!");
    Sleep(2000);
    setcolor(7);
    outtextxy(260,300,"Partida cargada!");
}
void Interfaz::msjNoPartidaG(){
    setcolor(4);
    outtextxy(260,300,"No hay partidas guardadas.");
    Sleep(2000);
    setcolor(7);
    outtextxy(260,300,"No hay partidas guardadas.");
}
Interfaz::~Interfaz()
{
    //dtor
}
