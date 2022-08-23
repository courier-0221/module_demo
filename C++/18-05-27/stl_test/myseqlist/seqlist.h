#pragma once

#define error(err) #err
#define STRUCT(type) typedef struct _tag_##type type;\
struct _tag_##type

template <typename T>
class seqlist
{
public:
	seqlist(int capacity);
	~seqlist();
	int transf();
	int len();
	int insert(T & _node, int pos);
	int del(int pos, T & _node);
	int get(int pos, T & _node);
private:
	int capacity;
	int length;
	T *node;	//Ä£ÄâÊı×é
};

