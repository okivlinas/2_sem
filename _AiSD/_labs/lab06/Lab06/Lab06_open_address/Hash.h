#pragma once
#define HASHDEL (void*) -1
int HashFunction(int key, int size, int p);
int Next_hash(int key, int size, int p);

struct Object
{
	void** data;
	Object(int, int(*)(void*));
	int size;  int N;
	int(*getKey)(void*);
	bool insert(void*);
	int searchInd(int key);
	void* search(int key);
	void* deleteByKey(int key);
	bool deleteByValue(void*);
	void scan(void(*f)(void*));
};
static void* DEL = (void*)HASHDEL;
Object create(int size, int(*getkey)(void*));
#undef HASHDEL