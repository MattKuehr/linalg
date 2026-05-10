#include <iostream>
#include "tensors.h"
#include "tensor_ops.h"
using namespace std;

int main() {
    vector<float> v1_data = create_vector(10, 1.0f, 10.0f);
    vector<float> v2_data = create_vector(10, 1.0f, 10.0f);
    Matrix v1(10, 1, v1_data);
    Matrix v2(10, 1, v2_data);
    v1.transpose();
    cout << inner_prod(v1.data.data(), v2.data.data(), v2.n_cols, v1.n_cols);
}