#include <windows.h>
#include <stdio.h>

//------------COLORES----------------
#define NEGRO 0X0000
#define AZUL 0X0001
#define VERDE 0X0002
#define CIAN 0X0003
#define ROJO 0X0004
#define MAGENTA 0X0005
#define MARRON 0X0006
#define GRIS_CLARO 0X0007
#define GRIS_OSCURO 0X0008
#define AZUL_INTENSO 0X0009
#define AZULI 0X0009
#define VERDE_INTENSO 0X000A
#define VERDEI 0X000A
#define CIAN_INTENSO 0X000B
#define CIANI 0X000B
#define ROJO_INTENSO 0X000C
#define ROJOI 0X000C
#define MAGENTA_INTENSO 0X000D
#define MAGENTAI 0X000D
#define AMARILLO_INTENSO 0X000E
#define AMARILLOI 0X000E
#define BLANCO 0X000F
#define BLANCOI 0X000F
#define BLANCO_INTENSO 0X000F
//-----------ABREVIACIONES-----------
#define setD setDefault
#define setT setTexto
#define setTF setTextoFondo


void gotoxy(int x, int y){
        HANDLE hCon;
        hCon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X=x;
        dwPos.Y=y;
        SetConsoleCursorPosition(hCon,dwPos);
}

void setDefault() {
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hCon,GRIS_CLARO);
}

void setTexto(int texto) {
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hCon,texto);
}

void setTextoFondo(int texto, int fondo){
    HANDLE hCon;
    int numero;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    numero = fondo*16+texto;
	SetConsoleTextAttribute (hCon,numero);
}

void setTitle (const char *texto){
    SetConsoleTitle(texto);
}

//creador en C++: Pablo Lavezzi
//traduccion a C: Matias Picon
