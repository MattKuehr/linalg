#include <vector>
#include <iostream>
#include "tensors.h"
#include "tensor_ops.h"
using namespace std;

// We should expect inputs at (1xn) and (nx1) to generalize for matrix multiplication
template <typename T>
float inner_prod(const T* a, const T* b, int n_elems) {
    float res = 0.0f;
    for (int i = 0; i < n_elems; i++) {
        res = res + *(a + i) * *(b + i);
    }
    return res;
}

Matrix matmul(Matrix m1, Matrix m2) {
    int m1_rows = m1.n_rows;
    int m1_cols = m1.n_cols;
    int m2_rows = m2.n_rows;
    int m2_cols = m2.n_cols;

    vector<float> vec(m1_rows*m2_cols);
    for (int i = 0; i < m1_rows*m2_cols; i++) {
        vec[i] = inner_prod(m1.data.data(), m2.data.data(), m1_rows);
    }
    Matrix res(m1_rows, m2_cols, move(vec));
    return res;
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