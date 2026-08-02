// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(const int matrix[10][10], int transposed[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(const int mat1[10][10], const int mat2[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplyMatrices(const int mat1[10][10], const int mat2[10][10], int result[10][10], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows, cols;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0 || rows > 10 || cols > 10) {
        cout << "Error: Dimensions must be between 1 and 10." << endl;
        return 1;
    }

    int matrixA[10][10];
    cout << "Enter elements for Matrix A:" << endl;
    readMatrix(matrixA, rows, cols);

    cout << "\nOriginal Matrix A:" << endl;
    printMatrix(matrixA, rows, cols);

    int transposed[10][10];
    transposeMatrix(matrixA, transposed, rows, cols);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);

    cout << "\nEnter elements for Matrix B (same size " << rows << "x" << cols << "):" << endl;
    int matrixB[10][10];
    readMatrix(matrixB, rows, cols);

    int sumMatrix[10][10];
    addMatrices(matrixA, matrixB, sumMatrix, rows, cols);
    cout << "\nSum Matrix (A + B):" << endl;
    printMatrix(sumMatrix, rows, cols);

    int colsC;
    cout << "\nEnter number of columns for Matrix C (rows must be " << cols << "): ";
    cin >> colsC;

    if (colsC <= 0 || colsC > 10) {
        cout << "Error: Columns must be between 1 and 10." << endl;
        return 1;
    }

    cout << "Enter elements for Matrix C (" << cols << "x" << colsC << "):" << endl;
    int matrixC[10][10];
    readMatrix(matrixC, cols, colsC);

    int productMatrix[10][10];
    multiplyMatrices(matrixA, matrixC, productMatrix, rows, cols, colsC);
    cout << "\nProduct Matrix (A x C):" << endl;
    printMatrix(productMatrix, rows, colsC);

    return 0;
}
