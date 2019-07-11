#ifndef SLVN_HASHTABLE_H
#define SLVN_HASHTABLE_H

#include <cstdint>
#include <cstdlib>
#include <string>

#include "hashtable_node.h"

#define GET_VAR_NAME(Variable) (#Variable)

class slvn_hashtable
{
private:
	float fillratio;
	int alloc_len;
	int used_len;
	slvn_hashtable_node** data;

public:
	slvn_hashtable(float fr, int initial_len);
	void* find(uint32_t hashed_index);
	void insert(void* data);
	uint32_t hash(void* insert_data);


private:
	void allocate_mem();
	void update_fillratio();

};

#endif
