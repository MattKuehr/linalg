#include <vector>
#include <iostream>
#include "tensors.h"
using namespace std;


Matrix::Matrix(int rows, int cols, vector<float> vec) {
        n_rows = rows;
        n_cols = cols;
        data = move(vec);
}

Matrix Matrix::transpose() {
    vector<float> newData(n_rows*n_cols);
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            newData[j*n_rows + i] = data[i*n_cols + j];
        }
    }
    Matrix transposed(n_cols, n_rows, newData);
    return transposed;
}

void Matrix::display() {
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            cout << data[i*n_cols + j] << " ";
        }
        cout << endl;
    }
}
