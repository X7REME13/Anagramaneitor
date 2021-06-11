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
#define ROJO_INTENSO 0X000C
#define ROJOI 0X000C
#define MAGENTA_INTENSO 0X000D
#define MAGENTAI 0X000D
#define AMARILLO_INTENSO 0X000E
#define AMARILLOI 0X000E
#define JOHI 0X000E
#define BLANCO_INTENSO 0X000F
#define BLANCO 0X000F
#define BLANCOI 0X000F
#define ROJOJO 0X0007



//---------------------------------

//----------------------------------------------------------------------------
//------- FUNCIONES RESERVADAS PARA VIDEO ------------------------------------
//----------------------------------------------------------------------------
void gotoxy(int x, int y){
        HANDLE hCon;
        hCon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X=x;
        dwPos.Y=y;
        SetConsoleCursorPosition(hCon,dwPos);
}

void setD() {
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hCon,GRIS_CLARO);
}

void setT(int texto) {
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hCon,texto);
}

void setTF(int texto, int fondo){
    HANDLE hCon;
    int numero;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    numero = fondo*16+texto;
	SetConsoleTextAttribute (hCon,numero);
}

void settitle (const char *texto){
    SetConsoleTitle(texto);
}



void paintF(int x, int y, int *figura,int limY,int limX,int color){

	int j=0;
	gotoxy(x,y);
	int a,b;
	for (a=0;a<limY;a++ ){
		gotoxy(x,y);
		y++;
		for (b=0;b<limX;b++){
			switch (figura[j]){

				case 0: printf (" ");  break;				//Vv Tuberias vV

				case 1: setT (color); printf ("ษ"); setD(); break; //sup-izq

				case 2: setT (color); printf ("อ"); setD(); break;//vert

				case 3: setT (color); printf ("ป"); setD(); break;//sup-der

				case 4: setT (color); printf ("บ"); setD(); break;//horiz

				case 5: setT (color); printf ("ศ"); setD(); break;//inf-izq

				case 6: setT (color); printf ("ผ"); setD(); break;//inf-der

				case 7: setT (color); printf ("อออออออออออออออ"); setD(); break;//vert x15

				case 8:  printf ("               "); break;//void x15
			}
			j++;
		}
	}
}

void paintU(int thing,int color){


			switch (thing){

				case 0: printf (" ");  break;								 //Vv Tuberias vV

				case 1: setT (color); printf ("ษ"); setD(); break; //sup-izq

				case 2: setT (color); printf ("อ"); setD(); break;//vert

				case 3: setT (color); printf ("ป"); setD(); break;//sup-der

				case 4: setT (color); printf ("บ"); setD(); break;//horiz

				case 5: setT (color); printf ("ศ"); setD(); break;//inf-izq

				case 6: setT (color); printf ("ผ"); setD(); break;//inf-der

				case 7: setT (color); printf ("อออออออออออออออ"); setD(); break;//vert x15

				case 8:  printf ("               "); break;//void x15
			}



}

void cuadro(const char *text,int x,int y){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,6,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,9);
	int j;
	for ( j=1;j<len;j++)	paintF (x+j,y,midS,3,1,9);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,9);


}

void cuadroT(const char *text,int x,int y,int ColorBorde){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,6,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);

}

void cuadroIT(const char *textFormat,int x,int y,int ColorBorde, int variable){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,6,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}


void cuadroFT(const char *textFormat,int x,int y,int ColorBorde, float variable){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,6,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroST(const char *textFormat,int x,int y,int ColorBorde, char * variable){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,6,};

	char text[70];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroTF(const char *text,int x,int y,int ColorBorde,int ColorTexto){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,6,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF (x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	setT(ColorTexto);
	printf ("%s",text);
	setD();
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroBTF(const char *text,int x,int y,int ColorBorde,int ColorTexto, int ColorFondo){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,6,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF (x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	setTF(ColorTexto, ColorFondo);
	printf ("%s",text);
	setD();
	paintF (x+len,y,bot,3,1,ColorBorde);


}


void itemsNum(int cantItems, int x, int y,int color){

	setT(color);
	int a;
	int inter=0;
	for (a=0;a<cantItems;a++){
		gotoxy(x,y+inter);
		printf ("ฎ%dฏ",a+1);
		inter+=4;
	}
	setD();
}

void paintearD (int unit){

	// numero: 34
	// color 3
	// intensidad / completo? 4

	int color = trunc(unit / 10);
	int intensidad = unit % 10;

	switch (intensidad){

				case 0: setD(); printf ("  "); setD(); break;

				case 3: setT(color); printf ("ฐฐ"); setD(); break;

				case 2: setT(color); printf ("ฑฑ"); setD(); break; // difuminado

				case 1: setT(color); printf ("ฒฒ"); setD(); break; //gris claro mas difuminado

				case 4: setT(color); printf ("ÛÛ"); setD(); break; //completo


			}
}

void cuadroTtop(const char *text,int x,int y,int ColorBorde){
	int top[3]={1,4,4};
	int midS[3]={2,0,0,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,4,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroTmid(const char *text,int x,int y,int ColorBorde){  //necesito armar un cuadro grande, uso una variacion de cuadro t para imprimir texto metido en el medio de un cuadro
	int top[3]={4,4,4};
	int midS[3]={0,0,0,};
	//int midL[3]={7,8,7,};
	int bot[3]={4,4,4,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroTbot(const char *text,int x,int y,int ColorBorde){
	int top[3]={4,4,5};
	int midS[3]={0,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={4,4,6,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}


void cuadroITtop(const char *textFormat,int x,int y,int ColorBorde, int variable){
	int top[3]={1,4,4};
	int midS[3]={2,0,0,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,4,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroITmid(const char *textFormat,int x,int y,int ColorBorde, int variable){
	int top[3]={4,4,4};
	int midS[3]={0,0,0,};
	//int midL[3]={7,8,7,};
	int bot[3]={4,4,4,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroITbot(const char *textFormat,int x,int y,int ColorBorde, int variable){
	int top[3]={4,4,5};
	int midS[3]={0,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={4,4,6,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}


void cuadroFTtop(const char *textFormat,int x,int y,int ColorBorde, float variable){
	int top[3]={1,4,4};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,4,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroFTmid(const char *textFormat,int x,int y,int ColorBorde, float variable){
	int top[3]={4,4,4};
	int midS[3]={0,0,0,};
	//int midL[3]={7,8,7,};
	int bot[3]={4,4,4,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroFTbot(const char *textFormat,int x,int y,int ColorBorde, float variable){
	int top[3]={4,4,5};
	int midS[3]={0,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={4,4,6,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

//Asi como tengo top mid y bot, necesito lati, hori y latd para hacer cuadros a lo ancho
void cuadroTlatd(const char *text,int x,int y,int ColorBorde){
	int top[3]={2,0,2};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,6,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);

}

void cuadroITlati(const char *textFormat,int x,int y,int ColorBorde, int variable){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={2,0,2,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroIThori(const char *textFormat,int x,int y,int ColorBorde, int variable){
	int top[3]={2,0,2};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={2,0,2,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroITlatd(const char *textFormat,int x,int y,int ColorBorde, int variable){
	int top[3]={2,0,2};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,6,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}


void cuadroSTlati(const char *textFormat,int x,int y,int ColorBorde, char * variable){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={2,0,2,};

	char text[70];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroSThori(const char *textFormat,int x,int y,int ColorBorde, char * variable){
	int top[3]={2,0,2};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={2,0,2,};

	char text[70];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroSTlatd(const char *textFormat,int x,int y,int ColorBorde, char * variable){
	int top[3]={2,0,2};
	int midS[3]={2,0,2,};
	//int midL[3]={7,8,7,};
	int bot[3]={3,4,6,};

	char text[70];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}


void cuadroST_gral(const char *textFormat,int x,int y,int ColorBorde, char * variable,int t1,int t2,int t3,int m1, int m2, int m3, int b1, int b2, int b3){
	int top[3]={t1,t2,t3};
	int midS[3]={m1,m2,m3,};
	//int midL[3]={7,8,7,};
	int bot[3]={b1,b2,b3,};

	char text[70];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroIT_gral(const char *textFormat,int x,int y,int ColorBorde, int variable,int t1,int t2,int t3,int m1, int m2, int m3, int b1, int b2, int b3){
	int top[3]={t1,t2,t3};
	int midS[3]={m1,m2,m3,};
	//int midL[3]={7,8,7,};
	int bot[3]={b1,b2,b3,};

	char text[50];

	sprintf(text,textFormat,variable);


	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);


}
//--------------------------------------------------------------------
