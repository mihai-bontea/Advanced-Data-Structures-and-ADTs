#include "Deque.h"
#include <stdexcept>

template <class T>
Deque<T>::Deque()
{

}

template <class T>
Deque<T>::~Deque()
{

}

template <class T>
void Deque<T>::push_front(T elem)
{
	elems.insertFirst(elem);
}

template <class T>
void Deque<T>::push_back(T elem)
{
	elems.insertLast(elem);
}

template <class T>
T Deque<T>::front() const
{
	if (elems.isEmpty())
		throw std::exception();
	
	return elems.get_head();
}

template <class T>
T Deque<T>::back() const
{
	if (elems.isEmpty())
		throw std::exception();

	return elems.get_tail();
}

template <class T>
T Deque<T>::pop_front()
{
	if (elems.isEmpty())
		throw std::exception();

	auto temp = elems.deleteFirst();
	T info = temp->info;
	delete temp;
	return info;
}

template <class T>
T Deque<T>::pop_back()
{
	if (elems.isEmpty())
		throw std::exception();

	auto temp = elems.deleteLast();
	T info = temp->info;
	delete temp;
	return info;
}

template <class T>
bool Deque<T>::isEmpty() const
{
	return elems.isEmpty();
}

template class Deque<int>;