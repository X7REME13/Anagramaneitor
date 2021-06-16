#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TDICC 80500
#define TPALABRA 24
#define LMAX 24

int esAnagrama(char cad1[], char cad2[])
{
	
	
    int lcad=strlen(cad1);
    int rta=1; // la respuesta la inicialiamos como que no es anagrama
	

	if(strcmp(cad1, cad2)!=0){
		
	    if(lcad==strlen(cad2))// verificamos que el largo de las cadenas coincida
	    {	
	    	int i,j,cont=0;
	    	char cadAux[LMAX]; // duplicamos la cadena para poder modificarla 
	    	strcpy(cadAux,cad1);
	        for (i=0;i<lcad;i++)// iteramos sobre cad2
	        {
	            for(j=0;j<lcad;j++)// iteramos sobre cad1 (aux)
	            {
	                if(cad2[i]==cadAux[j]) //comparacion de cad1 (aux) contra cad2
	                {
	                    cadAux[j]='!'; // en caso de encontrar la letra se reemplaza por un "!"
	                    cont++; // se suma 1 al contador que nos servira luego para saber si es un anagrama
	                    break; // rompemos el bucle sobre cad1 (aux) y continuamos sobre la siguiente letra de cad2
	                }
	            }
	        }
	        if(lcad==cont) rta=0; // si el largo de la palabra coincide con la cantidad de veces 
			                     //que encontramos la letras, entonces es un anamgrama
	    }
	}
    return rta;
}


int main(){
	
	char diccionario[TDICC][TPALABRA];
	
	FILE *dicc;
	FILE *dicc_anagramas;
    dicc = fopen("diccionario_anagramas2.txt","rt");
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
    //printf("%s", diccionario[12345]);
    fclose(dicc);
    int palabra2;
    while(1){
	    scanf("%d",&palabra);
		printf("%s\n", diccionario[palabra]);
		for(palabra2 = 0;palabra2 < TDICC; palabra2++){
			if(esAnagrama(diccionario[palabra], diccionario[palabra2])==0){
				printf("%s\n", diccionario[palabra2]);
			}
		}		
	
	}
	
	
	

    dicc_anagramas = fopen("diccionario_anagrama123123s2.txt","wt");
	for(palabra = 0;palabra < TDICC; palabra++){
		printf("porcentaje: %f%% \r ", (float)palabra/TDICC * 100);
		for(palabra2 = 0;palabra2 < TDICC; palabra2++){
			//printf("%8d >> porcentaje: %f%% \r", palabra ,(float)palabra2/TDICC * 100);
			if(esAnagrama(diccionario[palabra], diccionario[palabra2])==0){
				//printf("    %s ", diccionario[palabra2]);
				fprintf(dicc_anagramas,"%s\n",diccionario[palabra]);
				//getch();
				break;
			}		
		}
	}
    
    fclose(dicc_anagramas);
    
	
	
	
	
	
}
