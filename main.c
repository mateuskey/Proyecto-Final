#Integranates: Juan Manuel Benavente - Mateus Flores
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct {
	// Numero magico extraido desde el archivo.
	uint8_t magikNumber[4];
	// Ancho y alto de la matriz.
	uint32_t N;
	uint32_t M;
	// Cantidad de bacterias (poblacion)
	uint32_t cantidad;
	uint32_t bac;
} DescriptorBacterias;

int main(int argc, char *argv[]) {
	FILE *fr, *fw;
	int entero, entero_h;
	DescriptorBacterias db;
	int i = 0;
	int n = 0;
	////////////////////
	int aux = 0;

	fr = fopen("bacterias.bin", "rb");

	// Lee desde el archivo los datos y son almacenados en la estructra DescriptorBacterias
	// fread(Puntero_destino, Tamano_lectura, Cantidad_a_leer, Puntero_FILE)
	fread(&db, sizeof(DescriptorBacterias), 1, fr);

	// Imprimir las componentes del numero magico
	printf("Numero magico: " );
	for (i = 0; i < 4; i++){
		// La mascara %X imprime como numero hexadecimal
		// 02 define que se rellenara con ceros hasta que imprima 2 digitos
		//printf("%02X", db.magikNumber[i]);
		//printf("%i ", db.magikNumber[i]);
		if(db.magikNumber[i] != 0)
			aux += db.magikNumber[i];
	}
	printf("%i \n", aux);

	// Llamando las funciones para llenar la estructura con sus valores.
	db.N = obtener_decimal(4, 8, 0, db); // N
	db.M = obtener_decimal(8, 12, 0, db); // M
	db.cantidad = obtener_decimal(12, 16, 0, db); // cantidad
	db.bac= recorrido_x(16, 20, db);
	printf("%d",db.bac);
	// fclose(Puntero_FILE)
	fclose(fr);

	printf("\nn: %i\nm: %i\ncant: %i\n", db.N, db.M, db.cantidad);
	printf("\nbacteriias.bin: \n");
	
	int magic=num_magico();
	printf("%02X",magic);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Obtener las pociciones solicitadas del archivo binario y retornar su valor  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * parametros:																		 *
 * inicio: valor desde donde comienza a buscar.      								 *
 * final: valor hasta donde buscara. 											*
 * aux: guardara la transformacion del numero a travez del bucle.    			 *
 * db: la estructura que guarda los datos de la matriz.                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int obtener_decimal(int inicio, int final, int aux, DescriptorBacterias db){
	int i;
	for (i = inicio; i < final; i++){
		if(db.magikNumber[i] != 0)
			aux += db.magikNumber[i];
	}
	printf("%i\n", aux);
	return aux;
}
int recorrido_x(int inicio, int final, DescriptorBacterias db){
	int i;
	int fila=0;
	int colum=0;
	for (i = inicio; i < final; i++){
		fila=db.magikNumber[i]+fila;
	}

	for (i = 0; i < 4; i++){
		colum=db.magikNumber[i]+colum;
		printf("%02X",colum);
	}
	
	int matriz_aux[fila][colum];
	
	return (fila);
}
int totalmagico( ){
	FILE *fr;
	DescriptorBacterias db;
	int j;
	int magico[56];
	fr = fopen("bacterias (1).bin", "rb");
	fread(&db, sizeof(DescriptorBacterias), 1, fr);
	for (j = 0; j <56 ; j++){
		magico[j]=db.magikNumber[j];
		printf("%02X",magico[j]);
		printf(" ");
	}
	printf ("\n");
	fclose (fr);

	return magico[j];
}
int num_magico( ){
	// Imprimir las componentes del número mágico
	FILE *fr;
	DescriptorBacterias db;
	int j;
	int magico[56];
	fr = fopen("bacterias (1).bin", "rb");
	while(!feof(fr)){
		fread(&db, sizeof(DescriptorBacterias), 1, fr);
		for (j = 0; j < 16; j++){
		// La máscara %X imprime como número hexadecimal
		// 02 define que se rellenará con ceros hasta que imprima 2 digitos
			magico[j]=db.magikNumber[j];
			printf("%02X",db.magikNumber[j]);
			printf(" ");
		}printf("\n");
	}
	printf (" ");
	fclose (fr);
	//int equis = verificador (db);
	//printf ("%i",equis);
	//int M =verificador();
	//printf ("%i",M);
	return magico[j];
}
