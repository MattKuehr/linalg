#include <iostream>
#include <vector>

int main() {
    std::vector<float> v = {10.5f, 20.5f, 30.5f};
    float* ptr = v.data();

    // PRINTING THE DATA (THE VALUES)
    std::cout << "Value via dereference: " << *ptr << std::endl;   // Prints 10.5
    std::cout << "Value via indexing:    " << ptr[0] << std::endl; // Prints 10.5
    std::cout << "Value at index 1:     " << ptr[1] << std::endl; // Prints 20.5

    // PRINTING THE ADDRESSES (THE BOX LOCATIONS)
    std::cout << "Address of index 0:   " << ptr << std::endl;     // Prints 0x... (hex)
    std::cout << "Address of index 1:   " << (ptr + 1) << std::endl; // Prints 0x... (4 bytes higher)
    
    return 0;
}