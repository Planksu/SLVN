#ifndef SLVN_HASHTABLE_H
#define SLVN_HASHTABLE_H

#include <stdint.h>
#include <stdlib.h>

typedef struct
{
	void* data;
	void* next;
} slvn_hashtable_node;

typedef struct
{
	float fillratio;
	int alloc_len;
	int used_len;
	slvn_hashtable_node** data;

} slvn_hashtable;

void allocate_mem(slvn_hashtable* ht);
void insert(slvn_hashtable* ht, void* insert_data);
void* find(slvn_hashtable* ht, void* insert_data);
uint32_t hash(slvn_hashtable* ht, void* insert_data);


#endif
