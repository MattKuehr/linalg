#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    vector<int> matrix = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    int* ptr = matrix.data();

    // Using pointers
    cout << ptr << std::endl;  // Prints the hex code of the memory location
    cout << *ptr << std::endl;  // Prints the object at the memory location of ptr
    cout << ptr + 1 << std::endl;  // Prints the next valid address, skipping the size of the data type (int = 4 bytes here)
    cout << *(ptr + 1) << std::endl;  // Prints the object at the next memory location after ptr
    cout << ptr[1] << std::endl;  // Does the same as above, implicitly dereferencing and adjusting memory location
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << std::endl;
    
    return 0;
}