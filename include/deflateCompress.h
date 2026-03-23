#ifndef DEFLATECOMPRESS_H
#define DEFLATECOMPRESS_H

#include <stdint.h>
#include <string.h>

#define DEFLATE_MAX_NUM_SYMS		288
#define NUM_SYMBOL_BITS             10
#define NUM_FREQ_BITS	(32 - NUM_SYMBOL_BITS)
#define SYMBOL_MASK	((1 << NUM_SYMBOL_BITS) - 1)
#define FREQ_MASK	(~SYMBOL_MASK)
#define GET_NUM_COUNTERS(num_syms)	(num_syms)

#define MIN(a, b)		((a) <= (b) ? (a) : (b))

typedef uint32_t u32;
typedef uint8_t u8;

void heapify_subtree(u32 A[], unsigned length, unsigned subtree_idx);
void heapify_array(u32 A[], unsigned length);
void heap_sort(u32 A[], unsigned length);
unsigned sort_symbols(unsigned num_syms, const u32 freqs[], u8 lens[], u32 symout[]);
void build_tree(u32 A[], unsigned sym_count);
void contar_frecuencias(const char *cadena, u32 freqs[]);
void deflateCompression(const char *cadena);
void imprimirArbol(u32 A[], int nodo_idx, int nivel);


#endif // DEFLATECOMPRESS_H