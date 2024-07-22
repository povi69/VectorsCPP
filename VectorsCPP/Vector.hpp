#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>
int capacityNumber = 5;

template<typename T>
class Vector
{
public:
    // Constructors
    Vector()
        : size(0),
        capacity(capacityNumber),
        array(new T[capacity])
    {

    }
    
    Vector(const Vector& rhs)
        : size(rhs.size),
        capacity(rhs.capacity + capacityNumber),
        array(new T[capacity])
    {
        for (int i = 0; i < rhs.Size(); i++)
        {
            array[i] = rhs.array[i];
        }
    }

    Vector(int elements, T value)
        : size(elements),
        capacity(elements + capacityNumber),
        array(new T[capacity])
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = value;
        }
    }

    Vector(const std::initializer_list<T>& list)
        : size(0),
        capacity(list.size() + capacityNumber),
        array(new T[capacity])
    {
        for (const T& i : list)
        {
            PushBack(i);
        }
    }

    // Destructor
    ~Vector()
    {
        delete[] array;
    }

    // Functions
    void PushBack(T value)
    {
        if (size < capacity)
        {
            array[size] = value;
            ++size;
        }
        else
        {
            // Double the capacity
            capacity = capacity * 2;
            T* newarray = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                newarray[i] = array[i];
            }
            newarray[size] = value;
            ++size;
            delete[] array;
            array = newarray;
        }
    }

    void PopBack()
    {
        if (size > 0)
        {
            --size;
        }
    }

    void Clear()
    {
        size = 0;
    }

    void Reverse()
    {
        std::reverse(array, array + size);
    }

    void Display() const
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    bool Empty() const
    {
        return size == 0;
    }

    int Size() const
    {
        return size;
    }

    int Capacity() const
    {
        return capacity;
    }

    bool operator==(const Vector& rhs) const
    {
        if (Size() != rhs.Size())
        {
            return false;
        }

        for (int i = 0; i < Size(); i++)
        {
            if (array[i] != rhs.array[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector& rhs) const
    {
        return !(*this == rhs);
    }

private:
    int size;
    int capacity;
    T* array;
};
