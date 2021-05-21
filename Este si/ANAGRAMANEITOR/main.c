#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LMAX 100


int continuar(int partidas);
int reintentarMenu(int intentos);
void ingresar_palabra(char palabra[]);
int reintentar_menu(int intentos);
int es_anagrama(char cad1[], char cad2[]);
void game_over(int puntosj1,int puntosj2,int partidas);
int es_palabra(char cad[]);

int main()
{
    int partidas=0;
    int puntosj1=0,puntosj2=0;
    do{ //partida
        partidas++;
        int intentos=0;
        int reintentar=1;
        char palabraj1[LMAX],palabraj2[LMAX];
        printf("J1 ingrese una palabra: ");
        ingresar_palabra(palabraj1);

        do{//intentos
            intentos++;
            printf("J2 ingrese una palabra: ");
            ingresar_palabra(palabraj2);
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
        if (intentos<5) puntosj1++;
        else puntosj2++;
        printf("Punt j1: %i\nPunt j2: %i",puntosj1,puntosj2);

    }while(continuar(partidas)==1);
    game_over(puntosj1,puntosj2,partidas);
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

void ingresar_palabra(char palabra[])
{
    fflush(stdin);
    gets(palabra);
    while (es_palabra(palabra)!=0)
    {
        printf("ERROR\nIngrese una palabra usando solo letras: ");
        fflush(stdin);
        gets(palabra);
    }

}

int es_palabra(char cad[])
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

void game_over(int puntosj1,int puntosj2,int partidas)
{
    printf("\nFIN DEL JUEGO");
    printf("\nJugaron %d partidas", partidas);
    printf("\nPuntos finales: ");
    printf("\nJugador 1: %d", puntosj1);
    printf("\nJugador 2: %d", puntosj2);

    if(puntosj1 > puntosj2) printf("\n\n>> GANO EL JUGADOR 1");
    else{
        if(puntosj1 == puntosj2) printf("\n\n>> Empate! Ambos ganan");
        else printf("\n\n>> GANO EL JUGADOR 2");
    }
}
