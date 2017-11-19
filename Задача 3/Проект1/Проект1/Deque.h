#pragma once
#include "Node.h"

using namespace std;
template <class T> class Deque
{
private:
	Node<T> * Head;
	Node<T> * Tall;
	int cnt;
public:
	Deque();
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
	Head = NULL;
	Tall = NULL;
	cnt = 0;
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
		Tall = Head;
		cnt++;
	}
	else
	{	
		Node<T> * el = new Node<T>(info);
		el->pred = Tall;
		Tall->next = el;
		Tall = el;
		cnt++;
	}
}

template <class T>
void Deque<T>::PushInFront(T info)
{
	if (cnt == 0) {
		Head = new Node<T>(info);
		Tall = Head;
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
	if (cnt!=0) {
		T info;
		Node *el = Tall;
		info = el->info;
		Tall = Tall->pred;
		delete el;
		cnt--;
		return info;

	}
	else
		_raise __EXCEPTIONS("Очередь пуста");
}

template <class T>
T Deque<T>::PopFromFront()
{
	if (cnt!=0) {
		T info;
		Node *el = Head;
		info = el->info;
		Head = Head->next;
		delete el;
		cnt--;
		return info;
	}
	else
		_raise __EXCEPTIONS("Очередь пуста");
}

template <class T>
T Deque<T>::TopFromBack() {
	if (!IsEmpty()) {
		T info = Tall->info;
		return info;
	}
	else
		_raise __EXCEPTIONS("Очередь пуста");
}

template <class T>
T Deque<T>::TopFromFront() {
	if (!IsEmpty()) {
		T info = Head->info;
		return info;
	}
	else
		_raise __EXCEPTIONS("Очередь пуста");
}

template <class T>
void Deque<T>::Print() {
	Node<T> *tmp = Head;
	while (tmp != NULL) {
		cout << tmp->info << endl;
		tmp = tmp->next;
	}
}