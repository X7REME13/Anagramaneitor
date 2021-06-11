#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <conio.h> //para getch()

//------------Librerias-Personalizadas--------------
#include "MUMP.c"

//------------------Definiciones----------------
#define LMAX 100
#define TDICC 80500
#define TPALABRA 24

#define FILE_LOG "log.dat"
#define FILE_DICC "dicc.txt"

#define XTER 70
#define YTER 1

#define COLOR_ESCRI ROJO
#define COLOR_ADIV GRIS_CLARO

//-----------ABREVIACIONES PARA MUMP.C-----------
#define setD setDefault
#define setT setTexto
#define setTF setTextoFondo

#define cuadroB cuadroBorde
#define cuadroBS cuadroBordeString
#define cuadroBI cuadroBordeInt
#define cuadroBF cuadroBordeFloat
#define cuadroBT cuadroBordeTexto
#define cuadroBTF cuadroBordeTextoFondo

#define cuadroBU cuadroBordeUniversal
#define cuadroBTU cuadroBordeTextoUniversal
#define cuadroBIU cuadroBordeIntUniversal
#define cuadroBFU cuadroBordeFloatUniversal
#define cuadroBSU cuadroBordeStringUniversal


//-----------------Estructuras------------------
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
	int jugadorEmpieza;
};

//-------------------Declaraciones---------------------
void imprimirTerminatorLento(int x, int y, int numTer);
void imprimirTerminator(int x, int y, int numTer);
int continuar();
int reintentarMenu(int intentos);
int esAnagrama(char cad1[], char cad2[]);
void gameOver(char nombrej1[],int puntosj1,char nombrej2[],int puntosj2,int partidas);
int esTexto(char cad[]);
void partida(char nombrej1[],int *puntosj1,char nombrej2[], int *puntosj2,char diccionario[][TPALABRA], int jugadorEmpieza, int idJuego);
void ingresar_nombre(char palabra[], int color, int x, int y);
void ingresar_palabra(char palabra[], char diccionario[][TPALABRA], int color, int x, int y);
int cargar_diccionario(char diccionario[][TPALABRA]);
int buscarPalabra(char diccionario[][TPALABRA], char palabra[]);
void juego(struct juego);
void crear_log(int,char anagrama[], char nombrej1[], char nombrej2[], int intentos, int ganador, int jugadorEmpieza);
void mostrarEstadisticas();
struct juego setearData();
struct juego cargadorPartida();
int menu();
void bienvenida();
void instrucciones();
void inst_pag_1();
void inst_pag_2();
void inst_pag_3();
int setearIdJuego();
int relocate_x(int largo_acompanamiento, int largo_variable, int espaciado,int hudX);
void borrar(int inix, int iniy, int endx, int endy);
void creditos();


// --------------------MAIN------------------------

int main()
{
	setTitle("<<< ANAGRAMANEITOR >>> By MUMP");
	bienvenida();
	do{
	}while(menu() != 99);
}


void bienvenida()
{
	imprimirTerminatorLento(10,YTER, 1);
	int i;
	for(i = 0; i < (XTER-10); i++){

		imprimirTerminator(10+(i), YTER,1);
		Sleep(40);
	}
}

void imprimirTerminator(int x, int y, int numTer){
	int terminator[4][27][23]={
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
	},
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
	},
	{
        {0,0,0,0,0,0,71,71,71,72,72,72,72,72,72,0,0,0,0,0,0},
        {0,0,0,0,0,72,72,72,72,72,72,72,72,72,72,72,0,0,0,0,0},
        {0,0,0,0,71,72,72,0,72,72,72,72,72,0,72,72,73,0,0,0,0},
        {0,0,0,0,71,72,72,0,72,72,72,72,72,0,72,72,73,0,0,0,0},
        {0,0,0,0,71,72,72,72,73,72,72,72,73,72,72,72,73,0,0,0,0},
        {0,0,0,0,0,72,72,72,73,72,72,72,73,72,72,72,0,0,0,0,0},
        {0,0,0,0,73,72,72,72,72,73,72,73,72,72,72,72,73,0,0,0,0},
        {0,0,0,0,73,72,71,72,72,73,73,73,72,72,73,72,73,0,0,0,0},
        {0,0,0,0,73,72,44,72,44,72,73,72,44,72,44,72,73,0,0,0,0},
        {0,0,0,0,71,72,0,44,0,0,72,0,0,44,0,72,73,0,0,0,0},
        {0,0,0,0,71,72,44,0,44,72,72,72,44,0,44,72,73,0,0,0,0},
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
    },
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
		{0,0,0,0,71,72,0,64,0,0,72,0,0,64,0,72,73,0,0,0,0},
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
    }};

	int iniX = x;
	int iniY = y;
	gotoxy(x, y);
	for (y=0;y<27;y++ ){
		for (x=0;x<24;x++){
			if (x==0) gotoxy(iniX,iniY+y);
			paintearD(terminator[numTer][y][x]);

		}
	}
}

void imprimirTerminatorLento(int x, int y, int numTer)
{
	int terminator[4][30][24]={
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
	},
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
	}};
	int iniX = x;
	int iniY = y;
	gotoxy(x, y);
	for (y=0;y<27;y++ ){
		for (x=0;x<23;x++){
			if (x==0) gotoxy(iniX,iniY+y);
			paintearD(terminator[numTer][y][x]);
			Sleep(1);
		}
	}

}

void imprimir_menu()
{
	int hudX = 10;
	cuadroBT("                 M E N U               ",hudX+0,0,GRIS_OSCURO,VERDEI);
	itemsNum(6, hudX + 3, 4, VERDEI);
	cuadroB("        Jugar        ",hudX+10,3,GRIS_OSCURO);
	cuadroB("    Instrucciones    ",hudX+10,7,GRIS_OSCURO);
	cuadroB("  Recuperar partida  ",hudX+10,11 ,GRIS_OSCURO);
	cuadroB("     Estadisticas    ",hudX+10,15,GRIS_OSCURO);
	cuadroB("       Creditos      ",hudX+10,19,GRIS_OSCURO);
	cuadroB("        Salir        ",hudX+10,23,GRIS_OSCURO);
	cuadroBT("      Ingrese una opcion:  << >>      ",hudX,26,GRIS_OSCURO,VERDEI);
}

int menu()
{
	system("cls");
	imprimirTerminator(XTER,YTER,0);
	imprimir_menu();
	int opcion = 0;
	gotoxy(40,27);
	setT(VERDEI);
	fflush(stdin);
	scanf("%d",&opcion);
	setD();
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
			break;
		case 3:
			data = cargadorPartida();
			if(data.idJuego>0) juego(data);
			break;
		case 4:
			system("cls");
			mostrarEstadisticas();
			break;
		case 5:
			creditos();
			break;
		default:
			return 99;

	}
	return 0;
}

void instrucciones()
{
   char c;
   int pag=1,hudX=5;
   cuadroBT("         I N S T R U C C I O N E S         ",hudX+3,0,GRIS_OSCURO,VERDEI);
   imprimirTerminator(XTER,YTER,0);
   cuadroBT("  a : retroceder | d : avanzar | m : volver al menu  ",hudX-1,27,GRIS_OSCURO,VERDEI);
   do{

    switch(pag){
    case 1:
        inst_pag_1();
        break;
    case 2:
        inst_pag_2();
        break;
    case 3:
        inst_pag_3();
        break;
    }
    gotoxy(27,25);
    setT(VERDEI);
    printf("<<");
    setD();
    printf("%i",pag);
    setT(VERDEI);
    printf("/");
    setD();
    printf("3");
    setT(VERDEI);
    printf(">>");
	setD();


    c=getch();

    if(c=='a')
    {
        if(pag>1)
        {
            pag--;
        }
    }
    else if(c=='d')
    {
        if(pag<3)
        {
            pag++;
        }
    }

   }while(c!='m');

}

void inst_pag_1()
{
    int hudX = 10;
    cuadroBU("Anagramaneitor es un juego para dos    ",hudX+0,3,MARRON,1,4,4,2,0,0,3,4,4); //top
    cuadroBU("jugadores, el cual consiste en que,    ",hudX+0,5,MARRON,4,4,4,0,0,0,4,4,4); //mids
    cuadroBU("por turnos, un jugador propone una     ",hudX+0,7,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroBU("palabra (rol ESCRITOR), y el otro      ",hudX+0,9,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroBU("jugador tiene 3 intentos para ingresar ",hudX+0,11,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroBU("un anagrama de la misma (ADIVINADOR).  ",hudX+0,13,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroBU("Se debe ingresar una palabra existente,",hudX+0,15,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroBU("es decir si la palabra ingresada es    ",hudX+0,17,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroBU("\"arbol\", no se puede ingresar \"rabol\", ",hudX+0,19,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroBU("debe ingresar, por ejemplo, \"labor\".   ",hudX,21,MARRON,4,4,5,0,0,2,4,4,6); //bot


}

void inst_pag_2()
{
    int hudX = 10;
	cuadroBU("Si el Adivinador logra ingresar un     ",hudX,3,MARRON,1,4,4,2,0,0,3,4,4); //top
	cuadroBU("anagrama en menos de 3 intentos, gana  ",hudX,5,MARRON,4,4,4,0,0,0,4,4,4); //mids
	cuadroBU("un punto. Si consume sus 3 intentos o  ",hudX,7,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("se rinde antes, el Escritor gana un    ",hudX,9,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("punto.                                 ",hudX,11,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("Una vez concluida la ronda, los        ",hudX,13,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("roles se invierten, asi no hay         ",hudX,15,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("desventajas para el segundo jugador.   ",hudX,17,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("Siempre al final de cada ronda se da   ",hudX,19,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("la opcion de dejar de jugar.           ",hudX,21,MARRON,4,4,5,0,0,2,4,4,6); //bot



}

void inst_pag_3()
{
    int hudX = 10;
	cuadroBU("RECUPERAR UNA PARTIDA                  ",hudX,3,MARRON,1,4,4,2,0,0,3,4,4); //top
	cuadroBU("Al inicio de cada juego, se le asigna  ",hudX,5,MARRON,4,4,4,0,0,0,4,4,4); //mids
	cuadroBU("un ID de partida. Para retomar la misma",hudX,7,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("se selecciona 3 en el menu principal,  ",hudX,9,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("                                       ",hudX,13,NEGRO,4,4,4,0,0,0,4,4,4);
	cuadroBU("se ingresa esa ID y listo, a jugar!!   ",hudX,11,MARRON,4,4,5,0,0,2,4,4,6); //bot, se imprime aca para que se vea
	cuadroBU("                                       ",hudX,15,NEGRO,4,4,4,0,0,0,4,4,4); //mids que borran la pagina anterior, hacen que se vea bien
	cuadroBU("                                       ",hudX,17,NEGRO,4,4,4,0,0,0,4,4,4);
	cuadroBU("                                       ",hudX,19,NEGRO,4,4,4,0,0,0,4,4,4);
	cuadroBU("                                       ",hudX,21,NEGRO,4,4,5,0,0,2,4,4,6);

}

struct juego setearData(){
	system("cls");
	struct juego data;
	data.idJuego = setearIdJuego();
	data.partidas=0;
    data.puntosEscritor=0;
	data.puntosAdivinador=0;
	srand(time(NULL));
    data.moneda=rand()%2;
    imprimirTerminator(XTER,YTER,1);
    cuadroB("  Jugador 1 ingrese su nombre:                           ",2,1,COLOR_ESCRI);
    ingresar_nombre(data.nombreEscritor,COLOR_ESCRI,relocate_x(strlen("  Jugador 1 ingrese su nombre: "),0,1,2),2);
    cuadroB("  Jugador 2 ingrese su nombre:                           ",2,4,COLOR_ADIV);
    ingresar_nombre(data.nombreAdivinador,COLOR_ADIV,relocate_x(strlen("  Jugador 2 ingrese su nombre: "),0,1,2),5);
	return data;
}

void juego(struct juego data)
{
	char diccionario[TDICC][TPALABRA];

    if(cargar_diccionario(diccionario)) return;

	int jugadorEmpieza = data.moneda;
    do{ //partida
    	system("cls");
        data.partidas++;
        if(data.partidas%2!=data.moneda) partida(data.nombreEscritor,&data.puntosEscritor,data.nombreAdivinador,&data.puntosAdivinador,diccionario, jugadorEmpieza, data.idJuego);
        else partida(data.nombreAdivinador,&data.puntosAdivinador,data.nombreEscritor,&data.puntosEscritor,diccionario, jugadorEmpieza, data.idJuego);

        if(jugadorEmpieza) jugadorEmpieza = 0;
		else jugadorEmpieza = 1;

    }while(continuar()==1);
    gameOver(data.nombreEscritor,data.puntosEscritor,data.nombreAdivinador,data.puntosAdivinador,data.partidas);
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
			if(c == '!'){
				c = 164;
			}
			diccionario[palabra][character] = c;
			character++;
		}
    }
    fclose(dicc);
    return 0;
}

void ingresar_nombre(char palabra[], int color, int x, int y)
{
	fflush(stdin);
	gotoxy(x,y);
    gets(palabra);
    while (esTexto(palabra)!=0)
    {


        setTF(BLANCO, ROJO);
        gotoxy(XTER+13,YTER+9);
        printf("ERROR");
        gotoxy(XTER+24,YTER+9);
        printf("ERROR");
        setD();
        int pos = relocate_x(strlen("ERROR"),0,6,7);
        cuadroBTU(" Ingrese solo letras... ", pos ,y+2,AZULI, VERDEI,1,4,5,2,0,2,3,4,6);
        pos = relocate_x(strlen(" Ingrese solo letras... "),0,6,pos);

        fflush(stdin);
        borrar(x, y, x + strlen(palabra), y + 1);
        gotoxy(x,y);
        gets(palabra);
        borrar(7, y+2, pos + 8, y + 6);
        imprimirTerminator(XTER, YTER,1);
    }

}

void partida(char nombrej1[],int *puntosj1,char nombrej2[], int *puntosj2,char diccionario[][TPALABRA], int jugadorEmpieza, int idJuego)
{
	imprimirTerminator(XTER,YTER,0);
    int intentos=0;
    int reintentar=1;
    int ganoj2 = 0; // 0 es que gano el jugador 1
    char palabraj1[LMAX],palabraj2[LMAX];

    int hudX=2,hudY=1;
    int x=0;
    cuadroBI(" ID: %03i ",hudX+0, hudY,GRIS_OSCURO,idJuego);
    cuadroBSU(" Puntos %s :",hudX+12,hudY+0,GRIS_OSCURO,nombrej1,1,4,5,2,0,2,2,0,2);
    x=relocate_x(strlen(" Puntos %s :"),strlen(nombrej1),0,hudX+12);
    cuadroBIU(" %02i  | ",x,hudY+0,GRIS_OSCURO,*puntosj1,2,0,2,2,0,2,2,0,2);
    x=relocate_x(strlen(" %i  | "),2,0,x);
    cuadroBSU("Puntos %s :",x,hudY+0,GRIS_OSCURO,nombrej2,2,0,2,2,0,2,2,0,2);
    x=relocate_x(strlen("Puntos %s :"),strlen(nombrej2),0,x);
    cuadroBIU(" %02i ",x,hudY+0,GRIS_OSCURO,*puntosj2,2,0,2,2,0,2,3,4,6);


    cuadroBS("%8s ingrese una palabra:                           ",hudX+0,hudY+3,COLOR_ESCRI,nombrej1);
    ingresar_palabra(palabraj1,diccionario, COLOR_ESCRI,relocate_x(strlen(" %s ingrese una palabra:"),15,2,hudX),hudY + 4);

    do{//intentos
        intentos++;
    	cuadroBSU(" Debes buscar un anagrama de esta palabra: %s ",hudX+0,hudY+3,COLOR_ESCRI,palabraj1,1,4,5,2,0,2,2,0,2);
    	x=relocate_x(strlen(" Debes buscar un anagrama de esta palabra: %s "),strlen(palabraj1),0,hudX+0);

        cuadroBSU("%8s ingrese una palabra:                           ",hudX+0,hudY+6,COLOR_ADIV,nombrej2,1,4,5,2,0,2,3,4,6);
        ingresar_palabra(palabraj2,diccionario, COLOR_ADIV,relocate_x(strlen(" %s ingrese una palabra:"),15,2,hudX),hudY + 7);
        if (strcmp(palabraj1,palabraj2)==0)reintentar=reintentarMenu(intentos);
        else
		{
            if (esAnagrama(palabraj1,palabraj2)==0)
			{
                ganoj2=1;
                break;
            }
            else
			{
                reintentar=reintentarMenu(intentos);
            }
        }
    }while(reintentar==1);
    if (ganoj2==1){
        *puntosj2=*puntosj2+1;
        cuadroBS("  Punto para %8s!!!  ",hudX+17,hudY+10,MARRON,nombrej2);

    }

    else{
    	*puntosj1=*puntosj1+1;
    	cuadroBS("  Punto para %8s!!!  ",hudX+17,hudY+10,MARRON,nombrej1);
	}

    crear_log(idJuego, palabraj1, nombrej1, nombrej2, intentos, ganoj2, jugadorEmpieza);

}

void crear_log(int idJuego,char anagrama[], char nombrej1[], char nombrej2[],int intentos, int ganador, int jugadorEmpieza)
{
	
	struct log log_partida;
	log_partida.idJuego = idJuego;
	strcpy(log_partida.anagrama, anagrama);
	strcpy(log_partida.nombreEscritor, nombrej1);
	strcpy(log_partida.nombreAdivinador, nombrej2);
	log_partida.intentos = intentos;
	log_partida.ganador = ganador; // 0 es que gano el escritor | 1 es que gano el adivinador
	log_partida.jugadorEmpieza = jugadorEmpieza;
	
	//DEBUG
	//gotoxy(0,25);
	//printf("\n\n%d: %s | %d | %d | %d\n\n",log_partida.idJuego, log_partida.anagrama, log_partida.intentos, log_partida.ganador, log_partida.jugadorEmpieza);

	FILE* f = fopen(FILE_LOG,"ab");
	fwrite(&log_partida, sizeof(struct log), 1, f);
	fclose(f);
}

int setearIdJuego()
{
	struct log l;
	FILE* f = fopen(FILE_LOG,"rb");
	if(!f) return 1;
	int cantidadJuegos = -1;
	fread(&l, sizeof(struct log), 1, f);
	while (!feof(f))
	{
		if(l.idJuego > cantidadJuegos){
			cantidadJuegos = l.idJuego;
		}
		fread(&l, sizeof(struct log), 1, f);
	}
	fread(&l, sizeof(struct log), 1, f);
	fclose(f);

	//printf("ID de juego: %d\n\n",cantidadJuegos + 1);
	return cantidadJuegos + 1;
}

void mostrarEstadisticas()
{
	system("cls");
	
	//logica
	FILE* f = fopen(FILE_LOG,"rb");
	struct log l;
	
	int cantidadPartidas = 0;
	int cantidadJuegos = 0;
	int cantidadIntentosTotal = 0;
	int ganaAdivinador = 0;
	int jugadorEmpieza = 0;
	
	fread(&l, sizeof(struct log), 1, f);
	while (!feof(f))
	{
		cantidadPartidas++;

		cantidadIntentosTotal+= l.intentos;

		ganaAdivinador+= l.ganador;

		if(l.idJuego > cantidadJuegos){
			cantidadJuegos = l.idJuego;
			jugadorEmpieza+= l.jugadorEmpieza;
		}

		fread(&l, sizeof(struct log), 1, f);
	}
	
	
	
	//interfaz
	int hudX = 10,hudY=3;
	imprimirTerminator(XTER,YTER,0);
	cuadroBTU("          E S T A D I S T I C A S          ",hudX-2,hudY-2,GRIS_OSCURO,VERDEI,1,4,5,2,0,2,3,4,6);
    cuadroBIU("          Juegos totales: %03d          ",hudX+0,hudY+3,MARRON,cantidadJuegos,1,4,4,2,0,0,3,4,4);
    cuadroBIU("         Partidas totales: %03d         ",hudX+0,hudY+5,MARRON, cantidadPartidas,4,4,4,0,0,0,4,4,4);
    cuadroBFU("        Partidas por juego: %4.1f       ",hudX+0,hudY+7,MARRON,(float) cantidadPartidas / cantidadJuegos,4,4,4,0,0,0,4,4,4);
    cuadroBFU("       Intentos por partida: %4.1f      ",hudX+0,hudY+9,MARRON,(float)cantidadIntentosTotal / cantidadPartidas,4,4,4,0,0,0,4,4,4);
    cuadroBFU("      Inicios de Jugador 1: %5.1f %%    ",hudX+0,hudY+11,MARRON,(float)(cantidadJuegos - jugadorEmpieza)*100/cantidadJuegos,4,4,4,0,0,0,4,4,4);
    cuadroBFU("      Inicios de Jugador 2: %5.1f %%    ",hudX+0,hudY+13,MARRON,(float)jugadorEmpieza * 100 / cantidadJuegos,4,4,4,0,0,0,4,4,4);
    cuadroBFU("         Gana Escritor: %5.1f %%        ",hudX+0,hudY+15,MARRON,(float)(cantidadPartidas - ganaAdivinador) * 100 / cantidadPartidas,4,4,4,0,0,0,4,4,4);
    cuadroBFU("        Gana Adivinador: %5.1f %%       ",hudX+0,hudY+17,MARRON,(float)ganaAdivinador * 100 / cantidadPartidas,4,4,5,0,0,2,4,4,6);
    cuadroBT(" m : volver al menu  ",hudX+10,26,GRIS_OSCURO,VERDEI);
	
	while(getch()!='m');

}

struct juego cargadorPartida()
{
	int idJuego;
	
	//interfaz
	imprimirTerminator(XTER,YTER,1);
	cuadroBTU("   R E C U P E R A R   P A R T I D A   ",15,1,GRIS_OSCURO,VERDEI,1,4,5,2,0,2,3,4,6);
	cuadroBT(" Ingrese su ID de juego: <<  >>  ",18,13,MARRON,GRIS_CLARO);
	cuadroBTU(" Para volver al menu, ingrese 0 ",18,26,GRIS_OSCURO,VERDEI,1,4,5,2,0,2,3,4,6);
	gotoxy(relocate_x(strlen(" Ingrese su ID de juego: << "),0,0,18),14);
	scanf("%d",&idJuego);
	
	//logica
	struct log l;
	struct juego data;
	//salida directa al menu
	if(idJuego<=0){
        data.idJuego=-999;
        return data;
	}
	
	FILE* f = fopen(FILE_LOG,"rb");
	fread(&l, sizeof(struct log), 1, f);
	while (!feof(f) && l.idJuego != idJuego)
	{
		fread(&l, sizeof(struct log), 1, f);
	}
	
	//si no encuentra el log de tu partida, te pide que crees una nueva
	if( l.idJuego != idJuego){
		return setearData();
	} 
	
	
	data.idJuego = l.idJuego;
	data.moneda = l.jugadorEmpieza;
	if(!l.jugadorEmpieza) { //false = 0 !-> true
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

	while (!feof(f))
	{
		if( l.idJuego == idJuego){
			if(l.ganador == l.jugadorEmpieza)	data.puntosEscritor++;
			else data.puntosAdivinador++;
			data.partidas++;
		}
		fread(&l, sizeof(struct log), 1, f);
	}

	fclose(f);
	//printf("\n| ID: %2d | J1: \"%s\" Puntos: %d | J2: \"%s\" Puntos: %d |\n\n ",data.idJuego, data.nombreAdivinador, data.puntosAdivinador, data.nombreEscritor, data.puntosEscritor);
	return data;

}

int continuar()
{
	int respuesta;
	int hudX = 20;
	int hudY = 15;
	cuadroBU("    Fin de la partida!   ",hudX,hudY,MARRON,1,4,4,2,0,0,3,4,4);
	cuadroBU("Desea jugar otra partida?",hudX,hudY + 2,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("   1. Si        2. No    ",hudX,hudY + 4,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroBU("          << >>          ",hudX,hudY + 6,MARRON,4,4,5,0,0,2,4,4,6);
	fflush(stdin); 
	gotoxy(hudX + 13,hudY + 7);
	scanf("%d",&respuesta);
	borrar(hudX, hudY,hudX + 28, hudY + 9);
	return respuesta;
}

int reintentarMenu(int intentos)
{
	imprimirTerminator(XTER, YTER,2);
	if(intentos >= 3) return 0;
	int respuesta;
	int hudX = 20;
	int hudY = 11;
	cuadroBU("        Lo siento!       ",hudX,hudY,GRIS_OSCURO,1,4,4,2,0,0,3,4,4);
	cuadroBU("Desea intentar de nuevo? ",hudX,hudY + 2,GRIS_OSCURO,4,4,4,0,0,0,4,4,4);
	cuadroBIU("  Quedan <<%i>> intentos  ",hudX,hudY + 4,GRIS_OSCURO,3-intentos,4,4,4,0,0,0,4,4,4);
	cuadroBU("   1. Si        2. No    ",hudX,hudY + 6,GRIS_OSCURO,4,4,4,0,0,0,4,4,4);
	cuadroBU("         << >>           ",hudX,hudY + 8,GRIS_OSCURO,4,4,5,0,0,2,4,4,6);
	fflush(stdin);
	gotoxy(hudX + 12,hudY + 9);
	scanf("%d",&respuesta);
	imprimirTerminator(XTER, YTER,1);
	borrar(hudX, hudY,hudX + 28, hudY + 11);


	return respuesta;
}

void ingresar_palabra(char palabra[], char diccionario[][TPALABRA], int color, int x, int y)
{
	gotoxy(x,y);
    fflush(stdin);
    gets(palabra);
    while (buscarPalabra(diccionario,palabra)!=0)
    {
        setTF(BLANCO, ROJO);
        gotoxy(XTER+13,YTER+9);
        printf("ERROR");
        gotoxy(XTER+24,YTER+9);
        printf("ERROR");
        setD();
        int pos = relocate_x(strlen("ERROR"),0,6,7);
        cuadroBT(" Ingrese una palabra valida...  ", pos ,y+2,AZULI, VERDEI);
        pos = relocate_x(strlen(" Ingrese una palabra valida...  "),0,6,pos);
        fflush(stdin);
        borrar(x, y, x + strlen(palabra), y + 1);
        gotoxy(x,y);
        gets(palabra);
        borrar(7, y+2, pos + 8, y + 6);
        imprimirTerminator(XTER, YTER,1);
    }
}

int buscarPalabra(char dicci[][TPALABRA], char palabra[])
{
    int i = 0;
    while(strcmp(palabra,dicci[i])!=0 && i < TDICC) i++;
    //printf("\nNumero de palabra: %i\n",i);
    if(i != TDICC) return 0;
    else return 1;
}

int esTexto(char cad[])
{
    int lcad = strlen(cad), i=0,cont=0,rta=0;
    strlwr(cad);
    for (i=0;i<lcad;i++){if (cad[i]>=97 && cad[i]<=122)cont++;}
    if (cont==lcad)rta=0;
    else rta=1;
    return rta;
}

int esAnagrama(char cad1[], char cad2[])
{
    int lcad=strlen(cad1);
    char cadAux[LMAX];
    strcpy(cadAux,cad1);
    int rta=1,i,j,cont=0;


	//aba Baa cont=0
	//a!a bAa cont=1
	//!!a baA cont=2
	//!!! baA cont=3
	//cont 3 == lcad 3 -> true
	
    if(lcad==strlen(cad2))
    {
        for (i=0;i<lcad;i++)
        {
            for(j=0;j<lcad;j++)
            {
                if(cad2[i]==cadAux[j])//comparacion de cad1 (aux) contra cad2
                {
                    cadAux[j]='!';
                    cont++;
                    break;
                }
            }
        }
        if(lcad==cont) rta=0;
    }
    return rta;
}

void gameOver(char nombrej1[],int puntosj1,char nombrej2[],int puntosj2,int partidas)
{
    system("cls");
    int hudX=10,hudY=3;
    int x;
    cuadroB("         F I N    D E L    J U E G O         ",hudX-3,hudY-2,MARRON);
    cuadroBIU("          Partidas jugadas: %02i         ",hudX,hudY+3,GRIS_OSCURO,partidas,1,4,4,2,0,0,3,4,4);
    cuadroBU("            Puntaje final:             ",hudX,hudY+5,GRIS_OSCURO,4,4,4,0,0,0,4,4,4);
    cuadroBSU("     %15s :",hudX,hudY+7,GRIS_OSCURO,nombrej1,4,4,4,0,0,0,0,0,0);
    x=relocate_x(strlen("     %s :"),15,0,hudX);
    cuadroBIU("%02i             ",x,hudY+7,GRIS_OSCURO,puntosj1,0,0,0,0,0,0,4,4,4);
    cuadroBSU("     %15s :",hudX,hudY+9,GRIS_OSCURO,nombrej2,4,4,5,0,0,2,0,0,2);
    x=relocate_x(strlen("     %s :"),15,0,hudX);
    cuadroBIU("%02i             ",x,hudY+9,GRIS_OSCURO,puntosj2,0,0,2,0,0,2,4,4,6);

    if(puntosj1 > puntosj2)
    {
        cuadroBS(" GANASTE, %8s!!! ",hudX+9,hudY+15,MARRON,nombrej1);

    }
    else{
        if(puntosj1 == puntosj2) cuadroB(" EMPATARON!!! ",hudX+13,hudY+15,MARRON);
        else cuadroBS(" GANASTE, %8s!!! ",hudX+9,hudY+15,MARRON,nombrej2);

    }
    cuadroBT(" m : volver al menu  ",hudX+10,26,GRIS_OSCURO,VERDEI);
    int i;
	for(i=0;i<10;i++)
    {
        imprimirTerminator(XTER,YTER,1);
        gotoxy(0,0);
        Sleep(100);
        imprimirTerminator(XTER,YTER,3);
        gotoxy(0,0);
        Sleep(100);

    }
    
	while(getch()!='m');
}

void creditos()
{
    int hudX = 10,hudY=2;
    imprimirTerminator(XTER,YTER,0);
    setT(CIAN_INTENSO);
    gotoxy(XTER+14,YTER+9);
    printf("MU");
    setT(AZUL);
    gotoxy(XTER+26,YTER+9);
    printf("MP");
    setD();

    cuadroBT("              C R E D I T O S              ",hudX-2,hudY-1,GRIS_OSCURO,VERDEI);

    cuadroBTU("            Programado por:            ",hudX+0,hudY+3,MARRON,MAGENTA,1,4,4,2,0,0,3,4,4); //top
    cuadroBTU("       Matias G. Picon (X7REME13)      ",hudX+0,hudY+5,MARRON,AZUL,4,4,4,0,0,0,4,4,4); //mids
    cuadroBTU("     Marcelo G. Ulrich (Marchelox)     ",hudX+0,hudY+7,MARRON,CIAN_INTENSO,4,4,5,0,0,2,4,4,6); //bot
   
    cuadroBTU("           Agradecimientos:            ",hudX+0,hudY+11,MARRON,MAGENTA,1,4,4,2,0,0,3,4,4); //top
    cuadroBU("A Luna Cosentino por la idea del juego.",hudX+0,hudY+13,MARRON,4,4,4,0,0,0,4,4,4); //mids
    cuadroBU("A Rolo por bancarnos e impulsarnos a   ",hudX+0,hudY+15,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroBU("       realizar este proyecto.         ",hudX+0,hudY+17,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroBU("A Johi por ayudarnos con la estetica.  ",hudX+0,hudY+19,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroBU("A Pablo Lavezzi por la libreria VIDEO. ",hudX,hudY+21,MARRON,4,4,5,0,0,2,4,4,6); //bot
    
	cuadroBT(" m : volver al menu  ",hudX+10,27,GRIS_OSCURO,VERDEI);
    
	while(getch()!='m');

}



