#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 82000

//arbol v

//int cargar_diccionario(char * diccionario){
//	FILE *dicc;
//	dicc = fopen("dicc.txt","rt");
//	if(dicc) return 1;	
//	char c;
//	int palabra = 0;
//	int character = 0;
//	
//	while((c = fgetc(dicc)) != EOF && palabra < MAX){	
//		if(c == '\n'){
//			palabra++;
//			character = 0;
//		}
//		else{
//			diccionario[palabra][character] = c;
//			character++;		
//		}		
//	}
//	fclose(dicc);
//	return 0;
//}
//
//
//int buscar_palabra(char diccionario[][25], char palabra[]){
//	int i = 0;
//	while(strcmp(palabra,diccionario[i])!=0 && i < MAX) i++;
//	if(i != MAX) return 0;
//	else return 1;	
//}


//int main(){
//	char diccionario[MAX][25];
//	
//	int nada = cargar_diccionario(&diccionario);
//	
//	for(int i= 0; i<MAX;i++) printf("%s", diccionario[i]);
//
//	
//	
//	
//	
//}



int main(){

	FILE *dicc;
	dicc = fopen("dicc.txt","rt");

	char diccionario[MAX][20];
	char c;
	
	int palabra = 0;
	int character = 0;
	
	char consulta[100];	
	printf("%c",-62);
	
	while((c = fgetc(dicc)) != EOF){	
		if(c == '\n'){
			palabra++;
			//if(character > 22) printf("\n%d %d", character, palabra);
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
	printf("---------------------------------");
//	int num;
//	scanf("%d",&num);
//	printf("%s\n", diccionario[num]);
//	printf("\n1: %d | 2: %d | 3: %d | 4: %d", diccionario[num][0], diccionario[num][1], diccionario[num][2], diccionario[num][3]);
//	
	while(1){
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
		int num;
		scanf("%d",&num);
		printf("%s\n", diccionario[num]);
//		printf("\n1: %d | 2: %d | 3: %d | 4: %d", diccionario[num][0], diccionario[num][1], diccionario[num][2], diccionario[num][3]);
		i = 0;
		while(diccionario[num][i]!='\0'){
			printf("\n%d: %d", i ,diccionario[num][i]);
			i++;
		}
	}
	fclose(dicc);
	
}
