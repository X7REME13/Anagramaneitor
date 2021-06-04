#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FILE_LOG "log.dat"
#define FILE_DICC "dicc.txt"

struct log{
		int idJuego;
		char anagrama[24];
		int intentos;
		int ganador;
		int jugador_empieza;
	} log_partida;


int setearIdJuego(){
	struct log log_partida;
	FILE* f = fopen("log.dat","rb");
	fseek(f, sizeof(struct log) * -1, 2);
	fread(&log_partida, sizeof(struct log), 1, f);
	fclose(f);
	printf("%d: %s, %d, %d, %d\n\n",log_partida.idJuego, log_partida.anagrama, log_partida.intentos, log_partida.ganador, log_partida.jugador_empieza);
	return log_partida.idJuego + 1;	
	
}

void mostrarEstadicticas(){
	FILE* f = fopen(FILE_LOG,"rb");
	struct log l;
	int cantidadPartidas = 0;
	int cantidadJuegos = 0;
	int cantidadIntentosTotal = 0;
	int jugadorGanador = 0;
	int jugadorEmpieza = 0;
	fread(&l, sizeof(struct log), 1, f);
	while (!feof(f))
	{ 
		//printf("Vuelta: %d\n", i);
		//printf("%d: %s, %d, %d, %d\n\n",log_partida.idJuego, log_partida.anagrama, log_partida.intentos, log_partida.ganador, log_partida.jugador_empieza);
		cantidadPartidas++;
		
		if(l.idJuego > cantidadJuegos) cantidadJuegos = l.idJuego;
		
		cantidadIntentosTotal+= l.intentos;
		
		jugadorGanador+= l.ganador;
		
		jugadorEmpieza+= l.jugador_empieza;
		
		fread(&l, sizeof(struct log), 1, f);
	}
	
	printf("Intentos: %d | Partidas: %d | Juegos: %d | Ganador J1: %d | Ganador J2: %d | empieza: %d", cantidadIntentosTotal, cantidadPartidas, cantidadJuegos, cantidadPartidas - jugadorGanador , jugadorGanador, jugadorEmpieza);
	
}

int main(){
	
	
	mostrarEstadicticas();
	
	char anagrama[24];
	int intentos;
	int ganador;
	int jugador_empieza;
	
	//struct log arrayLog[1000];
	
	//printf("%d\n\n", setearIdJuego());
	
	FILE* f = fopen("log.dat","rb");
	
	int i = 0;
	
	printf("\n\n\n| ID |    ANAGRAMA    | INTENTOS | WJ2 | JEmpieza");
	fread(&log_partida, sizeof(struct log), 1, f);
	while (!feof(f))
	{ 

		printf("\n| %2d |%13s   | %8d | %4d| %d",log_partida.idJuego, log_partida.anagrama, log_partida.intentos, log_partida.ganador, log_partida.jugador_empieza);
		i++;
		fread(&log_partida, sizeof(struct log), 1, f);
	}

	fclose(f);
	
	
	
	
	
	
}




