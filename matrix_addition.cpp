#include <iostream>
#include <vector>
using namespace std;

void print_matrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void matrix_addition(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C) {
    int m = A.size();
    int n = A[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> B = {
        {7, 8, 9},
        {1, 2, 3}
    };

    vector<vector<int>> C(A.size(), vector<int>(A[0].size()));

    matrix_addition(A, B, C);

    cout << "矩陣A + 矩陣B的結果為: " << endl;
    print_matrix(C);

    return 0;
}