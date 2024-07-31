#include "Vector.hpp"

int main()
{
    // Create a Vector with an initializer list
    Vector<int> vec{ 1, 2, 3, 4, 5 };
    Vector<int> vec2{ 5, 4, 3, 2, 1 };
    std::cout << "Initial Vector: ";
    std::cout << vec;  // Output: 5 4 3 2 1 

    // Reverse the Vector
    vec.reverse();
    std::cout << "Reversed Vector: ";
    std::cout << vec;  // Output: 5 4 3 2 1 

    // Pop the last element
    vec.popBack();
    std::cout << "After PopBack: ";
    std::cout << vec;  // Output: 5 4 3 2 

    // Clear the Vector
    vec.clear();
    std::cout << "After Clear: ";
    std::cout << vec;  // Output: (empty line)

    // Check if the Vector is empty
    if (vec.empty())
    {
        std::cout << "Vector is empty." << std::endl;
    }
    else
    {
        std::cout << "Vector is not empty." << std::endl;
    }

    // Push elements to the Vector
    vec.pushBack(10);
    vec.pushBack(20);
    vec.pushBack(30);
    std::cout << "After PushBack: ";
    std::cout << vec;  // Output: 10 20 30 

    // Check size and capacity
    std::cout << "Size: " << vec.getSize() << std::endl;        // Output: Size: 3
    std::cout << "Capacity: " << vec.getCapacity() << std::endl; // Output: Capacity: 10

    // Checking if the != operator is working
    if (vec != vec2)
    {
        std::cout << "vec and vec2 are not equal" << std::endl;
    }
    else
    {
        std::cout << "vec and vec2 are equal" << std::endl;
    }

    return 0;
}
