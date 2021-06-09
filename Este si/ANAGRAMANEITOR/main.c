#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#define LMAX 100
#define TDICC 80500
#define TPALABRA 24

#define FILE_LOG "log.dat"
#define FILE_DICC "dicc.txt"

#include "VIDEO.cpp"

struct juego{
	int idJuego;
	int partidas;
    int puntosEscritor;
	int puntosAdivinador;
    char nombreEscritor[LMAX];
	char nombreAdivinador[LMAX];
	int moneda;
};

struct log{
	int idJuego;
	char anagrama[TPALABRA];
	char nombreEscritor[TPALABRA];
	char nombreAdivinador[TPALABRA];
	int intentos;
	int ganador;
	int jugador_empieza;
};

void imprimir_terminator(int x, int y);
void imprimir_terminator2(int x, int y);
int continuar();
int reintentarMenu(int intentos);
int reintentar_menu(int intentos);
int es_anagrama(char cad1[], char cad2[]);
void game_over(char nombrej1[],int puntosj1,char nombrej2[],int puntosj2,int partidas);
int es_texto(char cad[]);
void partida(char nombrej1[],int *puntosj1,char nombrej2[], int *puntosj2,char diccionario[][TPALABRA], int jugador_empieza, int idJuego);
void ingresar_nombre(char palabra[]);
void ingresar_palabra(char palabra[], char diccionario[][TPALABRA]);
int cargar_diccionario(char diccionario[][TPALABRA]);
int buscar_palabra(char diccionario[][TPALABRA], char palabra[]);
void juego(struct juego);
void imprimir_terminator(int x, int y);
void crear_log(int,char anagrama[], char nombrej1[], char nombrej2[], int intentos, int ganador, int jugador_empieza);
void mostrarEstadisticas();
struct juego setearData();
struct juego cargadorPartida();
void bienvenida();
void instrucciones();


int main() // --------------------MAIN------------------------
{

	SetConsoleTitle("ANAGRAMANEITOR");
	//bienvenida();
	do{
	}while(menu() != 99);
}


void bienvenida(){
	imprimir_terminator2(10,0);
	int i;
	for(i = 0; i <  25; i++){

		imprimir_terminator(10+(i*2), 0);
		gotoxy(0,0);
		Sleep(80);
	}
}

void imprimir_terminator(int x, int y){
	int terminator[30][24]=
	{
		{0,0,0,0,0,0,71,71,71,72,72,72,72,72,72,0,0,0,0,0,0},
		{0,0,0,0,0,72,72,72,72,72,72,72,72,72,72,72,0,0,0,0,0},
		{0,0,0,0,71,72,72,0,72,72,72,72,72,0,72,72,73,0,0,0,0},
		{0,0,0,0,71,72,72,0,72,72,72,72,72,0,72,72,73,0,0,0,0},
		{0,0,0,0,71,72,72,72,73,72,72,72,73,72,72,72,73,0,0,0,0},
		{0,0,0,0,0,72,72,72,73,72,72,72,73,72,72,72,0,0,0,0,0},
		{0,0,0,0,73,72,72,72,72,73,72,73,72,72,72,72,73,0,0,0,0},
		{0,0,0,0,73,72,71,72,72,73,73,73,72,72,73,72,73,0,0,0,0},
		{0,0,0,0,73,72,71,72,72,72,73,72,72,72,73,72,73,0,0,0,0},
		{0,0,0,0,71,72,0,44,0,0,72,0,0,44,0,72,73,0,0,0,0},
		{0,0,0,0,71,72,0,0,72,72,72,72,72,0,0,72,73,0,0,0,0},
		{0,0,0,0,71,72,72,72,72,0,72,0,72,72,72,72,73,0,0,0,0},
		{0,0,0,0,0,72,72,72,72,0,72,0,72,72,72,72,0,0,0,0,0},
		{0,0,0,0,71,0,72,0,72,72,72,72,72,0,72,0,73,0,0,0,0},
		{0,0,0,0,71,72,0,0,71,72,71,72,71,0,0,72,73,0,0,0,0},
		{0,0,0,0,71,72,72,0,154,83,154,83,154,0,72,72,73,0,0,0,0},
		{0,0,0,0,0,72,72,0,83,154,83,154,83,0,72,72,0,0,0,0,0},
		{0,0,0,0,71,72,72,72,72,72,72,72,72,72,72,72,73,0,0,0,0},
		{0,0,0,0,0,72,72,72,0,72,0,72,0,72,72,72,0,0,0,0,0},
		{0,0,0,0,72,0,0,72,72,72,0,72,72,72,0,0,72,0,0,0,0},
		{0,0,0,0,72,0,0,0,72,72,72,72,72,0,0,0,72,0,0,0,0},
		{0,0,0,0,72,0,0,72,0,0,0,0,0,72,0,0,72,0,0,0,0},
		{0,0,0,71,72,73,73,73,73,0,0,0,73,73,73,73,72,72,0,0,0},
		{0,0,0,72,72,72,72,72,72,73,73,73,72,72,72,72,72,72,0,0,0},
		{0,73,73,72,0,0,0,0,0,72,72,72,0,0,0,0,0,72,73,73,0},
		{0,72,72,72,72,72,72,72,72,71,0,72,72,72,72,72,72,72,72,72,0},
		{0,0,0,72,72,72,72,72,72,71,0,72,72,72,72,72,72,72,0,0,0}
	};
	int iniX = x;
	int iniY = y;
	gotoxy(x, y);
	for (y=0;y<30;y++ ){

		for (x=0;x<24;x++){
			if (x==0 && y>0) gotoxy(iniX,y+iniY);

			paintearD(terminator[y][x]);

		}
	}

}

void imprimir_terminator2(int x, int y){
	int terminator[30][24]=
	{
		{0,0,0,0,0,0,71,71,71,72,72,72,72,72,72,0,0,0,0,0,0},
		{0,0,0,0,0,72,72,72,72,72,72,72,72,72,72,72,0,0,0,0,0},
		{0,0,0,0,71,72,72,0,72,72,72,72,72,0,72,72,73,0,0,0,0},
		{0,0,0,0,71,72,72,0,72,72,72,72,72,0,72,72,73,0,0,0,0},
		{0,0,0,0,71,72,72,72,73,72,72,72,73,72,72,72,73,0,0,0,0},
		{0,0,0,0,0,72,72,72,73,72,72,72,73,72,72,72,0,0,0,0,0},
		{0,0,0,0,73,72,72,72,72,73,72,73,72,72,72,72,73,0,0,0,0},
		{0,0,0,0,73,72,71,72,72,73,73,73,72,72,73,72,73,0,0,0,0},
		{0,0,0,0,73,72,71,72,72,72,73,72,72,72,73,72,73,0,0,0,0},
		{0,0,0,0,71,72,0,44,0,0,72,0,0,44,0,72,73,0,0,0,0},
		{0,0,0,0,71,72,0,0,72,72,72,72,72,0,0,72,73,0,0,0,0},
		{0,0,0,0,71,72,72,72,72,0,72,0,72,72,72,72,73,0,0,0,0},
		{0,0,0,0,0,72,72,72,72,0,72,0,72,72,72,72,0,0,0,0,0},
		{0,0,0,0,71,0,72,0,72,72,72,72,72,0,72,0,73,0,0,0,0},
		{0,0,0,0,71,72,0,0,71,72,71,72,71,0,0,72,73,0,0,0,0},
		{0,0,0,0,71,72,72,0,83,154,83,154,83,0,72,72,73,0,0,0,0},
		{0,0,0,0,0,72,72,0,154,83,154,83,154,0,72,72,0,0,0,0,0},
		{0,0,0,0,71,72,72,72,72,72,72,72,72,72,72,72,73,0,0,0,0},
		{0,0,0,0,0,72,72,72,0,72,0,72,0,72,72,72,0,0,0,0,0},
		{0,0,0,0,72,0,0,72,72,72,0,72,72,72,0,0,72,0,0,0,0},
		{0,0,0,0,72,0,0,0,72,72,72,72,72,0,0,0,72,0,0,0,0},
		{0,0,0,0,72,0,0,72,0,0,0,0,0,72,0,0,72,0,0,0,0},
		{0,0,0,71,72,73,73,73,73,0,0,0,73,73,73,73,72,72,0,0,0},
		{0,0,0,72,72,72,72,72,72,73,73,73,72,72,72,72,72,72,0,0,0},
		{0,73,73,72,0,0,0,0,0,72,72,72,0,0,0,0,0,72,73,73,0},
		{0,72,72,72,72,72,72,72,72,71,0,72,72,72,72,72,72,72,72,72,0},
		{0,0,0,72,72,72,72,72,72,71,0,72,72,72,72,72,72,72,0,0,0}
	};
	int iniX = x;
	int iniY = y;
	gotoxy(x, y);
	for (y=0;y<30;y++ ){

		for (x=0;x<24;x++){
			Sleep(1);
			if (x==0 && y>0) gotoxy(iniX,y+iniY);

			paintearD(terminator[y][x]);

		}
	}

}

void imprimir_menu()
{
	int hudX = 10;
	cuadroTF("                M E N U                ",hudX+0,0,AZUL,VERDEI);
	itemsNum(6, hudX + 3, 4, VERDEI);
	cuadroT("        Jugar        ",hudX+10,3,MAGENTA);
	cuadroT("    Instrucciones    ",hudX+10,7,MAGENTA);
	cuadroT("   Retomar partida   ",hudX+10,11 ,MAGENTA);
	cuadroT("     Estadisticas    ",hudX+10,15,MAGENTA);
	cuadroT("       Creditos      ",hudX+10,19,MAGENTA);
	cuadroT("        Salir        ",hudX+10,23,MAGENTA);

	cuadroT("       Ingrese una opcion:  < >        ",hudX,26,9);
}

int menu()
{
	system("cls");
	imprimir_terminator(60, 0);
	imprimir_menu();
	int opcion = 0;
	gotoxy(40,27);
	scanf("%d",&opcion);
	system("cls");
	struct juego data;
	switch(opcion)
	{
		case 1:
			data = setearData();
			juego(data);
			break;
		case 2:
			instrucciones();
			Sleep(1000);
			break;
		case 3:
			data = cargadorPartida();
			juego(data);
			break;
		case 4:
			mostrarEstadisticas();
			system("pause");
			break;
		case 5:
			printf("Creditos");
			break;
		default:
			return 99;

	}
	return 0;
}

void instrucciones()
{
   char c;
   int pag=1;
   do{
    switch(pag){
    case 1: inst_pag_1(); break;
    case 2: printf("PAG 2");break;
    case 3: printf("PAG 3");break;
    case 4:printf("PAG 4");break;
    }

    c=getche();
    if(c=='a')
    {
        if(pag>1)
        {
            pag--;
        }
    }
    else if(c=='d')
    {
        if(pag<4)
        {
            pag++;
        }
    }

   }while(c!='m');

}

void inst_pag_1()
{
    int hudX = 10;
	cuadroTF("       I N S T R U C C I O N E S       ",hudX+0,0,AZUL,VERDEI);
    cuadroTtop("Anagramaneitor es un juego para dos    ",hudX+0,3,MAGENTA);
    cuadroTmid("jugadores, el cual consiste en que,    ",hudX+0,5,MAGENTA);
    cuadroTmid("por turnos, un jugador propone una     ",hudX+0,7,MAGENTA);
    cuadroTmid("palabra y el otro jugador tiene 3      ",hudX+0,9,MAGENTA);
    cuadroTmid("intentos para ingresar un anagrama de  ",hudX+0,11,MAGENTA);
    cuadroTmid("la misma. Para que se considere intento",hudX+0,13,MAGENTA);
    cuadroTmid("se debe ingresar una palabra existente,",hudX+0,15,MAGENTA);
    cuadroTmid("es decir si la palabra ingresada es    ",hudX+0,17,MAGENTA);
    cuadroTmid("arbol, no se puede poner rabol, tiene  ",hudX+0,19,MAGENTA);
    cuadroTmid("que ser algo como labor, algo existente",hudX,21,MAGENTA);
    cuadroTbot("(sigue en pag 2)                       ",hudX,23,MAGENTA);
}

struct juego setearData(){

	struct juego data;
	data.idJuego = setearIdJuego();
	data.partidas=0;
    data.puntosEscritor=0;
	data.puntosAdivinador=0;
    strcpy(data.nombreEscritor,"Jugador 1");
	strcpy(data.nombreAdivinador,"Jugador 2");
	srand(time(NULL));
    data.moneda=rand()%2;

//	printf("Jugador 1 ingrese su nombre: ");
//    ingresar_nombre(data.nombreEscritor);
//    printf("\n\nJugador 2 ingrese su nombre: ");
//    ingresar_nombre(data.nombreAdivinador);

	return data;
}


void juego(struct juego data)
{
	char diccionario[TDICC][TPALABRA];

    if(cargar_diccionario(diccionario)) return;

	int jugador_empieza = data.moneda;
    do{ //partida
        data.partidas++;

        if(data.partidas%2!=data.moneda) partida(data.nombreEscritor,&data.puntosEscritor,data.nombreAdivinador,&data.puntosAdivinador,diccionario, jugador_empieza, data.idJuego);
        else partida(data.nombreAdivinador,&data.puntosAdivinador,data.nombreEscritor,&data.puntosEscritor,diccionario, jugador_empieza, data.idJuego);

        if(jugador_empieza) jugador_empieza = 0;
		else jugador_empieza = 1;
		printf("Puntos %s: %i\n\nPuntos %s: %i",data.nombreEscritor,data.puntosEscritor,data.nombreAdivinador,data.puntosAdivinador);

    }while(continuar()==1);
    game_over(data.nombreEscritor,data.puntosEscritor,data.nombreAdivinador,data.puntosAdivinador,data.partidas);
}

int cargar_diccionario(char diccionario[][TPALABRA])
{
    FILE *dicc;
    dicc = fopen(FILE_DICC,"rt");
    if(!dicc){
    	return 1;
	}
    char c;
    int palabra = 0;
    int character = 0;

    while((c = fgetc(dicc)) != EOF && palabra < TDICC){
        if(c == '\n'){
            palabra++;
            character = 0;
        }
        else{
            diccionario[palabra][character] = c;
            character++;
        }
    }
    fclose(dicc);
    return 0;
}

void ingresar_nombre(char palabra[])
{
	fflush(stdin);
    gets(palabra);
    while (es_texto(palabra)!=0)
    {
        printf("ERROR\n� Ingrese una palabra usando solo letras: ");
        fflush(stdin);
        gets(palabra);
    }

}

void partida(char nombrej1[],int *puntosj1,char nombrej2[], int *puntosj2,char diccionario[][TPALABRA], int jugador_empieza, int idJuego)
{
    int intentos=0;
    int reintentar=1;
    int ganoj2 = 0;
    char palabraj1[LMAX],palabraj2[LMAX];
    printf("%s ingrese una palabra: ",nombrej1);
    ingresar_palabra(palabraj1,diccionario);

    do{//intentos
        intentos++;
        printf("%s ingrese una palabra: ",nombrej2);
        ingresar_palabra(palabraj2,diccionario);
        if (strcmp(palabraj1,palabraj2)==0)reintentar=reintentar_menu(intentos);
        else
		{
            if (es_anagrama(palabraj1,palabraj2)==0)
			{
                ganoj2=1;
                break;
            }
            else
			{
                reintentar=reintentar_menu(intentos);
            }
        }
    }while(reintentar==1);
    if (ganoj2==1) *puntosj2=*puntosj2+1;
    else{
    	*puntosj1=*puntosj1+1;
    	//intentos = -1;
	}

    crear_log(idJuego, palabraj1, nombrej1, nombrej2, intentos, ganoj2, jugador_empieza);

}

void crear_log(int idJuego,char anagrama[], char nombrej1[], char nombrej2[],int intentos, int ganador, int jugador_empieza)
{
	struct log log_partida;
	log_partida.idJuego = idJuego;
	strcpy(log_partida.anagrama, anagrama);
	strcpy(log_partida.nombreEscritor, nombrej1);
	strcpy(log_partida.nombreAdivinador, nombrej2);
	log_partida.intentos = intentos;
	log_partida.ganador = ganador;
	log_partida.jugador_empieza = jugador_empieza;

//	printf("\n\n%d: %s | %d | %d | %d\n\n",log_partida.idJuego, log_partida.anagrama, log_partida.intentos, log_partida.ganador, log_partida.jugador_empieza);

	FILE* f = fopen("log.dat","ab");
	fwrite(&log_partida, sizeof(struct log), 1, f);
	fclose(f);
}

int setearIdJuego(){
	struct log log_partida;
	FILE* f = fopen(FILE_LOG,"rb");
	if(!f) return 1;

	fseek(f, sizeof(struct log) * -1, 2);
	fread(&log_partida, sizeof(struct log), 1, f);
	fclose(f);

//	printf("%d: %s, %d, %d, %d\n\n",log_partida.idJuego, log_partida.anagrama, log_partida.intentos, log_partida.ganador, log_partida.jugador_empieza);
	return log_partida.idJuego + 1;

}

void mostrarEstadisticas(){
	FILE* f = fopen(FILE_LOG,"rb");
	struct log l;
	int cantidadPartidas = 0;
	int cantidadJuegos = 0;
	int cantidadIntentosTotal = 0;
	int jugadorGanador = 0;
	int jugadorEmpieza = 0;
	int juegoActual = -999;
	fread(&l, sizeof(struct log), 1, f);
	while (!feof(f))
	{
		cantidadPartidas++;

		cantidadIntentosTotal+= l.intentos;

		jugadorGanador+= l.ganador;

		if(l.idJuego > cantidadJuegos){
			cantidadJuegos = l.idJuego;
			jugadorEmpieza+= l.jugador_empieza;
		}

		fread(&l, sizeof(struct log), 1, f);
	}
	int hudX = 10;
	cuadroTF("        E S T A D I S T I C A S        ",hudX+0,0,AZUL,VERDEI);

	printf("Intentos: %d | Partidas: %d | Juegos: %d | Ganador Escribe: %d | Ganador Adivina: %d | Empieza J1: %d", cantidadIntentosTotal, cantidadPartidas, cantidadJuegos, cantidadPartidas - jugadorGanador , jugadorGanador, cantidadJuegos - jugadorEmpieza);


	printf("Estadisticas:\n");
	printf("Juegos totales: %d\n", cantidadJuegos);
	printf("Partidas totales: %d\n", cantidadPartidas);
	printf("Partidas por juego: %f\n",(float) cantidadPartidas / cantidadJuegos );
	printf("Promedio intento por partida: %f\n",(float) cantidadIntentosTotal / cantidadPartidas);
	printf("Porcentaje de veces que inicio el Jugador 1: %f\n",(float) (cantidadJuegos - jugadorEmpieza) * 100 / cantidadJuegos);
	printf("Porcentaje de veces que inicio el Jugador 2: %f\n",(float) jugadorEmpieza * 100 / cantidadJuegos);
	printf("Porcentaje de veces que gano el Escritor: %f\n",(float) (cantidadPartidas - jugadorGanador) * 100 / cantidadPartidas);
	printf("Porcentaje de veces que gano el Adivinador: %f\n",(float)  jugadorGanador * 100 / cantidadPartidas);



}


struct juego cargadorPartida(){

	int idJuego;
	printf("Ingrese su ID de juego: ");
	scanf("%d",&idJuego);
	struct log l;
	FILE* f = fopen("log.dat","rb");
	fread(&l, sizeof(struct log), 1, f);
	while (!feof(f) && l.idJuego != idJuego)
	{
		printf("LA PUTA MADRE");
		fread(&l, sizeof(struct log), 1, f);
	}
	struct juego data;

	data.idJuego = l.idJuego;
	data.moneda = l.jugador_empieza;
	if(!l.jugador_empieza) {
		strcpy(data.nombreAdivinador, l.nombreAdivinador);
		strcpy(data.nombreEscritor, l.nombreEscritor);
	}
	else{
		strcpy(data.nombreAdivinador,l.nombreEscritor);
		strcpy(data.nombreEscritor, l.nombreAdivinador);
	}

	data.partidas = 0;
	data.puntosEscritor = 0;
	data.puntosAdivinador = 0;

//	fread(&l, sizeof(struct log), 1, f);
	while (!feof(f))
	{
		if( l.idJuego == idJuego){
			if(!l.ganador)	data.puntosEscritor++;
			else data.puntosAdivinador++;
			data.partidas++;
		}
		fread(&l, sizeof(struct log), 1, f);
	}

	fclose(f);

	return data;

}


int continuar()
{
	int respuesta;
	printf("\nDesea jugar otra partida?");
	printf("\n1. Si");
	printf("\n2. No");
	printf("\nRespuesta: ");
	fflush(stdin); // tuve que googlearlo para que ande
	scanf("%d",&respuesta);
	return respuesta;
}

int reintentar_menu(int intentos)
{
	if(intentos >= 3) return 0;
	int respuesta;
	printf("Lo siento!");
	printf("\nDesea intentar de nuevo?");
	printf("\n1. Si");
	printf("\n2. No");
	printf("\nRespuesta: ");
	fflush(stdin); // tuve que googlearlo para que ande
	scanf("%d",&respuesta);
	return respuesta;
}

void ingresar_palabra(char palabra[], char diccionario[][TPALABRA])
{
    fflush(stdin);
    gets(palabra);
    while (buscar_palabra(diccionario,palabra)!=0)
    {
    	setTF(BLANCO,ROJO);
        printf("ERROR");
        setT(GRIS_CLARO);
		printf("\nIngrese una palabra valida: ");
        fflush(stdin);
        gets(palabra);
    }

}

int buscar_palabra(char dicci[][TPALABRA], char palabra[])
{
    int i = 0;
    while(strcmp(palabra,dicci[i])!=0 && i < TDICC) i++;
    printf("%i",i);
    if(i != TDICC) return 0;
    else return 1;
}

int es_texto(char cad[])
{
    int lcad = strlen(cad), i=0,cont=0,rta=0;
    strlwr(cad);
    for (i=0;i<lcad;i++){if (cad[i]>=97 && cad[i]<=122)cont++;}
    if (cont==lcad)rta=0;
    else rta=1;
    return rta;
}

int es_anagrama(char cad1[], char cad2[])
{
    int lcad1=strlen(cad1),lcad2=strlen(cad2);
    char cadAux[LMAX];
    strcpy(cadAux,cad1);
    int rta=1,i,j,cont=0;


    if(lcad1==lcad2)
    {
        for (i=0;i<lcad1;i++)
        {
            for(j=0;j<lcad2;j++)
            {
                if(cad2[i]==cadAux[j])
                {
                    cadAux[j]='!';
                    cont++;
                    break;
                }
            }
        }
        if(lcad1==cont)rta=0;
    }
    return rta;
}

void game_over(char nombrej1[],int puntosj1,char nombrej2[],int puntosj2,int partidas)
{
    printf("\nFIN DEL JUEGO");
    printf("\nJugaron %d partidas", partidas);
    printf("\nPuntos finales: ");
    printf("\n%s: %d",nombrej1, puntosj1);
    printf("\n%s: %d",nombrej2, puntosj2);

    if(puntosj1 > puntosj2) printf("\n\n>> GANO %s!!!",strupr(nombrej1));
    else{
        if(puntosj1 == puntosj2) printf("\n\n>> Empate! Ambos ganan");
        else printf("\n\n>> GANO %s!!!",strupr(nombrej2));
    }
}



