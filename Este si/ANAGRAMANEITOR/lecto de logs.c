#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	struct log{
		int idJuego;
		char anagrama[24];
		int intentos;
		int ganador;
		int jugador_empieza;
	} log_partida;
	
	char anagrama[24];
	int intentos;
	int ganador;
	int jugador_empieza;
	
	//struct log arrayLog[1000];
	
	FILE* f = fopen("log.dat","rb");
	
	int i = 0;
	fread(&log_partida, sizeof(struct log), 1, f);
	while (!feof(f))
	{ 
		printf("Vuelta: %d\n", i);
		printf("%s, %d, %d, %d\n\n",log_partida.anagrama, log_partida.intentos, log_partida.ganador, log_partida.jugador_empieza);
		i++;
		fread(&log_partida, sizeof(struct log), 1, f);
	}

	fclose(f);
	
	
	
	
	
	
}




