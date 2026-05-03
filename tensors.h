#ifndef TENSORS_H
#define TENSORS_H
#include <vector>
using namespace std;

vector<int> create_vector_int(int n_elems, int min_val, int max_val);
vector<int> create_matrix_int(int n_rows, int n_cols, int min_val, int max_val);

vector<float> create_vector_float(int n_elems, float min_val, float max_val);
vector<float> create_matrix_float(int n_rows, int n_cols, float min_val, float max_val);

vector<double> create_vector_double(int n_elems, double min_val, double max_val);
vector<double> create_matrix_double(int n_rows, int n_cols, double min_val, double max_val);

#endif