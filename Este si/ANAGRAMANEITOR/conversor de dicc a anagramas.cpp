#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TDICC 107715
#define TPALABRA 24
#define LMAX 20

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
	                    cadAux[j]='*'; // en caso de encontrar la letra se reemplaza por un "!"
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

int indexador(int len){
	switch(len){
		case  1 : return 26;
		case 2 : return 120;
		case 3 : return 539;
		case 4 : return 2631;
		case 5 : return 8141;
		case 6 : return 18285;
		case 7 : return 32962;
		case 8 : return 50305;
		case 9 : return 67466;
		case 10 : return 81694;
		case 11 : return 92055;
		case 12 : return 98677;
		case 13 : return 102821;
		case 14 : return 105160;
		case 15 : return 106504;
		case 16 : return 107152;
		case 17 : return 107450;
		case 18 : return 107614;
		case 19 : return 107670;
		case 20 : return 107692;
		case 21 : return 107705;
		case 22 : return 107709;
		case 23 : return 107710;
		case 24 : return 107711;
		case 26 : return 107713;
		case 27 : return 107715;
		case 25 : return 107713;
		case 0 : return  0;
	}
	
}


int busquedaAnagramas(char palabraAnagrama[], int start, int end){

	int i;
	char palabraArch[30]="";
	FILE *dicc2 = fopen("dicc - copia.txt","rt");
	while(fgets(palabraArch,30,dicc2)){
		if(start < i < end){
			if(esAnagrama(palabraAnagrama, palabraArch)==0){
        		fclose(dicc2);
				return 0;
			}
		}
		i++;
    }
    fclose(dicc2);
    return 1;	
}



int main(){
	
	//char diccionario[50000][30];
	
	FILE *dicc;
	FILE *dicc_anagramas;
    dicc = fopen("dicc.txt","rt");
    //dicc = fopen("diccionario_anagramas2.txt","rt");
    char c;
    int palabra = 0;
    int character = 0;

//    while((c = fgetc(dicc)) != EOF && palabra < TDICC){
//        if(c == '\n'){
//            palabra++;
//            character = 0;
//        }
//        else{
//        	//if(character > 21) printf("\n%d", character);
//			if(c == '!'){
//				c = 164;
//			}
//			diccionario[palabra][character] = c;
//			character++;
//		}
//    }
    //printf("%s", diccionario[12345]);
    fclose(dicc);
    int palabra2;
//    while(1){
//	    scanf("%d",&palabra);
//		printf("%s\n", diccionario[palabra]);
//		for(palabra2 = 0;palabra2 < TDICC; palabra2++){
//			if(esAnagrama(diccionario[palabra], diccionario[palabra2])==0){
//				printf("%s\n", diccionario[palabra2]);
//			}
//		}		
//	
//	}
	
	
	
	dicc = fopen("dicc.txt","rt");
    dicc_anagramas = fopen("diccionario_anagrama_final.txt","wt");
//    
//	for(palabra = 0;palabra < TDICC; palabra++){
//		printf("porcentaje: %f%% \r ", (float)palabra/TDICC * 100);
//		for(palabra2 = 0;palabra2 < TDICC; palabra2++){
//			//printf("%8d >> porcentaje: %f%% \r", palabra ,(float)palabra2/TDICC * 100);
//			if(esAnagrama(diccionario[palabra], diccionario[palabra2])==0){
//				//printf("%s", diccionario[palabra2]);
//				fprintf(dicc_anagramas,"%s\n",diccionario[palabra]);
//				//getch();
//				break;
//			}
//					
//		}
//	}
	char palabraArch[30]="            ";
	int i = 0;
	int encuentros = 0;	
	while(fgets(palabraArch,30,dicc)){
		printf("Porcentaje: %f | encuentros: %d/%d\r",(float)i/TDICC * 100,encuentros, i);
		int len = strlen(palabraArch);
    	if(busquedaAnagramas(palabraArch, indexador(len),indexador(len+1))==0){
    		encuentros++;
    		fprintf(dicc_anagramas,"%s",palabraArch);
		}
		i++;
	}
	
	
	
	
	
//	while((c = fgetc(dicc)) != EOF && i < TDICC){
//		
//		printf("%d/%d\n",encuentros, i);
//		i++;
//        if(c == '\n'){
//        	printf("%s\n", palabraArch);
//        	if(busquedaAnagramas(palabraArch)==0){
//        		encuentros++;
//        		fprintf(dicc_anagramas,"%s\n",palabraArch);
//			}	        	
//            strcpy(palabraArch, "");
//            character = 0;
//        }
//        else{
//
//			if(c == '!'){
//				c = 164;
//			}
//			palabraArch[character] = c;
//			character++;
//		}
//	}	
//	
	
    fclose(dicc);
    fclose(dicc_anagramas);
    
	
	
	
	
	
}
