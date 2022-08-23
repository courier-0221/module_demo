#include <stdio.h>
#include "seqlist.h"


template <typename T>
seqlist<T>::seqlist(int capacity)
{
	this->node = new T[capacity];
	this->capacity = capacity;
	this->length = 0;
}

template <typename T>
seqlist<T>::~seqlist()
{
	delete[] node;
	node = NULL;
	length = 0;
	capacity = 0;
}

template <typename T>
int seqlist<T>::transf()
{
	int i = 0;
	T tmp;
	for (i = 0; i < length; i++){
		seqlist<T>::get(i, tmp);
		cout << "student info: " << tmp.age << endl;
	}
	return 0;
}

template <typename T>
int seqlist<T>::len()
{
	return this->length;
}

template <typename T>
int seqlist<T>::insert(T & _node, int pos)
{
	if (capacity == length){
		printf("seqlist is full\n");
		return -1;
	}

	if (pos < 0){
		printf("An error in %s\n", error(insert));
		return -1;
	}

	//移动数据
	int i = 0;
	for (i = length; i > pos; i--){
		node[i] = node[i - 1];
	}
	node[pos] = _node;

	length++;
	return 1;
}

template <typename T>
int seqlist<T>::del(int pos, T &_node)
{
	if (pos < 0){
		printf("An error in %s\n", error(del));
		return -1;
	}
	_node = node[pos];
	//移动数据
	int i = 0;
	for (i = pos; i < length; i++){
		node[i] = node[i + 1];
	}

	length--;
	return 0;
}

template <typename T>
int seqlist<T>::get(int pos, T &_node)
{
	if (pos < 0){
		printf("An error in %s\n", error(get));
		return -1;
	}
	_node = node[pos];
	return 0;
}
