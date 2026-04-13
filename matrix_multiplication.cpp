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

void matrix_multiplication(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C) {
    int A_m = A.size();
    int A_n = A[0].size();
    int B_m = B.size();
    int B_n = B[0].size();

    for (int i = 0; i < A_m; i++) {  // A的每一列
        for (int j = 0; j < B_n; j++) {  // B的每一行
            for (int k = 0; k < A_n; k++) {  // 內積累加
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> B = {
        {7, 8},
        {9, 10}, 
        {11, 12}
    };

    vector<vector<int>> C(A.size(), vector<int>(B[0].size()));

    matrix_multiplication(A, B, C);

    cout << "矩陣A X 矩陣B的結果為: " << endl;
    print_matrix(C);

    return 0;
}