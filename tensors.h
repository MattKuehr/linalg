#ifndef TENSORS_H
#define TENSORS_H
#include <vector>
using namespace std;

struct Matrix {int n_rows; int n_cols; float* matPtr;};

template<typename T>
vector<T> create_random_data(int n_elems, T min_val, T max_val);

template<typename T>
vector<T> create_vector(int n_elems, T min_val, T max_val);

template<typename T>
vector<T> create_matrix(int n_rows, int n_cols, T min_val, T max_val);

#endif