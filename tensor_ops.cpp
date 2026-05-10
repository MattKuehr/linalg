#include <vector>
#include <iostream>
#include "tensors.h"
#include "tensor_ops.h"
using namespace std;

template <typename T>
double inner_prod(const T* a, const T* b, int n_elems) {
    double res = 0.0;
    for (int i = 0; i < n_elems; i++) {
        res = res + *(a + i) * *(b + i);
    }
    return res;
}

vector<float> matmul(Matrix m1, Matrix m2) {

}

int main_local() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    int* v1Ptr = v1.data();
    int* v2Ptr = v2.data();
    cout << "The inner product of v1 and v2 is " << inner_prod(v1Ptr, v2Ptr, v1.size()) << endl;
    return 0;
}

int main_local();