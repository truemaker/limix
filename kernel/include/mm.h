#pragma once
#include <limine.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct memseg {
  struct memseg *prev;
  struct memseg *next;
} memseg_t;

bool mm_init(struct limine_memmap_response *);

void *request_page();
void *request_page_block();

void free_page(void *);
void free_page_block(void *, uint64_t);
