#pragma once
#include <iostream>
#include <initializer_list>

class Vector
{
public:
    // Constructors
    Vector();
    Vector(const Vector& rhs);
    Vector(int elements, int value = 0);
    Vector(const std::initializer_list<int>& list);

    // Destructor
    ~Vector();

    // Functions
    void PushBack(int value);
    void PopBack();
    void Clear();
    void Reverse();
    void Display() const;
    bool Empty() const;
    int Size() const;
    int Capacity() const;

    // Operators
    bool operator==(const Vector& rhs) const;
    bool operator!=(const Vector& rhs) const;

    friend std::ostream& operator<<(std::ostream& ostr, const Vector& rhs);

private:
    int size;
    int capacity;
    int* array;
};
