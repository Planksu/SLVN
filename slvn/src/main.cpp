#include "hashtable.h"

int main(int argc, char** argv)
{
	slvn_hashtable ht = slvn_hashtable(0.8f, 12);

	int i = 10;
	int second = 20;

	ht.insert(&i);
	ht.insert(&second);

	void* result = ht.find(ht.hash(&i));
	int* int_result = static_cast<int*>(result);

	printf("result: %i", *int_result);

	return 0;
}