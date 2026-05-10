#include <vector>
#include <iostream>
#include <random>
#include <type_traits>
#include "tensors.h"
using namespace std;

struct Matrix {
    int n_rows;
    int n_cols;
    float* matPtr;

    // Constructor (& prevents a temporary copy)
    Matrix(int rows, int cols, vector<float>& vec) {
        n_rows = rows;
        n_cols = cols;
        matPtr = vec.data();
    }

    void display() {
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                cout << *(matPtr + (i*n_cols) + j) << " ";
            }
            cout << endl;
        }
    }

};

template <typename T>
vector<T> create_random_data(int n_elems, T min_val, T max_val) {
    vector<T> vec(n_elems);

    random_device rd;
    mt19937 gen(rd());

    if constexpr (is_floating_point_v<T>) {
        uniform_real_distribution<T> distrib(min_val, max_val);
        for (int i = 0; i < n_elems; i++) vec[i] = distrib(gen); 
    }

    else {
        uniform_int_distribution<T> distrib(min_val, max_val);
        for int(i = 0; i < n_elems; i++) vec[i] = distrib(gen);
    }

    return vec;
}

template <typename T>
vector<T> create_vector(int n_elems, T min_val, T max_val) {
    return create_random_data(n_elems, min_val, max_val);
}

template <typename T>
vector<T> create_matrix(int n_rows, int n_cols, T min_val, T max_val) {
    return create_random_data(n_rows*n_cols, min_val, max_val);
}


int main() {

    vector<float> myVec = create_vector(9, 1.0f, 10.0f);
    for (int i = 0; i < myVec.size(); i++) {
        cout << myVec[i] << " ";
    }
    cout << endl;

    Matrix myMatrix(3, 3, myVec);
    myMatrix.display();
    cout << endl;

    return 0;
}