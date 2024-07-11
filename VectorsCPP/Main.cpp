#include "Vector.hpp"

int main()
{
    // Create a Vector with an initializer list
    Vector vec{ 1, 2, 3, 4, 5 };
    std::cout << "Initial Vector: ";
    vec.Display();  // Output: 1 2 3 4 5 

    // Reverse the Vector
    vec.Reverse();
    std::cout << "Reversed Vector: ";
    vec.Display();  // Output: 5 4 3 2 1 

    // Pop the last element
    vec.PopBack();
    std::cout << "After PopBack: ";
    vec.Display();  // Output: 5 4 3 2 

    // Clear the Vector
    vec.Clear();
    std::cout << "After Clear: ";
    vec.Display();  // Output: (empty line)

    // Check if the Vector is empty
    if (vec.Empty())
    {
        std::cout << "Vector is empty." << std::endl;
    }
    else
    {
        std::cout << "Vector is not empty." << std::endl;
    }

    // Push elements to the Vector
    vec.PushBack(10);
    vec.PushBack(20);
    vec.PushBack(30);
    std::cout << "After PushBack: ";
    vec.Display();  // Output: 10 20 30 

    // Check size and capacity
    std::cout << "Size: " << vec.Size() << std::endl;        // Output: Size: 3
    std::cout << "Capacity: " << vec.Capacity() << std::endl; // Output: Capacity: 10

    return 0;
}
