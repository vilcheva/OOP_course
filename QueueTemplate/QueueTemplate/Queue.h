#pragma once
#include <iostream>
#include <exception>
using namespace std;
const int CAPASITY = 8;

template <typename T>
class Queue
{
	T* array;
	size_t put;
	size_t get;
	size_t capasity;
	size_t size;

	void resize();
	void copyFrom(const T& other);
	void free();

public:
	Queue();
	~Queue();
	void push(T element);
	void pop();
	const T& peek() const;
	bool isEmpty()const;
};

template <typename T>
void Queue<T>::resize()
{
		T* temp = new T[capasity *= 2];
		int j = 0;
		for (int i = get; i < size; i++)
		{
			temp[j] = array[i];
			j++;
		}
		if (put < get)
		{
			for (int i = 0; i < put; i++)
			{
				temp[j] = array[i];
				j++;
			}
		}
		get = 0;
		put = size;
		delete[]array;
		array = new T[capasity];
		temp = array;
		

}
template <typename T>
void Queue<T>::copyFrom(const T& other)
{
	array = new T[other.size];
	int j = 0;
	for (int i = get; i < size; i++)
	{
		array[j] = other.array[i];
		j++;
	}
	if (get > put)
	{
		for (int i = 0; i < put; i++)
		{
			array[j] = other.array[i];
			j++;
		}
	}
	get = 0;
	put = other.size;
	capasity = other.capasity;
	size = other.size;

}
template <typename T>
void Queue<T>::free()
{
	delete[] array;
}

template <typename T>
Queue<T>::Queue()
{
	size = 0;
	capasity = CAPASITY;
	array = nullptr;
	get = 0;
	put = 1;
}
template <typename T>
Queue<T>::~Queue()
{
	free();
}
template <typename T>
void Queue<T>::push(T element)
{
	if (size == capasity)
	{
		resize();
	}
	array[put] = element;
	if (put == capacity - 1)
	{
		put = 0;
	}
	else
	{
		put++;
	}
	size++;
}
template <typename T>
void Queue<T>::pop()
{
	if (!isEmpty())
	{
		size--;
		if (get == size-1)
		{
			get = 0;
		}
		else
		{
			get++;
		}
	}
	else
	{
		throw "Queue is empty";
	}
}
template <typename T>
const T& Queue<T>::peek() const
{
	return array[put - 1];
}
template <typename T>
bool Queue<T>::isEmpty()const
{
	return size == 0;
}
