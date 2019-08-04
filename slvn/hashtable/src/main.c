#include "hashtable.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	slvn_hashtable ht = { 0 };
	ht.alloc_len = 10;
	ht.fillratio = 1.0f;
	ht.data = NULL;
	ht.used_len = 0;


	int first = 3500;
	insert(&ht, &first);

	size_t i;
	for (i = 0; i < 750; i++)
	{
		insert(&ht, &i);
	}

	int* result = (int*)find(&ht, &first);
	
	printf("The result is: %i", *result);

	return 0;
}