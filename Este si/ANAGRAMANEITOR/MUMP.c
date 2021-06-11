//--------------------------------INICIO DE LIBRERIA VIDEO----------------------

#include <windows.h>
#include <stdio.h>
#include <math.h>

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

//--------------------------------FIN DE LIBRERIA VIDEO----------------------


void paintU(int thing,int color){

	switch (thing){

		case 0: printf (" ");  break;						// Caracteres de Tuberias 

		case 1: setTexto (color); printf ("ษ"); setDefault(); break; //sup-izq

		case 2: setTexto (color); printf ("อ"); setDefault(); break;//horiz

		case 3: setTexto (color); printf ("ป"); setDefault(); break;//sup-der

		case 4: setTexto (color); printf ("บ"); setDefault(); break;//vert

		case 5: setTexto (color); printf ("ศ"); setDefault(); break;//inf-izq

		case 6: setTexto (color); printf ("ผ"); setDefault(); break;//inf-der

		case 7: setTexto (color); printf ("อออออออออออออออ"); setDefault(); break;//vert x15

		case 8:  printf ("               "); break;//void x15
	}

}

void paintF(int x, int y, int *figura,int limY,int limX,int color){

	int pos=0;
	gotoxy(x,y);
	int a,b;
	for (a=0;a<limY;a++ ){
		gotoxy(x,y);
		y++;
		for (b=0;b<limX;b++){
			paintU(figura[pos], color);
			pos++;
		}
	}
}

void cuadro(const char *text,int x,int y){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	int bot[3]={3,4,6,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,9);
	int j;
	for (j=1;j<len;j++)	paintF (x+j,y,midS,3,1,9);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,9);

}

void cuadroBorde(const char *text,int x,int y,int ColorBorde){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	int bot[3]={3,4,6,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);

}

void cuadroBordeInt(const char *textFormat,int x,int y,int ColorBorde, int variable){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
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

void cuadroBordeFloat(const char *textFormat,int x,int y,int ColorBorde, float variable){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
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

void cuadroBordeString(const char *textFormat,int x,int y,int ColorBorde, char * variable){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
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

void cuadroBordeTexto(const char *text,int x,int y,int ColorBorde,int ColorTexto){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};
	int bot[3]={3,4,6,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF (x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	setTexto(ColorTexto);
	printf ("%s",text);
	setDefault();
	paintF (x+len,y,bot,3,1,ColorBorde);

}

void cuadroBordeTextoFondo(const char *text,int x,int y,int ColorBorde,int ColorTexto, int ColorFondo){
	int top[3]={1,4,5};
	int midS[3]={2,0,2,};

	int bot[3]={3,4,6,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF (x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	setTextoFondo(ColorTexto, ColorFondo);
	printf ("%s",text);
	setDefault();
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void itemsNum(int cantItems, int x, int y,int color){
	setTexto(color);
	int a;
	int inter=0;
	for (a=0;a<cantItems;a++){
		gotoxy(x,y+inter);
		printf ("ฎ%dฏ",a+1);
		inter+=4;
	}
	setDefault();
}

void paintearD (int unit){

	// numero: 34
	// color -> 3 
	// caracter -> 4

	int color = trunc(unit / 10);
	int intensidad = unit % 10;

	switch (intensidad){

				case 0: setDefault(); printf ("  "); setDefault(); break;

				case 3: setTexto(color); printf ("ฐฐ"); setDefault(); break;

				case 2: setTexto(color); printf ("ฑฑ"); setDefault(); break; // difuminado

				case 1: setTexto(color); printf ("ฒฒ"); setDefault(); break; //mas difuminado

				case 4: setTexto(color); printf ("ÛÛ"); setDefault(); break; //completo

			}
}

//void paintearD (int unit){
//
//	// numero: 34
//	// color -> 3 
//	// caracter -> 4
//
//	int color = trunc(unit / 10);
//	int intensidad = unit % 10;
//
//	switch (intensidad){
//
//				case 0: setDefault(); printf ("  "); setDefault(); break;
//
//				case 1: setTexto(color); printf ("ฐฐ"); setDefault(); break;
//
//				case 2: setTexto(color); printf ("ฑฑ"); setDefault(); break; // difuminado
//
//				case 3: setTexto(color); printf ("ฒฒ"); setDefault(); break; //mas difuminado
//
//				case 4: setTexto(color); printf ("ÛÛ"); setDefault(); break; //completo
//
//			}
//}


void cuadroBordeUniversal(const char *text,int x,int y,int ColorBorde,int t1,int t2,int t3,int m1,int m2,int m3,int b1,int b2,int b3){
	int top[3]={t1,t2,t3};
	int midS[3]={m1,m2,m3,};
	int bot[3]={b1,b2,b3,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF(x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	printf ("%s",text);
	paintF (x+len,y,bot,3,1,ColorBorde);

}

void cuadroBordeTextoUniversal(const char *text,int x,int y,int ColorBorde,int ColorTexto,int t1,int t2,int t3,int m1, int m2,int m3,int b1,int b2, int b3){
	int top[3]={t1,t2,t3};
	int midS[3]={m1,m2,m3,};
	int bot[3]={b1,b2,b3,};

	int len=strlen(text) + 1;

	paintF (x,y,top,3,1,ColorBorde);
	int j;
	for (j=1;j<len;j++)	paintF (x+j,y,midS,3,1,ColorBorde);
	gotoxy(x+1,y+1);
	setTexto(ColorTexto);
	printf ("%s",text);
	setDefault();
	paintF (x+len,y,bot,3,1,ColorBorde);


}

void cuadroBordeStringUniversal(const char *textFormat,int x,int y,int ColorBorde, char * variable,int t1,int t2,int t3,int m1, int m2, int m3, int b1, int b2, int b3){
	int top[3]={t1,t2,t3};
	int midS[3]={m1,m2,m3,};
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

void cuadroBordeIntUniversal(const char *textFormat,int x,int y,int ColorBorde, int variable,int t1,int t2,int t3,int m1, int m2, int m3, int b1, int b2, int b3){
	int top[3]={t1,t2,t3};
	int midS[3]={m1,m2,m3,};
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

void cuadroBordeFloatUniversal(const char *textFormat,int x,int y,int ColorBorde, float variable,int t1,int t2,int t3,int m1, int m2, int m3, int b1, int b2, int b3){
	int top[3]={t1,t2,t3};
	int midS[3]={m1,m2,m3,};
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

int relocate_x(int largo_acompanamiento, int largo_variable, int espaciado,int hudX)  //espaciado es si quiero que el cuadro quede pegado o separado
{
   int dist_x=largo_acompanamiento+largo_variable+espaciado;
   return hudX+dist_x;
}

void borrar(int inix, int iniy, int endx, int endy){
	int x, y;
	setDefault();
	for(y = iniy; y < endy; y++){
		for(x = inix; x < endx; x++){
			gotoxy(x,y);
			printf(" ");
		}
	}
}
