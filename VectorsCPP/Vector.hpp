#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>


class Vector
{
public:
    // Constructors
    Vector()
        :size(0),
        capacity(5),
        array(new int[capacity])
    {

    }

    Vector(const Vector& rhs)
        :size(rhs.size),
        capacity(rhs.capacity + 5),
        array(new int[capacity])
    {
        for (int i = 0; i < rhs.Size(); i++)
        {
            array[i] = rhs.array[i];
        }
    }

    Vector(int elements, int value)
        : size(elements),
        capacity(elements + 5),
        array(new int[capacity])
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = value;
        }
    }

    Vector(const std::initializer_list<int>& list)
        : size(0),
        capacity(list.size() + 5),
        array(new int[capacity])
    {
        for (int i : list)
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
    void PushBack(int value)
    {
        if (size < capacity)
        {
            array[size] = value;
            ++size;
        }
        else
        {
            capacity *= 2;
            int* newarray = new int[capacity];
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
    //remove the last number from the vector
    void PopBack()
    {
        if (size > 0)
        {
            --size;
        }
    }
    //clears the vector and make the size equal to 0
    void Clear()
    {
        size = 0;
    }

    //using a built in librerty to reverse the numbers
    void Reverse()
    {
        std::reverse(array, array + size);
    }

    //Displays the Vector
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

    friend std::ostream& operator<<(std::ostream& ostr, const Vector& rhs)
    {
        for (int i = 0; i < rhs.size; i++)
        {
            ostr << rhs.array[i] << " ";
        }

        ostr << " || ";

        for (int i = rhs.size; i < rhs.capacity; i++)
        {
            ostr << rhs.array[i] << " ";
        }
        return ostr;
    }

private:
    int size;
    int capacity;
    int* array;
};
