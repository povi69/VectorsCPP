#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>

constexpr int capacityNumber = 5;
constexpr int multiplier = 2;

template<typename T>
class Vector
{

public:

    // Constructors
    /// <summary>
    /// a constructor class
    /// to handle vector()
    /// </summary>
    Vector()
        : size(0),
        capacity(capacityNumber),
        array(new T[capacity])
    {
    }

    /// <summary>
    /// Constructor function to handle Vector(Size)
    /// </summary>
    /// <param name="rhs"></param>
    Vector(const Vector& rhs)
        : size(rhs.size),
        capacity(rhs.capacity),
        array(new T[capacity])
    {
        for (int i = 0; i < rhs.size; i++)
        {
            array[i] = rhs.array[i];
        }
    }

    /// <summary>
    /// Constructor function to handle vector(number, size)
    /// </summary>
    /// <param name="elements"></param>
    /// <param name="value"></param>
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

    /// <summary>
    /// Constructor function to handle Vector {1,2,3,4,5}
    /// </summary>
    /// <param name="list"></param>
    Vector(const std::initializer_list<T>& list)
        : size(0),
        capacity(list.size() + capacityNumber),
        array(new T[capacity])
    {
        for (const T& i : list)
        {
            pushBack(i);
        }
    }

    /// <summary>
    /// Deconstructor for Vector()
    /// </summary>
    ~Vector()
    {
        delete[] array;
    }

    /// <summary>
    /// Function to put a value at the top of the vector
    /// </summary>
    /// <param name="value"></param>
    void pushBack(T value)
    {
        if (size < capacity)
        {
            array[size] = value;
            ++size;
        }
        else
        {
            capacity *= multiplier;
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

    /// <summary>
    /// remove the first number in the vector. 
    /// it does not return it
    /// </summary>
    void popBack()
    {
        if (size > 0)
        {
            --size;
        }
    }

    void clear()
    {
        size = 0;
    }

    /// <summary>
    /// Flip the values in the vector. for example 1,2,3,4 will be 4,3,2,1
    /// </summary>
    void reverse()
    {
        std::reverse(array, array + size);
    }

    /// <summary>
    /// Prints the vector's values
    /// </summary>
    void display() const
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    /// <summary>
    /// Clears the vector
    /// </summary>
    /// <returns></returns>
    bool empty() const
    {
        return size == 0;
    }

    /// <summary>
    /// returns the size of the vector
    /// </summary>
    /// <returns></returns>
    size_t getSize() const
    {
        return size;
    }

    /// <summary>
    /// returns the capactiy of the vector
    /// </summary>
    /// <returns></returns>
    size_t getCapacity() const
    {
        return capacity;
    }

    /// <summary>
    /// check if the 2 vectors are equal. for example if(vec1 == vec2)
    /// </summary>
    /// <param name="rhs"></param>
    /// <returns></returns>
    bool operator==(const Vector& rhs) const
    {
        if (size != rhs.size)
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            if (array[i] != rhs.array[i])
            {
                return false;
            }
        }
        return true;
    }

    /// <summary>
    /// checks if 2 vectors are not equal. for example if(vec1 != vec2)
    /// </summary>
    /// <param name="rhs"></param>
    /// <returns></returns>
    bool operator!=(const Vector& rhs) const
    {
        return !(*this == rhs);
    }

private:
    size_t size;
    size_t capacity;
    T* array;
};
