#pragma once
#include <iostream>
using namespace std;
template <class T> class Node
{
public:
	Node(T inf);

	T info;
	Node *next;
	Node *pred;
};

template <class T>
Node<T>::Node(T inf) {
	info = inf;
	next = NULL;
	pred = NULL;
}

