#include "hashtable.h"

#define GET_VAR_NAME(Variable) (#Variable)

int main(int argc, char** argv)
{
	slvn_hashtable ht = slvn_hashtable(0.8f, 12);

	//int i = 10;
	int second = 3521;

	//ht.insert(&i, GET_VAR_NAME(i));
	ht.insert(&second, GET_VAR_NAME(second));

	for (size_t i = 0; i < 1000; i++)
	{
		ht.insert(&i, GET_VAR_NAME(i));
	}

	int result = *(static_cast<int*>(ht.find(&second, GET_VAR_NAME(second))));
	//int* int_result = static_cast<int*>(result);

	printf("result: %i", result);

	return 0;
}