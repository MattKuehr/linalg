#include <vector>
#include <iostream>
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

template <typename T>
PowerIterationReturn powerIteration(const T* matPtr, int n_row, int n_cols) {
    // Create PowerIteration method
}

int main() {

    PowerIterationReturn test(1.2, {1.2, 2.4});
    cout << test.eigenvalue << endl;
    for (int i = 0; i < test.eigenvector.size(); i++) {
        cout << test.eigenvector[i] << " ";
    }
    cout << endl;

    return 0;
}



