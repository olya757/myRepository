#pragma once
#include "Node.h"

using namespace std;
template <class T> class Deque
{
private:
	Node<T> * Head;
	Node<T> * Tail;
	int cnt;
public:
	Deque();
	~Deque();
	bool IsEmpty();
	int Count();
	void PushBack(T info);
	void PushInFront(T info);
	T PopFromBack();
	T PopFromFront();
	T TopFromBack();
	T TopFromFront();
	void Print();
};



template <class T>
Deque<T>::Deque()
{
	cnt = 0;
}

template <class T>
Deque<T>::~Deque() {
	Node<T> * tmp1;
	while (Head != NULL) {
		tmp1 = Head;
		Head = Head->next;
		delete tmp1;
	}
}

template <class T>
bool Deque<T>::IsEmpty()
{
	return cnt == 0;
}

template <class T>
int Deque<T>::Count()
{
	return cnt;
}

template <class T>
void Deque<T>::PushBack(T info)
{
	if (cnt == 0) {
		Head = new Node<T>(info);
		Tail = Head;
		cnt++;
	}
	else
	{	
		Node<T> * el = new Node<T>(info);
		el->pred = Tail;
		Tail->next = el;
		Tail = el;
		cnt++;
	}
}

template <class T>
void Deque<T>::PushInFront(T info)
{
	if (cnt == 0) {
		Head = new Node<T>(info);
		Tail = Head;
		cnt++;
	}
	else {
		Node<T> * el = new Node<T>(info);
		el->next = Head;
		Head->pred = el;
		Head = el;
		cnt++;
	}
}

template <class T>
T Deque<T>::PopFromBack()
{
	try {
		if (cnt == 1) {
			cnt--; 
			T info = Head->info;
			delete Head;
			Tail = NULL; 
			return info;
		}
		else {
			T info;
			Node<T> *el = Tail;
			info = el->info;
			Tail = Tail->pred;
			Tail->next = NULL;
			delete el;
			cnt--;
			return info;
		}

	}
	catch (int) 
	{
		runtime_error("Очередь пуста");
		getchar();
		getchar();
	}
}

template <class T>
T Deque<T>::PopFromFront()
{
	try {
		if (cnt == 1) {
			cnt--;
			T info = Head->info;
			delete Head;
			Tail = NULL;
			return info;
		}
		else {
			T info;
			Node<T> *el = Head;
			info = el->info;
			Head = Head->next;
			Head->pred = NULL;
			delete el;
			cnt--;
			return info;
		}
	}
	catch (int) 
	{
		runtime_error("Очередь пуста");
		getchar();
		getchar();
	}
}

template <class T>
T Deque<T>::TopFromBack() {
	try {
		T info = Tail->info;
		return info;
	}
	catch (int)
	{
		runtime_error("Очередь пуста");
		getchar();
		getchar();
	}
}

template <class T>
T Deque<T>::TopFromFront() {
	try {
		T info = Head->info;
		return info;
	}
	catch (int)
	{
		runtime_error("Очередь пуста");
		getchar();
		getchar();
	}
}

template <class T>
void Deque<T>::Print() {
	Node<T> *tmp = Head;
	while (tmp != NULL) {
		cout << tmp->info << endl;
		tmp = tmp->next;
	}
}