#include "hashtable.h"

void allocate_mem(slvn_hashtable* ht)
{
	if (ht->data == NULL)
	{
		ht->data = malloc(sizeof(slvn_hashtable_node*) * ++ht->alloc_len);
	}
	else
	{
		realloc(ht->data, sizeof(slvn_hashtable_node*) * ++ht->alloc_len);
	}
}

uint32_t hash(slvn_hashtable* ht, void* insert_data)
{
	uint32_t hashed_value = 0;
	uint32_t memory_value = 0;
	uint32_t* variable_value = 0;
	variable_value = (uint32_t*)(insert_data);
	memory_value = (uint32_t)(*(&insert_data));

	uint32_t addition = 0;
	if (*variable_value % 2 == 0)
		addition = (*variable_value + 128) / 2;
	else
		addition = (*variable_value + 128) * 2;

	hashed_value = (((memory_value + *variable_value) - addition)) / (addition * sizeof(insert_data) + 1);

	printf("This hash resulted in value of: %i\n", hashed_value);

	return hashed_value;
}

void insert(slvn_hashtable* ht, void* insert_data)
{
	uint32_t hashed_index = hash(ht, insert_data);
	if (hashed_index > ht->alloc_len)
	{
		ht->alloc_len = hashed_index;
		allocate_mem(ht);
	}
	slvn_hashtable_node* node = malloc(sizeof(slvn_hashtable_node));
	node->data = insert_data;
	node->next = NULL;

	ht->data[hashed_index] = node;
	ht->used_len++;
}

void* find(slvn_hashtable* ht, void* insert_data)
{
	uint32_t hashed_index = hash(ht, insert_data);
	slvn_hashtable_node* node = (ht->data[hashed_index]);
	return node->data;
}
