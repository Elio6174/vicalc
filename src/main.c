#include <deflateCompress.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	
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

	return 0;
}

