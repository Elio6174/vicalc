#include <stdio.h>
#include <stdint.h>

typedef uint32_t u32;
void heap_sort(u32 A[], unsigned length);

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

static void
heapify_subtree(u32 A[], unsigned length, unsigned subtree_idx)
{
	unsigned parent_idx;
	unsigned child_idx;
	u32 v;

	v = A[subtree_idx];
	parent_idx = subtree_idx;
	while ((child_idx = parent_idx * 2) <= length) {
		if (child_idx < length && A[child_idx + 1] > A[child_idx])
			child_idx++;
		if (v >= A[child_idx])
			break;
		A[parent_idx] = A[child_idx];
		parent_idx = child_idx;
	}
	A[parent_idx] = v;
}

static void
heapify_array(u32 A[], unsigned length)
{
	unsigned subtree_idx;

	for (subtree_idx = length / 2; subtree_idx >= 1; subtree_idx--)
		heapify_subtree(A, length, subtree_idx);
}


void heap_sort(u32 A[], unsigned length){

	A--; /* Use 1-based indices  */

	heapify_array(A, length);

	while (length >= 2) {
		u32 tmp = A[length];

		A[length] = A[1];
		A[1] = tmp;
		length--;
		heapify_subtree(A, length, 1);
	}
}
