#include <vector>
#include <iostream>
#include "tensors.h"
#include "tensor_ops.h"
using namespace std;

struct PowerIterationReturn {
    float eigenvalue;
    vector<float> eigenvector;

    // Constructor
    PowerIterationReturn(float eigval, vector<float> eigvector) {
        eigenvalue = eigval;
        eigenvector = eigvector;
    }
};


PowerIterationReturn powerIteration(Matrix A, int n_rows, int n_cols) {
    Matrix vk(n_rows, 1, create_vector(n_rows, 1.0f, 10.0f));
    float lambda = 0.0;
    
    for (int k = 0; k < 1000; k++) {
        vk = matmul(A, vk);
        float vk_norm = vec_norm(vk, "2");
        
        // Edit vector in place directly with reference &
        for (float& val : vk.data) {
            val /= vk_norm;
        }

        Matrix Av = matmul(A, vk);
        Matrix vk_T = vk.transpose();
        lambda = inner_prod(vk_T.data.data(), Av.data.data(), Av.n_cols, vk_T.n_cols);
    }

    PowerIterationReturn res(lambda, vk.data);
    return res;
}

int main() {
    vector<float> data = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };
    Matrix A(3, 3, data);
    PowerIterationReturn result = powerIteration(A, 3, 3);
    cout << result.eigenvalue;
}



