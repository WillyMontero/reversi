#include "Archivos.h"
#include <string>
#include "Tablero.h"
#include "Jugadores.h"
#include "Interfaz.h"
#include <iostream>
using namespace std;
Archivos::Archivos()
{
    //ctor
}
void Archivos::info(){//arreglar
    FILE *inf;
    char caracter[10000];
    int y=100;
    int c=0;
    cleardevice();
    setcolor(0);
    settextstyle(4,HORIZ_DIR,4);//LETRA GRANDE (fuente,posicion,tamaño)
    outtextxy(220,25,"INFORMACION");
    settextstyle(8,0,1);
    setcolor(0);
    inf = fopen("info.txt","r");

    while(!feof(inf)){
        caracter[c] = fgetc(inf);
        if(caracter[c]=='\n'){
            y=y+40;
            c=0;
        }
        else c++;
        moveto(150,y);
        outtext(caracter);
    }
    fclose(inf);
    setcolor(0);
}
void Archivos::reglas(){
    FILE *rg;
    char caracter[10000];
    int y=80;
    int c=0;

    cleardevice();
    setcolor(0);
    settextstyle(4,HORIZ_DIR,4);//LETRA GRANDE
    outtextxy(245,25,"REGLAS");

    settextstyle(8,0,1);
    setcolor(0);
    rg = fopen("reglas.txt","r");

    while(!feof(rg)){
        caracter[c] = fgetc(rg);
        if(caracter[c]=='\n'){
            y=y+40;
            c=0;
        }
        else c++;
        moveto(50,y);
        outtext(caracter);
    }
    fclose(rg);
    setcolor(0);
}
void Archivos::guardar(Tablero t,Jugadores j1,Jugadores j2){
    FILE *g;

    g = fopen("guardado.txt","a");

    fwrite(&t,sizeof(Tablero),1,g);
    fwrite(&j1,sizeof(Jugadores),1,g);
    fwrite(&j2,sizeof(Jugadores),1,g);

    fclose(g);
}
void Archivos::cargar(Tablero &t,Jugadores &j1,Jugadores &j2,string n,bool &nomb){
    FILE *c;

    Tablero rT=t;
    Jugadores rJ1=j1;
    Jugadores rJ2=j2;
    bool encontro=false;

    Interfaz p;
    c = fopen("guardado.txt","r");
    if(c==NULL){
        p.msjNoPartidaG();
    }
    else{
        while(!feof(c)){
            fread(&t,sizeof(Tablero),1,c);
            if(n == t.getNombre()){
                t=t;
                fread(&j1,sizeof(Jugadores),1,c);
                j1=j1;
                fread(&j2,sizeof(Jugadores),1,c);
                j2=j2;
                encontro=true;
                break;
            }
            fread(&j1,sizeof(Jugadores),1,c);
            fread(&j2,sizeof(Jugadores),1,c);
        }
    }

    fclose(c);

    if(encontro){
        p.msjPartidaEncontrada();
        nomb=false;
    }
    if(!encontro&&c!=NULL){
        t=rT;
        j1=rJ1;
        j2=rJ2;
        p.msjPartidaNoEncontrada();
    }
    //IMPRIME JUEGOS GUARDADOS
    //FILE *c;

    /*c = fopen("guardado.txt","r");

    while(!feof(c)){
        fread(&t,sizeof(Tablero),1,c);
        cout<<t.getNombre();
        fread(&j1,sizeof(Jugadores),1,c);
        cout<<"  -> Jugador 1: "<<j1.getNombre();
        fread(&j2,sizeof(Jugadores),1,c);
        cout<<" -> Jugador 2: "<<j2.getNombre()<<endl<<endl;
    }

    fclose(c);*/
}
Archivos::~Archivos()
{
    //dtor
}
