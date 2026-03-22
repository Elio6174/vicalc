#ifndef DEFLATECOMPRESS_H
#define DEFLATECOMPRESS_H

#include <stdint.h>

typedef uint32_t u32;

void heapify_subtree(u32 A[], unsigned length, unsigned subtree_idx);
void heapify_array(u32 A[], unsigned length);
void heap_sort(u32 A[], unsigned length);

#endif // DEFLATECOMPRESS_H