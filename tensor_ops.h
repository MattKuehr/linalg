#ifndef TENSOR_OPS_H
#define TENSORS_OPS_H

// We should expect inputs at (1xn) and (nx1) to generalize for matrix multiplication
template <typename T>
float inner_prod(const T* a, const T* b, int mat2_cols, int n_elems) {
    float res = 0.0f;
    for (int i = 0; i < n_elems; i++) {
        res = res + *(a + i) * *(b + i*mat2_cols);
    }
    return res;
}

Matrix matmul(Matrix m1, Matrix m2);

#endif