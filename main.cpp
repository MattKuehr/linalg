#include <iostream>
#include "tensors.h"
#include "tensor_ops.h"
using namespace std;

int main() {
    vector<int> intVec = create_vector(10, 1, 10);
    for (int elem : intVec) {
        cout << elem << " ";
    }
    cout << "\n";
    return 0;
}