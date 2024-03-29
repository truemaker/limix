#pragma once

#include <stddef.h>
#include <stdint.h>

typedef struct heapseg {
  size_t size;
  struct heapseg *prev;
  struct heapseg *next;
  uint64_t used;
} heapseg_t;

void heap_init();

void *malloc(size_t);
void free(void *);
