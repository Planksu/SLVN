#include "hashtable.h"


slvn_hashtable::slvn_hashtable(float fr, int initial_len)
{
	fillratio = fr;
	alloc_len = initial_len;
	used_len = 0;
	printf("Using the pointer type hashtable format.\n");
	data = { NULL };
	allocate_mem();
}

void* slvn_hashtable::find(void* insert_data, char* data_identifier)
{
	uint32_t hashed_index = hash(insert_data, data_identifier);
	slvn_hashtable_node* node = static_cast<slvn_hashtable_node*>(data[hashed_index]);
	return node->data;
}

void slvn_hashtable::insert(void* insert_data, char* data_identifier)
{
	// get the hashed index
	// insert to hashed index location in data
	uint32_t hashed_index = hash(insert_data, data_identifier);
	if (hashed_index > alloc_len)
	{
		alloc_len += (hashed_index - alloc_len);
		allocate_mem();
	}
	slvn_hashtable_node* node = new slvn_hashtable_node(insert_data, NULL);
	data[hashed_index] = node;
	used_len++;
}

void slvn_hashtable::allocate_mem()
{
	if (data == NULL)
	{
		data = static_cast<slvn_hashtable_node**>(malloc(sizeof(slvn_hashtable_node*) * alloc_len));
	}
	else
	{
		realloc(data, sizeof(slvn_hashtable_node*) * alloc_len);
	}
}

void slvn_hashtable::update_fillratio()
{
	while ((sizeof(data)) / (sizeof(slvn_hashtable_node*)) > fillratio)
	{
		alloc_len++;
	}
	this->slvn_hashtable::template allocate_mem();
}

uint32_t slvn_hashtable::hash(void* data, char* data_identifier)
{
	// no need for anything too complicated, going for efficiency before security
	//return (sizeof(T) * 7) % 12;
	uint32_t hashed_value = 0;
	for (int i = 0; data_identifier[i] != '\0'; i++)
	{
		hashed_value += (int)data_identifier[i];
	}

	hashed_value *= sizeof(data);

	printf("This hash produced a value of: %i\n", hashed_value);

	return hashed_value;
}