#include <deflateCompress.h>
#include <stdio.h>
#include <conio.h>

void imprimirBuffer(const char *buffer);

int main(int argc, char *argv[]){
	
	const char *BUFFER = "Este es un mensaje que espero que tenga mucha repeticion de letras en su interior";

	imprimirBuffer(BUFFER);
	deflateCompression(BUFFER);




	u32 arry[]= {5,2,1,6};

	for(int i = 0; i < 4; i++){
		printf("%d ", arry[i]);
	}
	printf("\n");

	heap_sort(arry, 4);

	
	for(int i = 0; i < 4; i++){
		printf("%d ", arry[i]);
	}
	printf("\n");



	int a = 4;
	printf("Variable a: %d || a << 1: %d\n", a, a<<1);
	/*
	if(argc > 1){
		FILE *archivo;
		printf("El parametro recividio es: %s\n", argv[1]);
		archivo = fopen(argv[1], "rb");

		if(archivo == NULL) 
			printf("error al abrir el archivo\n");

		int car;
		while((car = fgetc(archivo)) != EOF){
			printf("%c", car);
		}

		fclose(archivo);

	}*/


	char tecla;
	tecla = _getch();
	printf("la tecla: %d\n", tecla);

	return 0;
}

void imprimirBuffer(const char *buffer){
	printf("BUFFER: %s\n", buffer);
}
