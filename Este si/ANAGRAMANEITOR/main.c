#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>  

#define LMAX 100
#define TDICC 80500
#define TPALABRA 24

#include "VIDEO.cpp"

int continuar();
int reintentarMenu(int intentos);
int reintentar_menu(int intentos);
int es_anagrama(char cad1[], char cad2[]);
void game_over(char nombrej1[],int puntosj1,char nombrej2[],int puntosj2,int partidas);
int es_texto(char cad[]);
void partida(char nombrej1[],int *puntosj1,char nombrej2[], int *puntosj2,char diccionario[][TPALABRA], int jugador_empieza);
void ingresar_nombre(char palabra[]);
void ingresar_palabra(char palabra[], char diccionario[][TPALABRA]);
int cargar_diccionario(char diccionario[][TPALABRA]);
int buscar_palabra(char diccionario[][TPALABRA], char palabra[]);
void juego();
void imprimir_terminator(int x, int y);
void crear_log(char anagrama[], int intentos, int ganador, int jugador_empieza);


void paintearD (int unit){
	
	// numero: 34 
	// color 3
	// intensidad / completo? 4 
	
	int color = trunc(unit / 10);
	int intensidad = unit % 10;

	switch (intensidad){
				
				case 0: setD(); printf ("  "); setD(); break;
				
				case 3: setT(color); printf ("∞∞"); setD(); break;	

				case 2: setT(color); printf ("±±"); setD(); break; // difuminado	
							
				case 1: setT(color); printf ("≤≤"); setD(); break; //gris claro mas difuminado			
								
				case 4: setT(color); printf ("€€"); setD(); break; //completo	
				
				
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
		{73,73,73,72,0,0,0,0,0,72,72,72,0,0,0,0,0,72,73,73,73},
		{72,72,72,72,72,72,72,72,72,71,0,72,72,72,72,72,72,72,72,72,72},
		{0,0,0,72,72,72,72,72,72,71,0,72,72,72,72,72,72,72,0,0,0}	
	};
	int iniX = x;
	int iniY = y;
	
	for (y=0;y<30;y++ ){
		
		for (x=0;x<24;x++){
			
			if (x==0 && y>0) gotoxy(iniX,y+iniY);
			
			paintearD(terminator[y][x]);
			 
		}
	}
	
}

int main() // --------------------MAIN------------------------
{
	SetConsoleTitle("ANAGRAMANEITOR");
	do{
	}while(menu() != 99);
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
	switch(opcion)
	{
		case 1:
			juego();
			break;
		case 2:
			printf("Instrucciones");
			break;
		case 3:
			printf("Retomar partida");
			break;
		case 4:
			printf("Logs");
			break;
		case 5:
			printf("Creditos");
			break;			
		default:
			return 99;
		
	}
	return 0;
}

void juego()
{
	
	int partidas=0;
    int puntosj1=0,puntosj2=0;
    char nombrej1[LMAX]="Marchelox",nombrej2[LMAX] = "X7REME13";
    
	char diccionario[TDICC][TPALABRA];
	
    if(cargar_diccionario(diccionario)) return; 

//    printf("Jugador 1 ingrese su nombre: ");
//    ingresar_nombre(nombrej1);
//    printf("\n\nJugador 2 ingrese su nombre: ");
//    ingresar_nombre(nombrej2);

    srand(time(NULL));
    int moneda=rand()%2;

    do{ //partida
        partidas++;
        
        if(partidas%2==moneda) partida(nombrej1,&puntosj1,nombrej2,&puntosj2,diccionario, moneda);
        else partida(nombrej2,&puntosj2,nombrej1,&puntosj1,diccionario, moneda);
        
		printf("Puntos %s: %i\n\nPuntos %s: %i",nombrej1,puntosj1,nombrej2,puntosj2);
		
    }while(continuar()==1);
    game_over(nombrej1,puntosj1,nombrej2,puntosj2,partidas);
}

int cargar_diccionario(char diccionario[][TPALABRA])
{
    FILE *dicc;
    dicc = fopen("dicc.txt","rt");
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
        printf("ERROR\n´ Ingrese una palabra usando solo letras: ");
        fflush(stdin);
        gets(palabra);
    }

}

void partida(char nombrej1[],int *puntosj1,char nombrej2[], int *puntosj2,char diccionario[][TPALABRA], int jugador_empieza)
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
    	intentos = -1;
	} 
    
    crear_log(palabraj1,intentos,ganoj2, jugador_empieza);
    
}

struct log{
		char anagrama[TPALABRA];
		int intentos;
		int ganador;
		int jugador_empieza;
};

void crear_log(char anagrama[], int intentos, int ganador, int jugador_empieza)
{
	struct log log_partida;

	strcpy(log_partida.anagrama, anagrama);
	printf("\n\n ESTOY GUARDANDO EL ARCHIVO\n");
	log_partida.intentos = intentos;
	log_partida.ganador = ganador;
	log_partida.jugador_empieza = jugador_empieza;

	FILE* f = fopen("log.dat","ab");
	fwrite(&log_partida, sizeof(struct log), 1, f);	
	fclose(f);
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



