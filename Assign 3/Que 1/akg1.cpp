#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixMult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    if (n == 1) {
        result[0][0] = A[0][0] * B[0][0];
    } else {
        vector<vector<int>> A11(n / 2, vector<int>(n / 2));
        vector<vector<int>> A12(n / 2, vector<int>(n / 2));
        vector<vector<int>> A21(n / 2, vector<int>(n / 2));
        vector<vector<int>> A22(n / 2, vector<int>(n / 2));

        vector<vector<int>> B11(n / 2, vector<int>(n / 2));
        vector<vector<int>> B12(n / 2, vector<int>(n / 2));
        vector<vector<int>> B21(n / 2, vector<int>(n / 2));
        vector<vector<int>> B22(n / 2, vector<int>(n / 2));

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + n / 2];
                A21[i][j] = A[i + n / 2][j];
                A22[i][j] = A[i + n / 2][j + n / 2];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + n / 2];
                B21[i][j] = B[i + n / 2][j];
                B22[i][j] = B[i + n / 2][j + n / 2];
            }
        }

    vector<vector<int>> C11(n / 2, vector<int>(n / 2));
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            C11[i][j] = matrixMult(A11, B11)[i][j] + matrixMult(A12, B21)[i][j];
        }
    }

    vector<vector<int>> C12(n / 2, vector<int>(n / 2));
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            C12[i][j] = matrixMult(A11, B12)[i][j] + matrixMult(A12, B22)[i][j];
        }
    }

    vector<vector<int>> C21(n / 2, vector<int>(n / 2));
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            C21[i][j] = matrixMult(A21, B11)[i][j] + matrixMult(A22, B21)[i][j];
        }
    }

    vector<vector<int>> C22(n / 2, vector<int>(n / 2));
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            C22[i][j] = matrixMult(A21, B12)[i][j] + matrixMult(A22, B22)[i][j];
        }
    }


        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                result[i][j] = C11[i][j];
                result[i][j + n / 2] = C12[i][j];
                result[i + n / 2][j] = C21[i][j];
                result[i + n / 2][j + n / 2] = C22[i][j];
            }
        }
    }

    return result;
}

void printMatrix(const vector<vector<int>>& matrix, ofstream& outputFile) {
    for (const auto& row : matrix) {
        for (int num : row) {
            outputFile << num << " ";
        }
        outputFile << endl;
    }
}
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    for (int testCase = 0; testCase < 2; ++testCase) {
        int n;
        inputFile >> n;

        vector<vector<int>> A(n, vector<int>(n));
        vector<vector<int>> B(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inputFile >> A[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inputFile >> B[i][j];
            }
        }

        vector<vector<int>> result = matrixMult(A, B);

        outputFile << "Test Case " << testCase + 1 << ":\n";
        printMatrix(result, outputFile);
        outputFile << "\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
