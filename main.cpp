#include "Interfaz.h"
#include "Archivos.h"
#include "Tablero.h"
#include "Jugadores.h"
#include "Juego.h"

Archivos arch;
Interfaz pantalla;
Tablero c;
Jugadores jug1,jug2;

int main()
{
    pantalla.imprimirInterfaz();
    pantalla.all();
    //estas 4 variables controlan que no se den errores en la pantalla de inicio al cambiar de "ventanas"
    bool aC=false;//al  entrar a acercade..
    bool aCD=false;//dentro de acercade..
    bool jc=false;//al entrar a los botones de jugar cargar
    bool jr=false;//al entrar a jugar

    int cm=1;//variable para el efecto de comodin
    int cCT=1;//variable para el cambio de color del tablero
    int mostrarJ=1;//variable para mostrar jugadas correctas

    bool nomb=true;//permite que solo se pidan los nombres una vez al entrar al juego

    while(true){
        pantalla.efectoBotones(jc,aCD,aC,jr);
        //acciones al hacer click sobre los botones
        //rectangle(255,210,345,240); jugar
        if(aC==false&&jr==false&&mousex()>255&&mousex()<345&&mousey()>210&&mousey()<240&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            jc=true;
            if(nomb){//pide los nombres de los jugadores
                pantalla.pideNombres(jug1,jug2);
                pantalla.rifaTurno(jug1,jug2);//elije quien empieza
                nomb=false;
            }
            pantalla.titulo(7);//oculta el titulo
            pantalla.pintarTablero(cCT,c);//dibuja el tablero de juego
            pantalla.cambiarColorTablero(cCT);//tablero con color actual
            pantalla.jugadores(jug1,jug2);//muestra los jugadores
            pantalla.mostrarJugadas(mostrarJ);//muestra u oculta las jugadas correctas
            pantalla.botonGuardar();
            pantalla.botonReiniciar();
            pantalla.botonRegresar(0);
            jr=!jr;
        }
        if(jr){
            pantalla.actualizaTablero(c);//actualiza las jugadas
            c.inicializa_Var_efectoJ();
            pantalla.refrescaJC(c,jug1,jug2);//oculta las jugadas correctas anteriores

            if(jug1.getTurno()){//si es turno del jugador 1
                c.evaluarJC(jug1,jug2);//busca las jugadas correctas segun turno
                if(c.pasaTurno(jug1,jug2)==1){//si el jugador no tiene jugada pasa el turno
                    pantalla.msjPasaTurno(jug1);
                    jug1.setTurno(0);
                    jug2.setTurno(1);
                    c.evaluarJC(jug1,jug2);//estas lineas evalua si los dos no tiene jugada y dice el ganador
                    if(c.pasaTurno(jug1,jug2)==1){
                        jug2.setTurno(0);
                        pantalla.ganador2(c,jug1,jug2);
                    }
                }
            }
            if(jug2.getTurno()){//si es turno del jugador 2
                c.evaluarJC(jug1,jug2);//busca las jugadas correctas segun turno
                if(c.pasaTurno(jug1,jug2)==1){
                    pantalla.msjPasaTurno(jug2);
                    jug2.setTurno(0);
                    jug1.setTurno(1);
                    c.evaluarJC(jug1,jug2);
                    if(c.pasaTurno(jug1,jug2)==1){
                        jug1.setTurno(0);
                        pantalla.ganador2(c,jug1,jug2);
                    }
                }
            }
            pantalla.efectosComodines(cm,c);
            pantalla.muestraJC(c,jug1,jug2,mostrarJ);//muestra las jugadas correctas
            pantalla.ganador(c,jug1,jug2);
            pantalla.puntaje(c,jug1,jug2);
            pantalla.turno(jug1,jug2);
            //ESTOS DOS IF ES DONDE SE JUEGA
            if(jug1.getTurno()&&mousex()>30&&mousex()<530&&mousey()>60&&mousey()<560&&ismouseclick(WM_LBUTTONDOWN)){//J1
                clearmouseclick(WM_LBUTTONDOWN);
                if(c.getCeldas(c.posFTablero(mousex(),mousey()),c.posCTablero(mousex(),mousey())).getJugadaC()==15){//si se puede jugar donde dio click
                    c.volverFichas(jug1,jug2,c.posFTablero(mousex(),mousey()),c.posCTablero(mousex(),mousey()));
                    jug2.setTurno(1);//cambia el turno
                    jug1.setTurno(0);
                }
            }
            if(jug2.getTurno()&&mousex()>30&&mousex()<530&&mousey()>60&&mousey()<560&&ismouseclick(WM_LBUTTONDOWN)){//J2
                clearmouseclick(WM_LBUTTONDOWN);
                if(c.getCeldas(c.posFTablero(mousex(),mousey()),c.posCTablero(mousex(),mousey())).getJugadaC()==0){
                    c.volverFichas(jug1,jug2,c.posFTablero(mousex(),mousey()),c.posCTablero(mousex(),mousey()));
                    jug2.setTurno(0);
                    jug1.setTurno(1);
                }
            }
            //
            //rectangle(675,200,700,225);//mostrarJug
            if(mousex()>675&&mousex()<700&&mousey()>200&&mousey()<225&&ismouseclick(WM_LBUTTONDOWN)){
                clearmouseclick(WM_LBUTTONDOWN);
                mostrarJ+=1;
                pantalla.muestraJC(c,jug1,jug2,mostrarJ);
                pantalla.mostrarJugadas(mostrarJ);//pone si o no en lo grafico
            }
            //rectangle(565,490,650,520);//guardar
            if(mousex()>565&&mousex()<650&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)){
                clearmouseclick(WM_LBUTTONDOWN);
                pantalla.nombreGuardar(c);
                arch.guardar(c,jug1,jug2);
                pantalla.efectoGuardar();
            }
            //rectangle(565,450,675,480); Reiniciar
            if(mousex()>565&&mousex()<675&&mousey()>450&&mousey()<480&&ismouseclick(WM_LBUTTONDOWN)){
                clearmouseclick(WM_LBUTTONDOWN);
                c.reiniciar();
                pantalla.pintarTablero(cCT,c);
                //jug1.setTurno(1);
                //jug2.setTurno(0);
            }
            //rectangle(270,20,305,45);// <- cambia de color el tablero
            if(cCT>=2&&mousex()>270&&mousex()<305&&mousey()>20&&mousey()<45&&ismouseclick(WM_LBUTTONDOWN)){
                clearmouseclick(WM_LBUTTONDOWN);
                c.inicializa_Var_efectoJ();
                cCT-=1;
                pantalla.pintarTablero(cCT,c);
                pantalla.cambiarColorTablero(cCT);
            }
            //rectangle(355,20,390,45); ->
            if(cCT<=5&&mousex()>355&&mousex()<390&&mousey()>20&&mousey()<45&&ismouseclick(WM_LBUTTONDOWN)){
                clearmouseclick(WM_LBUTTONDOWN);
                c.inicializa_Var_efectoJ();
                cCT+=1;
                pantalla.pintarTablero(cCT,c);
                pantalla.cambiarColorTablero(cCT);
            }
            if(mousex()>30&&mousex()<130&&mousey()>25&&mousey()<55&&ismouseclick(WM_LBUTTONDOWN)){//boton regresar
                clearmouseclick(WM_LBUTTONDOWN);
                pantalla.all();
                jr=false;
                jc=false;
            }
            //rectangle(660,490,730,520); salir
            if(mousex()>650&&mousex()<730&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)) exit(0);
            else if(ismouseclick(WM_LBUTTONDOWN)){
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
        //rectangle(255,250,345,280); cargar
        if(!jc&&!aC&&mousex()>255&&mousex()<345&&mousey()>250&&mousey()<280&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            arch.cargar(c,jug1,jug2,pantalla.nombreCargar(),nomb);
        }
        //rectangle(370,210,500,240); acerca de
        if(jc==false&&aC==false&&mousex()>370&&mousex()<500&&mousey()>210&&mousey()<240&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            pantalla.botonInfo(0);
            pantalla.botonReglas(0);
            pantalla.botonRegresar(0);
            aC=true;
        }
        if(aC){//si click en acerca de..
            //rectangle(385,250,470,280); info
            if(aCD==false&&mousex()>385&&mousex()<470&&mousey()>250&&mousey()<280&&ismouseclick(WM_LBUTTONDOWN)){
                clearmouseclick(WM_LBUTTONDOWN);
                arch.info();
                pantalla.botonRegresar(0);
                aCD=true;
            }
            //rectangle(385,290,470,320); reglas
            if(aCD==false&&mousex()>385&&mousex()<470&&mousey()>290&&mousey()<320&&ismouseclick(WM_LBUTTONDOWN)){
                clearmouseclick(WM_LBUTTONDOWN);
                arch.reglas();
                pantalla.botonRegresar(0);
                aCD=true;
            }
            //rectangle(30,25,130,55); regresar
            if(mousex()>30&&mousex()<130&&mousey()>25&&mousey()<55&&ismouseclick(WM_LBUTTONDOWN)){
                clearmouseclick(WM_LBUTTONDOWN);
                aC=false;
                aCD=false;
                pantalla.all();
            }
            else if(ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);//limpia los click que no sirven
        }
        //rectangle(660,490,730,520); salir
        if(aC==false&&mousex()>650&&mousex()<730&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)) exit(0);
        else if(ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);//si da click donde no hay nada lo borra
        cm+=1;//variable para el efecto de los comodines
        delay(100);
    }
    return 0;
}
