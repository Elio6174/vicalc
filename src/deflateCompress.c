#include <deflateCompress.h>
#include <stdio.h>

void
deflateCompression(const char *cadena){
	u32 freqs[256]; 
	u8 lens[256] = {0};
    u32 symout[256] = {0};

    memset(freqs, 0, sizeof(freqs));
    contar_frecuencias(cadena, freqs);


	printf("--- Conteo de Frecuencias ---\n");
    for (int i = 0; i < 256; i++) {
        // Solo imprimimos los caracteres que aparecieron al menos una vez
        if (freqs[i] > 0) {
            // %c imprime el carácter (ej. 'a')
            // %u imprime la cantidad (frecuencia)
            printf("Carácter [%c] (ASCII %d): %u veces\n", (char)i, i, freqs[i]);
        }
    }
    printf("-----------------------------\n");


	unsigned num_usados = sort_symbols(256, freqs, lens, symout);

	printf("num_usados: %d\n", num_usados);


	if (num_usados > 1) {
        build_tree(symout, num_usados);
		printf("\n--- Estructura del Árbol de Huffman ---\n");
        // El último nodo creado en build_tree es la raíz
        //imprimirArbol(symout, num_usados - 2, 0);
    }
}


void 
contar_frecuencias(const char *cadena, u32 freqs[]) {
    memset(freqs, 0, sizeof(u32) * 256); 
    
    while (*cadena) {
        freqs[(unsigned char)*cadena]++;
        cadena++;
    }
}

void
heapify_subtree(u32 A[], unsigned length, unsigned subtree_idx){
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

void
heapify_array(u32 A[], unsigned length){
	unsigned subtree_idx;

	for (subtree_idx = length / 2; subtree_idx >= 1; subtree_idx--)
		heapify_subtree(A, length, subtree_idx);
}


void 
heap_sort(u32 A[], unsigned length){
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

unsigned
sort_symbols(unsigned num_syms, const u32 freqs[], u8 lens[], u32 symout[])
{
	unsigned sym;
	unsigned i;
	unsigned num_used_syms;
	unsigned num_counters;
	unsigned counters[GET_NUM_COUNTERS(DEFLATE_MAX_NUM_SYMS)];

	num_counters = GET_NUM_COUNTERS(num_syms);
	memset(counters, 0, num_counters * sizeof(counters[0]));

	for (sym = 0; sym < num_syms; sym++)
		counters[MIN(freqs[sym], num_counters - 1)]++;

	num_used_syms = 0;
	for (i = 1; i < num_counters; i++) {
		unsigned count = counters[i];

		counters[i] = num_used_syms;
		num_used_syms += count;
	}

	for (sym = 0; sym < num_syms; sym++) {
		u32 freq = freqs[sym];

		if (freq != 0) {
			symout[counters[MIN(freq, num_counters - 1)]++] =
				sym | (freq << NUM_SYMBOL_BITS);
		} else {
			lens[sym] = 0;
		}
	}

	heap_sort(symout + counters[num_counters - 2],
		  counters[num_counters - 1] - counters[num_counters - 2]);

	return num_used_syms;
}


void
build_tree(u32 A[], unsigned sym_count)
{
	const unsigned last_idx = sym_count - 1;
	unsigned i = 0;
	unsigned b = 0;
	unsigned e = 0;

	do {
		u32 new_freq;
		if (i + 1 <= last_idx &&
		    (b == e || (A[i + 1] & FREQ_MASK) <= (A[b] & FREQ_MASK))) {
			new_freq = (A[i] & FREQ_MASK) + (A[i + 1] & FREQ_MASK);
			i += 2;
		} else if (b + 2 <= e &&
			   (i > last_idx ||
			    (A[b + 1] & FREQ_MASK) < (A[i] & FREQ_MASK))) {
			new_freq = (A[b] & FREQ_MASK) + (A[b + 1] & FREQ_MASK);
			A[b] = (e << NUM_SYMBOL_BITS) | (A[b] & SYMBOL_MASK);
			A[b + 1] = (e << NUM_SYMBOL_BITS) |
				   (A[b + 1] & SYMBOL_MASK);
			b += 2;
		} else {
			new_freq = (A[i] & FREQ_MASK) + (A[b] & FREQ_MASK);
			A[b] = (e << NUM_SYMBOL_BITS) | (A[b] & SYMBOL_MASK);
			i++;
			b++;
		}
		A[e] = new_freq | (A[e] & SYMBOL_MASK);
	} while (++e < last_idx);
}


void imprimirArbol(u32 A[], int nodo_idx, int nivel) {
    // Extraer la frecuencia y el dato del nodo actual
    u32 freq = A[nodo_idx] & FREQ_MASK;
    u32 info = A[nodo_idx] >> NUM_SYMBOL_BITS;

    // Sangría para ver la jerarquía
    for (int i = 0; i < nivel; i++) printf("  ");

    if (nodo_idx < info) { 
        // Es un nodo interno (Padre)
        printf("Node (Freq: %u)\n", freq);
        // En Huffman DEFLATE, los hijos suelen estar en posiciones calculadas
        // Nota: Esta parte depende de cómo manejes los índices en build_tree
        imprimirArbol(A, info, nivel + 1);      // Hijo derecho
        imprimirArbol(A, info + 1, nivel + 1);  // Hijo izquierdo
    } else {
        // Es una hoja (Carácter real)
        printf("Leaf: '%c' (Freq: %u)\n", (char)(A[nodo_idx] & SYMBOL_MASK), freq);
    }
}