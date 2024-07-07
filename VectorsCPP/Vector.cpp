#include "Vector.h"

Vector::Vector()
	:size(0),
	capacity(5),
	array(new int[capacity])
{
	//Nothing to look in here :0
}
Vector::Vector(const Vector& rhs)
	:size(rhs.size),
	capacity(rhs.capacity + 5),
	array(new int[capacity])
{
	for (int i = 0; i < rhs.Size(); i++)
	{
		array[i] = rhs.array[i];
	}
}
Vector::Vector(int elements, int value)
	:size(elements),
	capacity(elements + 5),
	array(new int[capacity])
{
	for (int i = 0; i < size; i++)
	{
		array[i] = value;
	}
}

Vector::Vector(const std::initializer_list<int>& list)
	:size(0),
	capacity(list.size() + 5),
	array(new int[capacity])
{
	for (int i : list)
	{
		PushBack(i);
	}
}

Vector::~Vector()
{
	delete[] array;
}

void Vector::PushBack(int value)
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

bool Vector::Empty()const
{
	return size == 0;
}

int Vector::Size()const
{
	return size;
}

int Vector::Capacity()const
{
	return capacity;
}

bool Vector::operator==(const Vector& rhs) const
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

bool Vector::operator!=(const Vector& rhs)const
{
	return!(*this == rhs);
}

std::ostream& operator<<(std::ostream& ostr, const Vector& rhs)
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
