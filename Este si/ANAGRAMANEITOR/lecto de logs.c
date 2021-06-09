#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define LMAX 100
#define TDICC 80500
#define TPALABRA 24

#define FILE_LOG "log.dat"
#define FILE_DICC "dicc.txt"


struct log{
	int idJuego;
	char anagrama[TPALABRA];
	char nombreEscritor[TPALABRA];
	char nombreAdivinador[TPALABRA];
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
	int juegoActual = -999;
	fread(&l, sizeof(struct log), 1, f);
	while (!feof(f))
	{ 
		//printf("Vuelta: %d\n", i);
		//printf("%d: %s, %d, %d, %d\n\n",log_partida.idJuego, log_partida.anagrama, log_partida.intentos, log_partida.ganador, log_partida.jugador_empieza);
		cantidadPartidas++;
		
		cantidadIntentosTotal+= l.intentos;
		
		jugadorGanador+= l.ganador;
		
		if(l.idJuego > cantidadJuegos){
			cantidadJuegos = l.idJuego;
			jugadorEmpieza+= l.jugador_empieza;
		}
		
		fread(&l, sizeof(struct log), 1, f);
	}
	
	printf("Intentos: %d | Partidas: %d | Juegos: %d | Ganador Escribe: %d | Ganador Adivina: %d | Empieza J1: %d", cantidadIntentosTotal, cantidadPartidas, cantidadJuegos, cantidadPartidas - jugadorGanador , jugadorGanador, cantidadJuegos - jugadorEmpieza);
	
	
	printf("Estadisticas:\n");
	printf("Juegos totales: %d\n", cantidadJuegos);
	printf("Partidas totales: %d\n", cantidadPartidas);
	printf("Partidas por juego: %f\n",(float) cantidadPartidas / cantidadJuegos );
	printf("Promedio intento por partida: %f\n",(float) cantidadIntentosTotal / cantidadPartidas);
	printf("Porcentaje de veces que inicio el Jugador 1: %f\n",(float) (cantidadJuegos - jugadorEmpieza) * 100 / cantidadJuegos);
	printf("Porcentaje de veces que inicio el Jugador 2: %f\n",(float) jugadorEmpieza * 100 / cantidadJuegos);
	printf("Porcentaje de veces que gano el Escritor: %f\n",(float) (cantidadPartidas - jugadorGanador) * 100 / cantidadPartidas);
	printf("Porcentaje de veces que gano el Adivinador: %f\n",(float)  jugadorGanador * 100 / cantidadPartidas);

	
	
}

void hacerGrafico(int ram, float valor){
	ram = ram/2;
	int cont = 0, rest = 0;
	while (cont<ram) {
		printf ("²");
		cont++;
	}
	rest=50-ram;
	cont=0;
	while (cont<rest) {	
	printf ("°");
    cont++;
	}
	printf ("] = %f%%\n",valor);
}

//-----------MAIN----------------------

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
	
	printf("\n\n\n| ID |    ANAGRAMA    | INTENTOS | WAdi | JEmpieza");
	fread(&log_partida, sizeof(struct log), 1, f);
	while (!feof(f))
	{ 
//		printf("NOMRBE: %s", log_partida.nombreEscritor);
		printf("\n| %2d |%13s   | %8d | %4d | %d",log_partida.idJuego, log_partida.anagrama, log_partida.intentos, log_partida.ganador, log_partida.jugador_empieza);
		i++;
		fread(&log_partida, sizeof(struct log), 1, f);
	}

	fclose(f);
	
	
	
	
	
	
}




