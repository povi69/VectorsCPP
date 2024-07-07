#pragma once
#include <iostream>

class Vector
{
public:
	Vector();
	Vector(const Vector& rhs);
	Vector(int elements, int value = 0);
	Vector(const std::initializer_list<int>& list);

	~Vector();
	void PushBack(int value);

	bool Empty() const;
	int Size()const;
	int Capacity()const;

	bool operator==(const Vector& rhs) const;
	bool operator!=(const Vector& rhs) const;
	
	friend std::ostream& operator <<(std::ostream& ostr, const Vector& rhs);


private:
	int size;
	int capacity;
	int* array;
};