#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LMAX 100
#define TDICC 81000
#define TPALABRA 25

int continuar(int partidas);
int reintentarMenu(int intentos);
int reintentar_menu(int intentos);
int es_anagrama(char cad1[], char cad2[]);
void game_over(char nombrej1[],int puntosj1,char nombrej2[],int puntosj2,int partidas);
int es_texto(char cad[]);
void partida(char nombrej1[],int *puntosj1,char nombrej2[], int *puntosj2,char diccionario[][TPALABRA]);
void ingresar_nombre(char palabra[]);
void ingresar_palabra(char palabra[], char diccionario[][TPALABRA]);
int cargar_diccionario(char diccionario[][TPALABRA]);
int buscar_palabra(char diccionario[][TPALABRA], char palabra[]);


int main()
{
    int partidas=0;
    int puntosj1=0,puntosj2=0;
    char nombrej1[LMAX],nombrej2[LMAX];
    
	char diccionario[TDICC][TPALABRA];
	
    if(cargar_diccionario(diccionario)) return 0; 

    printf("Jugador 1 ingrese su nombre: ");
    ingresar_nombre(nombrej1);
    printf("\n\nJugador 2 ingrese su nombre: ");
    ingresar_nombre(nombrej2);

    srand(time(NULL));
    int moneda=rand()%2;

    do{ //partida
        partidas++;
        if(partidas%2==moneda)partida(nombrej1,&puntosj1,nombrej2,&puntosj2,diccionario);
        else partida(nombrej2,&puntosj2,nombrej1,&puntosj1,diccionario);
        printf("Puntos %s: %i\n\nPuntos %s: %i",nombrej1,puntosj1,nombrej2,puntosj2);
    }while(continuar(partidas)==1);
    game_over(nombrej1,puntosj1,nombrej2,puntosj2,partidas);
}

int continuar(int partidas){
	if(partidas >= 5) return 0;
	int respuesta;
	printf("\nDesea jugar otra partida?");
	printf("\n1. Si");
	printf("\n2. No");
	printf("\nRespuesta: ");
	fflush(stdin); // tuve que googlearlo para que ande
	scanf("%d",&respuesta);
	return respuesta;
}

int reintentar_menu(int intentos){
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

void ingresar_nombre(char palabra[])
{
	fflush(stdin);
    gets(palabra);
    while (es_texto(palabra)!=0)
    {
        printf("ERROR\nIngrese una palabra usando solo letras: ");
        fflush(stdin);
        gets(palabra);
    }

}

void ingresar_palabra(char palabra[], char diccionario[][TPALABRA])
{
    fflush(stdin);
    gets(palabra);
    while (buscar_palabra(diccionario,palabra)!=0)
    {
        printf("ERROR\nIngrese una palabra valida: ");
        fflush(stdin);
        gets(palabra);
    }

}

int cargar_diccionario(char diccionario[][TPALABRA]){
    FILE *dicc;
    dicc = fopen("dicc.txt","rt");
    if(!dicc) return 1;
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
    printf("Diccionario dentro: %s", diccionario[1]);
    return 0;
}

int buscar_palabra(char dicci[][TPALABRA], char palabra[]){
   
    //---------------------------------------------------
//    FILE *dicc;
//    dicc = fopen("dicc.txt","rt");
//    char diccionario[TDICC][TPALABRA];
//    char c;
//    int palab = 0;
//    int character = 0;
//
//    while((c = fgetc(dicc)) != EOF && palab < TDICC){
//        if(c == '\n'){
//            palab++;
//            character = 0;
//        }
//        else{
//            diccionario[palab][character] = c;
//            character++;
//        }
//    }
//    fclose(dicc);
    //---------------------------------------------------
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

void partida(char nombrej1[],int *puntosj1,char nombrej2[], int *puntosj2,char diccionario[][TPALABRA])
{

    int intentos=0;
    int reintentar=1;
    char palabraj1[LMAX],palabraj2[LMAX];
    printf("%s ingrese una palabra: ",nombrej1);
    ingresar_palabra(palabraj1,diccionario);

    do{//intentos
        intentos++;
        printf("%s ingrese una palabra: ",nombrej2);
        ingresar_palabra(palabraj2,diccionario);
        if (strcmp(palabraj1,palabraj2)==0)reintentar=reintentar_menu(intentos);
        else {
            if (es_anagrama(palabraj1,palabraj2)==0){
                intentos=5;
                break;
            }
            else {
                reintentar=reintentar_menu(intentos);
            }
        }



    }while(reintentar==1);
    if (intentos<5) *puntosj1=*puntosj1+1;
    else *puntosj2=*puntosj2+1;

}

