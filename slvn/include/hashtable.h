#ifndef SLVN_HASHTABLE_H
#define SLVN_HASHTABLE_H

#include <cstdint>
#include <cstdlib>
#include <string>

#include "hashtable_node.h"



class slvn_hashtable
{
private:
	float fillratio;
	int alloc_len;
	int used_len;
	slvn_hashtable_node** data;

public:
	slvn_hashtable(float fr, int initial_len);
	void* find(void* insert_data, char* data_identifier);
	void insert(void* insert_data, char* data_identifier);
	uint32_t hash(void* insert_data, char* data_identifier);


private:
	void allocate_mem();
	void update_fillratio();

};

#endif
