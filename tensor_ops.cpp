#include <vector>
#include <cmath>
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

float vec_norm(Matrix v1, string p) {
    
    Matrix v1_T = v1.transpose();
    float v1_norm = sqrt(
        inner_prod(v1_T.data.data(), v1.data.data(), v1.n_cols, v1_T.n_cols)
    );
    return v1_norm;


}

float RayleighQuotient(Matrix m1, Matrix v1) {
    Matrix Mv = matmul(m1, v1);
    Matrix v1_T = v1.transpose();
    float numerator = inner_prod(v1_T.data.data(), Mv.data.data(), Mv.n_cols, v1_T.n_cols);
    float denominator = inner_prod(v1_T.data.data(), v1.data.data(), v1.n_cols, v1_T.n_cols);
    return numerator / denominator;
}
