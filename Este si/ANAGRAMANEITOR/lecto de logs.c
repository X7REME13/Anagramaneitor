#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	struct Log{
		char anagrama[24];
		int intentos;
		int ganador;
		int jugador_empieza;
	} log_partida;
	
	char anagrama[24];
	int intentos;
	int ganador;
	int jugador_empieza;
	
	
	
	FILE* Archivaldo = fopen("log.dat","rb");

    fread(log_partida, sizeof(log_partida), 1, Archivaldo);
    fread(&intentos, sizeof(int), 1, Archivaldo);
    printf("%s",anagrama);
//    
//    Nuevo->Id_Doctor=id_doc; ///copies data in structure
//    strcpy(Nuevo -> Nombre , nombre_doc);
//    strcpy(Nuevo -> Clave_Acceso, password);
//    strcpy(Nuevo -> Especialidad, especialida);
//    Nuevo-> Estado = estado_doc;
//    printf("---------------------------------\n"); //display info
//    printf("ID: %d\n", id_doc);
//    printf("\nDoctor: ");
//    puts(nombre_doc);
//    printf("\nPassword: ");
//    puts(password);
//    printf("\nEspecialidad: ");
//    puts(especialida);
//    printf("\nEstado: ");
//    if(estado_doc==1)
//        puts("Activo\n");
//    else
//        puts("Inactivo\n");
//    Nuevo-> next = *Inicio;
//    *Inicio = Nuevo
//	
	fclose(Archivaldo);
	
	
	
	
	
	
}




