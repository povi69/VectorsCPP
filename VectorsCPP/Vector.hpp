#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>

/**
 * @brief A template class for a dynamic array, similar to std::vector.
 *
 * @tparam T The type of elements stored in the vector.
 */
template<typename T>
class Vector
{
public:
    /// @brief Initial capacity for the vector.
    static constexpr int capacityNumber = 5;
    /// @brief Multiplier for increasing the capacity when resizing.
    static constexpr int multiplier = 2;

    /**
     * @brief Default constructor initializes an empty vector with a default capacity.
     */
    Vector()
        : size(0),
        capacity(capacityNumber),
        array(new T[capacity])
    {
    }

    /**
     * @brief Copy constructor to create a new vector as a copy of another.
     *
     * @param rhs The vector to copy from.
     */
    Vector(const Vector& rhs)
        : size(rhs.size),
        capacity(rhs.capacity),
        array(new T[capacity])
    {
        std::copy(rhs.array, rhs.array + rhs.size, array);
    }

    /**
     * @brief Constructor to initialize a vector with a specified number of elements, all set to a given value.
     *
     * @param elements Number of elements to initialize.
     * @param value The value to assign to all elements.
     */
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

    /**
     * @brief Constructor to initialize a vector from an initializer list.
     *
     * @param list The initializer list containing elements to initialize the vector.
     */
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

    /**
     * @brief Destructor to clean up dynamically allocated memory.
     */
    ~Vector()
    {
        delete[] array;
    }

    /**
     * @brief Adds a value to the end of the vector.
     *
     * @param value The value to add.
     */
    void pushBack(T value)
    {
        if (size < capacity)
        {
            array[size] = std::move(value);
            ++size;
        }
        else
        {
            resizeAndMoveElements();
            array[size] = std::move(value);
            ++size;
        }
    }

    /**
     * @brief Inserts a value at a specified index in the vector.
     *
     * @param index The position at which to insert the new value.
     * @param value The value to insert.
     * @throws std::out_of_range if the index is out of bounds.
     */
    void insert(size_t index, T value)
    {
        if (index > size)
        {
            throw std::out_of_range("Index out of bounds.");
        }

        if (size >= capacity)
        {
            resizeAndMoveElements();
        }

        for (size_t i = size; i > index; --i)
        {
            array[i] = std::move(array[i - 1]);
        }

        array[index] = std::move(value);
        ++size;
    }

    /**
     * @brief Removes the last element of the vector.
     */
    void popBack()
    {
        if (size > 0)
        {
            --size;
        }
    }

    /**
     * @brief Clears all elements from the vector.
     */
    void clear()
    {
        size = 0;
    }

    /**
     * @brief Reverses the elements of the vector.
     */
    void reverse()
    {
        std::reverse(array, array + size);
    }

    /**
     * @brief Overloads the << operator to output the vector's values.
     *
     * @param os The output stream.
     * @param vec The vector to output.
     * @return std::ostream& The output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec)
    {
        for (size_t i = 0; i < vec.size; ++i)
        {
            os << vec.array[i] << " ";
        }
        return os;
    }

    /**
     * @brief Checks if the vector is empty.
     *
     * @return true If the vector is empty.
     * @return false If the vector is not empty.
     */
    bool empty() const
    {
        return size == 0;
    }

    /**
     * @brief Returns the number of elements in the vector.
     *
     * @return size_t The number of elements in the vector.
     */
    size_t getSize() const
    {
        return size;
    }

    /**
     * @brief Returns the capacity of the vector.
     *
     * @return size_t The capacity of the vector.
     */
    size_t getCapacity() const
    {
        return capacity;
    }

    /**
     * @brief Checks if two vectors are equal.
     *
     * @param rhs The vector to compare with.
     * @return true If the vectors are equal.
     * @return false If the vectors are not equal.
     */
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

    /**
     * @brief Checks if two vectors are not equal.
     *
     * @param rhs The vector to compare with.
     * @return true If the vectors are not equal.
     * @return false If the vectors are equal.
     */
    bool operator!=(const Vector& rhs) const
    {
        return !(*this == rhs);
    }

private:
    size_t size;     ///< The current number of elements in the vector.
    size_t capacity; ///< The current capacity of the vector.
    T* array;        ///< Pointer to the dynamically allocated array.

    /**
     * @brief Resizes the vector's capacity and moves existing elements to the new array.
     */
    void resizeAndMoveElements()
    {
        capacity *= multiplier;
        T* newarray = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            newarray[i] = std::move(array[i]);
        }
        delete[] array;
        array = newarray;
    }
};
