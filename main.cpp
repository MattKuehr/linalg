#include <iostream>
#include "tensors.h"
#include "tensor_ops.h"
using namespace std;

int main() {
    vector<float> m1_data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    vector<float> v1_data = {4.0, 5.0, 6.0};
    Matrix m1(3, 3, m1_data);
    Matrix v1(3, 1, v1_data);
    m1.display();
    cout << endl;
    v1.display();
    cout << endl << "Rayleigh quotient:\n";
    float res = RayleighQuotient(m1, v1);
}