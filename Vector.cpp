#include <iostream>
#include "Vector.h"


template<typename T>
void DynamicVector<T>::copyElements(const T* const from,  T* const to, const T count)
{
    for(int i=0; i<count; i++)
    {
        to[i] = from[i];
    }
}

template<typename T>
DynamicVector<T>::DynamicVector()
    :size(0), capacity(10)
{
    data = new T[capacity];
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& vec)
    :size(vec.size), capacity(vec.capacity) 
    {
        data = new T[capacity];
        copyElements(vec.data, data, size);
    }

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& vec)
    {
        T* const temp = new T[vec.capacity];
        copyElements(vec.data, data, size);

        delete [] data;
        data = temp;

        return *this;
    }
template<typename T>
DynamicVector<T>::~DynamicVector()
    {
        delete [] data;
    }

template<typename T>
void DynamicVector<T>::push_back(const T& element)
{
        if(isReallocationNecessary())
        {
            reallocateMemory();
        }
    appendInMemory(element);
}

template<typename T>
bool DynamicVector<T>::isReallocationNecessary() const
{
    return capacity == size;
}

template<typename T>
void DynamicVector<T>::reallocateMemory()
{
    capacity *= 2;
    T* const temp = new T[capacity];
    copyElements(data, temp, size);

    delete [] data;
    data = temp; 
}

template<typename T>
void DynamicVector<T>::appendInMemory(const int element)
{
    data[size] = element;
    ++size;
}

template<typename T>
T DynamicVector<T>::getElement(const int index)
{
    return data[index];
}

template<typename T>
int DynamicVector<T>::getSize() const
{
    return size;
}

template<typename T>
T& DynamicVector<T>::operator[ ](unsigned int index) const
{
    if(index > (size-1))
    return data[index];
}
