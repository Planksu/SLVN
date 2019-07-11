#ifndef SLVN_HASHTABLE_H
#define SLVN_HASHTABLE_H

#include <cstdint>
#include <cstdlib>
#include <string>

#include "hashtable_node.h"

#define GET_VAR_NAME(Variable) (#Variable)

template <typename T>
class slvn_hashtable
{
protected:
	// Between 0-1
	float fillratio;
	int allocated_length;
	int used_length;

	T* data;
public:
	slvn_hashtable<T>(float desired_fillratio, int initial_length)
	{
		fillratio = desired_fillratio;
		allocated_length = initial_length;
		printf("Using the non-pointer type hashtable format.\n");
		printf("WARNING: this data structure is meant for use mainly with pointer types of data. Please keep this in mind.\nThis error is showing because you've created a hashtable with regular class types as data.\n");
	}
};

template<typename T>
class slvn_hashtable<T*>
{
protected:
	// Between 0-1
	float fillratio;
	int alloc_len;
	int used_len;

	T** data;
public:
	slvn_hashtable<T*>(float desired_fillratio, int initial_length)
	{
		fillratio = desired_fillratio;
		alloc_len = initial_length;
		printf("Using the pointer type hashtable format.");
		allocate_mem();
	}

	T* find(uint32_t hashed_index);
	void insert(T* data);
	void allocate_mem();
	void update_fillratio();
	uint32_t hash(T* data);
};

template<typename T>
inline void slvn_hashtable<T*>::allocate_mem()
{
	if (data != NULL)
	{
		realloc(data, sizeof(T*) * alloc_len);
	}
	else
	{
		data = malloc(sizeof(T*) * alloc_len);
	}
}

template<typename T>
inline uint32_t slvn_hashtable<T*>::hash(T* data)
{
	// no need for anything too complicated, going for efficiency before security
	//return (sizeof(T) * 7) % 12;
	uint32_t hashed_value;
	for (char c : GET_VAR_NAME(T))
	{
		hashed_value += (int)c;
	}
	printf("This hash produced a value of: %i", hashed_value);

	return hashed_value % 13;
}

template<typename T>
inline void slvn_hashtable<T*>::update_fillratio()
{
	while ((data / (sizeof(T*)) > fillratio)
	{
		alloc_len++;
	}
	this->slvn_hashtable::template allocate_mem();
}

template<typename T>
inline void slvn_hashtable<T*>::insert(T* data)
{
	// get the hashed index
	// insert to hashed index location in data
	uint32_t hashed_index = this->slvn_hashtable::template hash(data);
	if (hashed_index > alloc_len)
	{
		alloc_len += (hashed_index - alloc_len);
		this->slvn_hashtable::template allocate_mem();
	}
	data[hashed_index] = 
}

template<typename T>
inline T* slvn_hashtable<T*>::find(uint32_t hashed_index)
{

}

#endif
