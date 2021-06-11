#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <conio.h> //para getch()

#define LMAX 100
#define TDICC 80500
#define TPALABRA 24

#define FILE_LOG "log.dat"
#define FILE_DICC "dicc.txt"

#define XTER 70
#define YTER 1

#define COLOR_ESCRI ROJO
#define COLOR_ADIV GRIS_CLARO

#include "VIDEO.c"


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

void imprimir_terminator_lento(int x, int y, int numTer);
void imprimir_terminator(int x, int y, int numTer);
int continuar();
int reintentarMenu(int intentos);
int reintentar_menu(int intentos);
int es_anagrama(char cad1[], char cad2[]);
void game_over(char nombrej1[],int puntosj1,char nombrej2[],int puntosj2,int partidas);
int es_texto(char cad[]);
void partida(char nombrej1[],int *puntosj1,char nombrej2[], int *puntosj2,char diccionario[][TPALABRA], int jugador_empieza, int idJuego);
void ingresar_nombre(char palabra[], int color, int x, int y);
void ingresar_palabra(char palabra[], char diccionario[][TPALABRA], int color, int x, int y);
int cargar_diccionario(char diccionario[][TPALABRA]);
int buscar_palabra(char diccionario[][TPALABRA], char palabra[]);
void juego(struct juego);

void crear_log(int,char anagrama[], char nombrej1[], char nombrej2[], int intentos, int ganador, int jugador_empieza);
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
int relocate_x(int largo_acompanamiento, int largo_variable, int espaciado,int hudx);
void borrar(int inix, int iniy, int endx, int endy);



// --------------------MAIN------------------------

int main()
{
	SetConsoleTitle("<<< ANAGRAMANEITOR >>>");
	//bienvenida();
	do{
	}while(menu() != 99);
}


void bienvenida()
{
	imprimir_terminator_lento(10,YTER, 1);
	int i;
	for(i = 0; i < (XTER-10)/2; i++){

		imprimir_terminator(10+(i*2), YTER,1);
		//gotoxy(0,0);
		Sleep(80);
	}
}

void imprimir_terminator(int x, int y, int numTer){
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
	for (y=0;y<28;y++ ){

		for (x=0;x<24;x++){
			if (x==0 && y>0) gotoxy(iniX,y+iniY);
			Sleep(0);
			paintearD(terminator[numTer][y][x]);

		}
	}
}

void imprimir_terminator_lento(int x, int y, int numTer)
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
	for (y=0;y<28;y++ ){

		for (x=0;x<24;x++){
			if (x==0 && y>0) gotoxy(iniX,y+iniY);
			Sleep(1);
			paintearD(terminator[numTer][y][x]);

		}
	}

}

void imprimir_menu()
{
	int hudX = 10;
	cuadroTF_gral("                 M E N U               ",hudX+0,0,GRIS_OSCURO,VERDEI,1,4,5,2,0,2,3,4,6);
	itemsNum(6, hudX + 3, 4, VERDEI);
	cuadroT_gral("        Jugar        ",hudX+10,3,GRIS_OSCURO,1,4,5,2,0,2,3,4,6);
	cuadroT_gral("    Instrucciones    ",hudX+10,7,GRIS_OSCURO,1,4,5,2,0,2,3,4,6);
	cuadroT_gral("  Recuperar partida  ",hudX+10,11 ,GRIS_OSCURO,1,4,5,2,0,2,3,4,6);
	cuadroT_gral("     Estadisticas    ",hudX+10,15,GRIS_OSCURO,1,4,5,2,0,2,3,4,6);
	cuadroT_gral("       Creditos      ",hudX+10,19,GRIS_OSCURO,1,4,5,2,0,2,3,4,6);
	cuadroT_gral("        Salir        ",hudX+10,23,GRIS_OSCURO,1,4,5,2,0,2,3,4,6);
	cuadroTF_gral("      Ingrese una opcion:  << >>      ",hudX,26,GRIS_OSCURO,VERDEI,1,4,5,2,0,2,3,4,6);
}

int menu()
{
	system("cls");
	imprimir_terminator(XTER,YTER,0);
	imprimir_menu();
	int opcion = 0;
	gotoxy(40,27);
	setT(VERDEI);
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
			if(data.idJuego>0)juego(data);
			break;
		case 4:
			system("cls");
			mostrarEstadisticas();
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
   int pag=1,hudX=5;
   cuadroTF_gral("         I N S T R U C C I O N E S         ",hudX+3,0,GRIS_OSCURO,VERDEI,1,4,5,2,0,2,3,4,6);
   imprimir_terminator(XTER,YTER,0);
   cuadroTF_gral("  a : retroceder | d : avanzar | m : volver al menu  ",hudX-1,27,GRIS_OSCURO,VERDEI,1,4,5,2,0,2,3,4,6);
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
    cuadroT_gral("Anagramaneitor es un juego para dos    ",hudX+0,3,MARRON,1,4,4,2,0,0,3,4,4);
    cuadroT_gral("jugadores, el cual consiste en que,    ",hudX+0,5,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroT_gral("por turnos, un jugador propone una     ",hudX+0,7,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroT_gral("palabra y el otro jugador tiene 3      ",hudX+0,9,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroT_gral("intentos para ingresar un anagrama de  ",hudX+0,11,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroT_gral("la misma. Para que se considere intento",hudX+0,13,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroT_gral("se debe ingresar una palabra existente,",hudX+0,15,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroT_gral("es decir si la palabra ingresada es    ",hudX+0,17,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroT_gral("arbol, no se puede poner rabol, tiene  ",hudX+0,19,MARRON,4,4,4,0,0,0,4,4,4);
    cuadroT_gral("que ser, por ejemplo labor.            ",hudX,21,MARRON,4,4,5,0,0,2,4,4,6);


}

void inst_pag_2()
{
    int hudX = 10;
	cuadroT_gral("Si el jugador logra ingresar un        ",hudX,3,MARRON,1,4,4,2,0,0,3,4,4);
	cuadroT_gral("anagrama en menos de 3 intentos, gana  ",hudX,5,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("un punto. Si consume sus 3 intentos o  ",hudX,7,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("se rinde antes, el jugador que         ",hudX,9,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("propuso la palabra gana un punto.      ",hudX,11,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("Una vez concluida la ronda, los        ",hudX,13,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("turnos se invierten, asi no hay        ",hudX,15,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("desventajas para el segundo jugador.   ",hudX,17,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("Siempre al final de cada ronda se da   ",hudX,19,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("la opcion de dejar de jugar.           ",hudX,21,MARRON,4,4,5,0,0,2,4,4,6);



}

void inst_pag_3()
{
    int hudX = 10;
	cuadroT_gral("RECUPERAR UNA PARTIDA                  ",hudX,3,MARRON,1,4,4,2,0,0,3,4,4);
	cuadroT_gral("Al inicio de cada juego, se le asigna  ",hudX,5,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("un ID de partida. Para retomar la misma",hudX,7,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("se selecciona 3 en el menu principal,  ",hudX,9,MARRON,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("                                       ",hudX,13,NEGRO,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("se ingresa esa ID y listo, a jugar!!   ",hudX,11,MARRON,4,4,5,0,0,2,4,4,6);
	cuadroT_gral("                                       ",hudX,15,NEGRO,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("                                       ",hudX,17,NEGRO,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("                                       ",hudX,19,NEGRO,4,4,4,0,0,0,4,4,4);
	cuadroT_gral("                                       ",hudX,21,NEGRO,4,4,5,0,0,2,4,4,6);

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
    imprimir_terminator(XTER,YTER,1);
    cuadroT_gral("  Jugador 1 ingrese su nombre:                           ",2,1,COLOR_ESCRI,1,4,5,2,0,2,3,4,6);
    ingresar_nombre(data.nombreEscritor,COLOR_ESCRI,relocate_x(strlen("  Jugador 1 ingrese su nombre: "),0,1,2),2);
    cuadroT_gral("  Jugador 2 ingrese su nombre:                           ",2,4,COLOR_ADIV,1,4,5,2,0,2,3,4,6);
    ingresar_nombre(data.nombreAdivinador,COLOR_ADIV,relocate_x(strlen("  Jugador 2 ingrese su nombre: "),0,1,2),5);
	return data;
}

void juego(struct juego data)
{
	char diccionario[TDICC][TPALABRA];

    if(cargar_diccionario(diccionario)) return;

	int jugador_empieza = data.moneda;
    do{ //partida
    	system("cls");
        data.partidas++;

        if(data.partidas%2!=data.moneda) partida(data.nombreEscritor,&data.puntosEscritor,data.nombreAdivinador,&data.puntosAdivinador,diccionario, jugador_empieza, data.idJuego);
        else partida(data.nombreAdivinador,&data.puntosAdivinador,data.nombreEscritor,&data.puntosEscritor,diccionario, jugador_empieza, data.idJuego);

        if(jugador_empieza) jugador_empieza = 0;
		else jugador_empieza = 1;

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
    while (es_texto(palabra)!=0)
    {


        setTF(BLANCO, ROJO);
        gotoxy(XTER+13,YTER+9);
        printf("ERROR");
        gotoxy(XTER+24,YTER+9);
        printf("ERROR");
        setD();
        int pos = relocate_x(strlen("ERROR"),0,6,7);
        cuadroTF_gral(" Ingrese solo letras... ", pos ,y+2,AZULI, VERDEI,1,4,5,2,0,2,3,4,6);
        pos = relocate_x(strlen(" Ingrese solo letras... "),0,6,pos);

        fflush(stdin);
        borrar(x, y, x + strlen(palabra), y + 1);
        gotoxy(x,y);
        gets(palabra);
        borrar(7, y+2, pos + 8, y + 6);
        imprimir_terminator(XTER, YTER,1);
    }

}

void partida(char nombrej1[],int *puntosj1,char nombrej2[], int *puntosj2,char diccionario[][TPALABRA], int jugador_empieza, int idJuego)
{
	imprimir_terminator(XTER,YTER,0);
    int intentos=0;
    int reintentar=1;
    int ganoj2 = 0;
    int hudx=2,hudy=1;
    int x=0;
    char palabraj1[LMAX],palabraj2[LMAX];

    cuadroIT_gral(" ID: %03i ",hudx+0, hudy,GRIS_OSCURO,idJuego,1,4,5,2,0,2,3,4,6);
    cuadroST_gral(" Puntos %s :",hudx+12,hudy+0,GRIS_OSCURO,nombrej1,1,4,5,2,0,2,2,0,2);
    x=relocate_x(strlen(" Puntos %s :"),strlen(nombrej1),0,hudx+12);
    cuadroIT_gral(" %02i  | ",x,hudy+0,GRIS_OSCURO,*puntosj1,2,0,2,2,0,2,2,0,2);
    x=relocate_x(strlen(" %i  | "),2,0,x);
    cuadroST_gral("Puntos %s :",x,hudy+0,GRIS_OSCURO,nombrej2,2,0,2,2,0,2,2,0,2);
    x=relocate_x(strlen("Puntos %s :"),strlen(nombrej2),0,x);
    cuadroIT_gral(" %02i ",x,hudy+0,GRIS_OSCURO,*puntosj2,2,0,2,2,0,2,3,4,6);


    cuadroST_gral("%15s ingrese una palabra:                           ",hudx+0,hudy+3,COLOR_ESCRI,nombrej1,1,4,5,2,0,2,3,4,6);
    ingresar_palabra(palabraj1,diccionario, COLOR_ESCRI,relocate_x(strlen(" %s ingrese una palabra:"),15,2,hudx),hudy + 4);

    do{//intentos
        intentos++;
        //arreglar la palabra
    	cuadroST_gral(" Debes buscar un anagrama de esta palabra: %s ",hudx+0,hudy+3,COLOR_ESCRI,palabraj1,1,4,5,2,0,2,2,0,2);
    	x=relocate_x(strlen(" Debes buscar un anagrama de esta palabra: %s "),strlen(palabraj1),0,hudx+0);

        cuadroST_gral("%15s ingrese una palabra:                           ",hudx+0,hudy+6,COLOR_ADIV,nombrej2,1,4,5,2,0,2,3,4,6);
        ingresar_palabra(palabraj2,diccionario, COLOR_ADIV,relocate_x(strlen(" %s ingrese una palabra:"),15,2,hudx),hudy + 7);
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

int relocate_x(int largo_acompanamiento, int largo_variable, int espaciado,int hudx)  //espaciado es si quiero que el cuadro quede pegado o separado
{
   int dist_x=largo_acompanamiento+largo_variable+espaciado;
   return hudx+dist_x;
}

int relocate_y(int posicion,int hudy) // 0 para = linea, 3 para u renglon abajo y asi
{
    int dist_y=hudy+posicion;
    return dist_y;
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
	gotoxy(0,25);
	//printf("\n\n%d: %s | %d | %d | %d\n\n",log_partida.idJuego, log_partida.anagrama, log_partida.intentos, log_partida.ganador, log_partida.jugador_empieza);

	FILE* f = fopen("log.dat","ab");
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
	FILE* f = fopen(FILE_LOG,"rb");
	struct log l;
	int cantidadPartidas = 0;
	int cantidadJuegos = 0;
	int cantidadIntentosTotal = 0;
	int jugadorGanador = 0;
	int jugadorEmpieza = 0;
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
	int hudX = 10,hudY=3;
	imprimir_terminator(XTER,YTER,0);
	cuadroTF_gral("          E S T A D I S T I C A S          ",hudX-2,hudY-2,GRIS_OSCURO,VERDEI,1,4,5,2,0,2,3,4,6);
    cuadroIT_gral("          Juegos totales: %03d          ",hudX+0,hudY+3,MARRON,cantidadJuegos,1,4,4,2,0,0,3,4,4);
    cuadroIT_gral("         Partidas totales: %03d         ",hudX+0,hudY+5,MARRON, cantidadPartidas,4,4,4,0,0,0,4,4,4);
    cuadroFT_gral("        Partidas por juego: %4.1f       ",hudX+0,hudY+7,MARRON,(float) cantidadPartidas / cantidadJuegos,4,4,4,0,0,0,4,4,4);
    cuadroFT_gral("       Intentos por partida: %4.1f      ",hudX+0,hudY+9,MARRON,(float)cantidadIntentosTotal / cantidadPartidas,4,4,4,0,0,0,4,4,4);
    cuadroFT_gral("      Inicios de Jugador 1: %5.1f %%    ",hudX+0,hudY+11,MARRON,(float)(cantidadJuegos - jugadorEmpieza)*100/cantidadJuegos,4,4,4,0,0,0,4,4,4);
    cuadroFT_gral("      Inicios de Jugador 2: %5.1f %%    ",hudX+0,hudY+13,MARRON,(float)jugadorEmpieza * 100 / cantidadJuegos,4,4,4,0,0,0,4,4,4);
    cuadroFT_gral("         Gana Escritor: %5.1f %%        ",hudX+0,hudY+15,MARRON,(float)(cantidadPartidas - jugadorGanador) * 100 / cantidadPartidas,4,4,4,0,0,0,4,4,4);
    cuadroFT_gral("        Gana Adivinador: %5.1f %%       ",hudX+0,hudY+17,MARRON,(float)jugadorGanador * 100 / cantidadPartidas,4,4,5,0,0,2,4,4,6);
    printf("\n");
    cuadroTF(" m : volver al menu  ",hudX+10,26,GRIS_OSCURO,VERDEI);
	do{
	}while(getch()!='m');

}

struct juego cargadorPartida()
{
	int idJuego;
	imprimir_terminator(XTER,YTER,1);
	cuadroTF_gral("   R E C U P E R A R   P A R T I D A   ",15,1,GRIS_OSCURO,VERDEI,1,4,5,2,0,2,3,4,6);
	cuadroTF(" Ingrese su ID de juego: <<  >>  ",18,13,MARRON,GRIS_CLARO);
	cuadroTF_gral(" Para volver al menu, ingrese 0 ",18,26,GRIS_OSCURO,VERDEI,1,4,5,2,0,2,3,4,6);
	gotoxy(relocate_x(strlen(" Ingrese su ID de juego: << "),0,0,18),14);
	scanf("%d",&idJuego);
	struct log l;
	struct juego data;
	if(idJuego<=0){
        data.idJuego=-999;
        return data;
	}
	FILE* f = fopen("log.dat","rb");
	fread(&l, sizeof(struct log), 1, f);
	while (!feof(f) && l.idJuego != idJuego)
	{
		fread(&l, sizeof(struct log), 1, f);
	}


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

	while (!feof(f))
	{
		if( l.idJuego == idJuego){
			if(l.ganador == l.jugador_empieza)	data.puntosEscritor++;
			else data.puntosAdivinador++;
			data.partidas++;
		}
		fread(&l, sizeof(struct log), 1, f);
	}

	fclose(f);
	//printf("\n| ID: %2d | J1: \"%s\" Puntos: %d | J2: \"%s\" Puntos: %d |\n\n ",data.idJuego, data.nombreAdivinador, data.puntosAdivinador, data.nombreEscritor, data.puntosEscritor);
	return data;

}

void borrar(int inix, int iniy, int endx, int endy){
	int x, y;
	setD();
	for(y = iniy; y < endy; y++){
		for(x = inix; x < endx; x++){
			gotoxy(x,y);
			printf(" ");
		}
	}
}


int continuar()
{
	int respuesta;
	int hudX = 20;
	int hudY = 11;
	cuadroTtop("    Fin de la partida!   ",hudX,hudY,MARRON);
	cuadroTmid("Desea jugar otra partida?",hudX,hudY + 2,MARRON);
	cuadroTmid("   1. Si        2. No    ",hudX,hudY + 4,MARRON);
	cuadroTbot("         << >>           ",hudX,hudY + 6,MARRON);
	fflush(stdin); // tuve que googlearlo para que ande
	gotoxy(hudX + 12,hudY + 7);
	scanf("%d",&respuesta);
	borrar(hudX, hudY,hudX + 28, hudY + 9);
	return respuesta;
}


int reintentar_menu(int intentos)
{
	imprimir_terminator(XTER, YTER,2);
	if(intentos >= 3) return 0;
	int respuesta;
	int hudX = 20;
	int hudY = 11;
	cuadroTtop("        Lo siento!       ",hudX,hudY,GRIS_OSCURO);
	cuadroTmid("Desea intentar de nuevo? ",hudX,hudY + 2,GRIS_OSCURO);
	cuadroITmid("  Quedan <<%i>> intentos  ",hudX,hudY + 4,GRIS_OSCURO,3-intentos);
	cuadroTmid("   1. Si        2. No    ",hudX,hudY + 6,GRIS_OSCURO);
	cuadroTbot("         << >>           ",hudX,hudY + 8,GRIS_OSCURO);
	fflush(stdin); // tuve que googlearlo para que ande
	gotoxy(hudX + 12,hudY + 9);
	scanf("%d",&respuesta);
	imprimir_terminator(XTER, YTER,1);
	borrar(hudX, hudY,hudX + 28, hudY + 11);


	return respuesta;
}

void ingresar_palabra(char palabra[], char diccionario[][TPALABRA], int color, int x, int y)
{
	gotoxy(x,y);
    fflush(stdin);
    gets(palabra);
    while (buscar_palabra(diccionario,palabra)!=0)
    {
        setTF(BLANCO, ROJO);
        gotoxy(83,10);
        printf("ERROR");
        gotoxy(94,10);
        printf("ERROR");
        setD();
        int pos = relocate_x(strlen("ERROR"),0,6,7);
        cuadroTF(" Ingrese una palabra valida...  ", pos ,y+2,AZULI, VERDEI);
        pos = relocate_x(strlen(" Ingrese una palabra valida...  "),0,6,pos);
        fflush(stdin);
        borrar(x, y, x + strlen(palabra), y + 1);
        gotoxy(x,y);
        gets(palabra);
        borrar(7, y+2, pos + 8, y + 6);
        imprimir_terminator(XTER, YTER,1);
    }
}

int buscar_palabra(char dicci[][TPALABRA], char palabra[])
{
    int i = 0;
    while(strcmp(palabra,dicci[i])!=0 && i < TDICC) i++;
    //printf("\nNumero de palabra: %i\n",i);
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
    system("cls");
    int hudx=10,hudy=3;
    int x;
    cuadroT("         F I N    D E L    J U E G O         ",hudx-3,hudy-2,MARRON);
    cuadroITtop("          Partidas jugadas: %02i         ",hudx,hudy+3,GRIS_OSCURO,partidas);
    cuadroTmid("            Puntaje final:             ",hudx,hudy+5,GRIS_OSCURO);
    cuadroST_gral("     %15s :",hudx,hudy+7,GRIS_OSCURO,nombrej1,4,4,4,0,0,0,0,0,0);
    x=relocate_x(strlen("     %s :"),15,0,hudx);
    cuadroIT_gral("%02i             ",x,hudy+7,GRIS_OSCURO,puntosj1,0,0,0,0,0,0,4,4,4);
    cuadroST_gral("     %15s :",hudx,hudy+9,GRIS_OSCURO,nombrej2,4,4,5,0,0,2,0,0,2);
    x=relocate_x(strlen("     %s :"),15,0,hudx);
    cuadroIT_gral("%02i             ",x,hudy+9,GRIS_OSCURO,puntosj2,0,0,2,0,0,2,4,4,6);

    if(puntosj1 > puntosj2)
    {
        cuadroST(" GANASTE, %7s!!! ",hudx+9,hudy+15,MARRON,nombrej1);

    }
    else{
        if(puntosj1 == puntosj2) cuadroT(" EMPATARON!!! ",hudx+13,hudy+15,MARRON);
        else cuadroST(" GANASTE, %7s!!! ",hudx+9,hudy+15,MARRON,nombrej2);

    }
    cuadroTF(" m : volver al menu  ",hudx+10,26,GRIS_OSCURO,VERDEI);
	for(int i=0;i<10;i++)
    {
        imprimir_terminator(XTER,YTER,1);
        gotoxy(0,0);
        Sleep(100);
        imprimir_terminator(XTER,YTER,3);
        gotoxy(0,0);
        Sleep(100);

    }
	do{
	}while(getch()!='m');


}



