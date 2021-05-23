#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 82000

//arbol v

int cargar_diccionario(char diccionario[][]){
	FILE *dicc;
	dicc = fopen("dicc.txt","rt");
	if(dicc) return 1;	
	char c;
	int palabra = 0;
	int character = 0;
	
	while((c = fgetc(dicc)) != EOF && palabra < MAX){	
		if(c == '\n'){
			palabra++;
			character = 0;
		}
		else{
			diccionario[palabra][character] = c;
			character++;		
		}		
	}	
	return 0;
}


int buscar_palabra(char diccionario[][], char palabra[]){
	while(strcmp(consulta,diccionario[i])!=0 && i < MAX) i++;
	if(i != MAX) return 0;
	else return 1;	
}


int main(){
	FILE *dicc;
	dicc = fopen("dicc.txt","rt");

	char diccionario[MAX][20];
	char c;
	
	int palabra = 0;
	int character = 0;
	
	char consulta[100];
	
	while((c = fgetc(dicc)) != EOF){	
		if(c == '\n'){
			palabra++;
			character = 0;
		}
		else{
			diccionario[palabra][character] = c;
			character++;		
		}		
	}
	printf("---------------------------------");
	while(){
		printf("\n<< Ingrese una palabra a buscar: ");
		gets(consulta);
		int i = 0;
		while(strcmp(consulta,diccionario[i])!=0 && i < MAX) i++;
		
		if(i != MAX){
			printf(">> Lo encontre en: %d\n", i);
		}else{
			printf(">> No lo encontre");
		}
		printf("\n---------------------------------");		
	}
	fclose(dicc);
	
}
