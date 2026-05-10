#include <vector>
#include <iostream>
#include "tensors.h"
#include "tensor_ops.h"
using namespace std;

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
