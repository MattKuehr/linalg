#include <vector>
#include <iostream>
#include <random>
#include "tensors.h"


/*
Int tensors
*/
std::vector<int> create_vector_int(int n_elems, int min_val, int max_val) {
    std::vector<int> vec(n_elems);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min_val, max_val);

    for (int i = 0; i < n_elems; i++) {
        vec[i] = distrib(gen);
    }

    return vec;
}

std::vector<int> create_matrix_int(int n_rows, int n_cols, int min_val, int max_val) {
    std::vector<int> vec(n_rows * n_cols);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min_val, max_val);

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            vec[n_cols * i + j] = distrib(gen);
        }
    }

    return vec;
}


/*
Float tensors
*/
std::vector<float> create_vector_float(int n_elems, float min_val, float max_val) {
    std::vector<float> vec(n_elems);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(min_val, max_val);

    for (int i = 0; i < n_elems; i++) {
        vec[i] = distrib(gen);
    }

    return vec;
}

std::vector<float> create_matrix_float(int n_rows, int n_cols, float min_val, float max_val) {
    std::vector<float> vec(n_rows * n_cols);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(min_val, max_val);

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            vec[n_cols * i + j] = distrib(gen);
        }
    }

    return vec;
}


/*
Double tensors
*/
std::vector<double> create_vector_double(int n_elems, double min_val, double max_val) {
    std::vector<double> vec(n_elems);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(min_val, max_val);

    for (int i = 0; i < n_elems; i++) {
        vec[i] = distrib(gen);
    }

    return vec;
}

std::vector<double> create_matrix_double(int n_rows, int n_cols, double min_val, double max_val) {
    std::vector<double> vec(n_rows * n_cols);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(min_val, max_val);

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            vec[n_cols * i + j] = distrib(gen);
        }
    }

    return vec;
}

// int main() {
//     std::cout << "Testing int creation:" << std::endl;
//     std::vector<int> myIntVec = create_vector_int(5, 1, 10);
//     std::cout << "Vector of size " << myIntVec.size() << std::endl;
//     for (int element : myIntVec) {
//         std::cout << element << " ";
//     }
//     std::cout << "\n\n";

//     std::vector<int> myIntMatrix = create_matrix_int(5, 4, 1, 10);
//     std::cout << "Matrix of shape 5x4" << std::endl; 
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 4; j++)
//             std::cout << myIntMatrix[4*i + j] << " ";
//         std::cout << std::endl;
//     }
//     std::cout << "\n\n";

//     std::cout << "Testing float creation:" << std::endl;
//     std::vector<float> myFloatVec = create_vector_float(5, 1.0, 10.0);
//     std::cout << "Vector of size " << myFloatVec.size() << std::endl;
//     for (float element : myFloatVec) {
//         std::cout << element << " ";
//     }
//     std::cout << "\n\n";

//     std::vector<float> myFloatMatrix = create_matrix_float(5, 4, 1.0, 10.0);
//     std::cout << "Matrix of shape 5x4" << std::endl; 
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 4; j++)
//             std::cout << myFloatMatrix[4*i + j] << " ";
//         std::cout << std::endl;
//     }
//     std::cout << "\n\n";

//     std::cout << "Testing double creation:" << std::endl;
//     std::vector<double> myDoubleVec = create_vector_double(5, 1.0, 10.0);
//     std::cout << "Vector of size " << myDoubleVec.size() << std::endl;
//     for (double element : myDoubleVec) {
//         std::cout << element << " ";
//     }
//     std::cout << "\n\n";

//     std::vector<double> myDoubleMatrix = create_matrix_double(5, 4, 1.0, 10.0);
//     std::cout << "Matrix of shape 5x4" << std::endl; 
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 4; j++)
//             std::cout << myDoubleMatrix[4*i + j] << " ";
//         std::cout << std::endl;
//     }

//     return 0;
// }