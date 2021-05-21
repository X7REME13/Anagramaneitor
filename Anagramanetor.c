#include <stdio.h>
#define MAX 100

int reintentarMenu(int intentos);
int longitud(char st[MAX]);
int continuar(int partidas);
int es_anagrama(char palabra[MAX],char anagrama[MAX]);
void duplicar_cadena(char cad1[], char cad2[]);


int main(){
	int puntosJ1 = 0,puntosJ2 = 0;

	char palabra[MAX],anagrama[MAX];
	int lenPalabra;
	int i,j;
	int intentos,partidas = 0;
	int gano,reintentar;

	do{
		partidas++;
        printf("\n<<<<<<<<<<<<<<<<<<<<->>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n             PARTIDA NUMERO %d", partidas);
        printf("\n<<<<<<<<<<<<<<<<<<<<->>>>>>>>>>>>>>>>>>>>>>>>>>");

		printf("\n<< Jugador 1 -> ingrese la palabra: ");
		fflush(stdin); // tuve que googlearlo para que ande
		gets(palabra);
		lenPalabra = longitud(palabra);
		intentos = 0;
		reintentar = 1;
		gano = 0;
		do{
			intentos++;
            printf("\n----------------------------------------------");
			printf("\n          INTENTO NUMERO %d", intentos);
            printf("\n----------------------------------------------");
			printf("\n<< Jugador 2 -> ingrese el anagrama:");
			fflush(stdin); // tuve que googlearlo para que ande
			gets(anagrama);

			if(compararCadenas(palabra,anagrama)==0){
				reintentar = reintentarMenu(intentos);
			}
			else{			    
                if(es_anagrama(palabra,anagrama)==0){
                    printf("\n >> BIEN HECHO! Sumas un punto Jugador 2\n");
                    puntosJ2++;
                    reintentar  = 0;
                    intentos = 4;
                } else{
                    reintentar = reintentarMenu(intentos);
                }
			}
		}while(reintentar == 1);
	    if(intentos != 4 ){
	         printf("\n >> BIEN HECHO! Sumas un punto Jugador 1\n");
	         puntosJ1++;
	    }
	}while(continuar(partidas) == 1);

    printf("\nFIN DEL JUEGO");
    printf("\nJugaron %d", partidas);
    printf("\nPuntos finales: ");
    printf("\nJugador 1: %d", puntosJ1);
    printf("\nJugador 2: %d", puntosJ2);

    if(puntosJ1 > puntosJ2) printf("\n\n>> GANO EL JUGADOR 1");
    else{
        if(puntosJ1 == puntosJ2) printf("\n\n>> Empate! Ambos ganan");
        else printf("\n\n>> GANO EL JUGADOR 2");
    }

}

int es_anagrama(char palabra[MAX],char anagrama[MAX]){
	int encontre = 0;
	int i,j;
	int lenPalabra = longitud(palabra);
	char auxiliar[MAX];
	duplicar_cadena(anagrama,auxiliar);
	for(i = 0; i < lenPalabra; i++ ){
		for(j = 0; j < lenPalabra; j++){
			if(palabra[j] == auxiliar[i]){
				encontre++;
				auxiliar[i]='!';
				break;
			}
		}
	}
	if(encontre==lenPalabra){
		return 0;
	}else{
		return -1;	
	}	
}

void duplicar_cadena(char cad1[], char cad2[])
{
	
    int a=0, rdo=0;
    for (a;cad1[a]!='\0';a++)
    {
        cad2[a] = cad1[a];
    }
}

int longitud(char st[MAX]){
	int l=0, i=0;
	while(st[i]){
		i++;
		l++;
	}
	return l;
}

int reintentarMenu(int intentos){
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

int compararCadenas(char st1[MAX], char st2[MAX]){
	if(longitud(st1)!=longitud(st2)) return 0;
	int ind = 0;
	while (st1[ind]!='\0' && st2[ind]!='\0' && st2[ind] == st1[ind]) ind++;

	if (st1[ind]!='\0' || st2[ind]!='\0')  return -1;

	return 0;
}


