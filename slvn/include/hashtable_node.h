#ifndef SLVN_HASHTABLE_NODE_H
#define SLVN_HASHTABLE_NODE_H

class slvn_hashtable_node
{
public:
	slvn_hashtable_node(void* d, slvn_hashtable_node* previous)
	{
		previous->next = this;
		data = data;
		next = NULL;
	}

	void* data;
	void* next;
};

#endif