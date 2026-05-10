#include <vector>
#include <iostream>
#include "tensors.h"
#include "tensor_ops.h"
using namespace std;

// We should expect inputs at (1xn) and (nx1) to generalize for matrix multiplication
template <typename T>
float inner_prod(const T* a, const T* b, int mat2_cols, int n_elems) {
    float res = 0.0f;
    for (int i = 0; i < n_elems; i++) {
        res = res + *(a + i) * *(b + i*mat2_cols);
    }
    return res;
}

Matrix matmul(Matrix m1, Matrix m2) {
    int m1_rows = m1.n_rows;
    int m1_cols = m1.n_cols;
    int m2_rows = m2.n_rows;
    int m2_cols = m2.n_cols;

    vector<float> vec(m1_rows*m2_cols);
    float* m1Ptr = m1.data.data();
    float* m2Ptr = m2.data.data();
    for (int i = 0; i < m1_rows; i++) {
        for (int j = 0; j < m2_cols; j++) {
            vec[i*m2_cols + j] = inner_prod(m1Ptr + i*m1_cols, m2Ptr + j, m2_cols, m1_cols);
        }
    }
    Matrix res(m1_rows, m2_cols, move(vec));
    return res;
}

int main() {
    vector<float> v1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    vector<float> v2 = {10.0, 13.0, 5.0, 4.0, 3.0, 8.0, 14.0, 26.0, 19.0};
    Matrix mat1(3, 3, move(v1));
    Matrix mat2(3, 3, move(v2));
    Matrix res = matmul(mat1, mat2);
    res.display();
    return 0;
}