#ifndef TENSORS_H
#define TENSORS_H
#include <vector>
#include <random>
#include <type_traits>
using namespace std;

// Put full blueprint of matrix struct in header, implement in cpp file
struct Matrix {
    int n_rows;
    int n_cols;
    vector<float> data;

    Matrix(int rows, int cols, vector<float> vec);

    Matrix transpose(); // Have transpose return a new matrix

    void display();
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
        for (int i = 0; i < n_elems; i++) vec[i] = distrib(gen);
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

#endif