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

#include <iostream>
#include <iomanip>
using namespace std;

void readMat(int m[10][10], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> m[i][j];
        }
}

void printMat(int m[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << setw(5) << m[i][j];
        cout << endl;
    }
}

void transpose(int a[10][10], int r, int c, int t[10][10]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = a[i][j];
}

void add(int a[10][10], int b[10][10], int r, int c, int s[10][10]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            s[i][j] = a[i][j] + b[i][j];
}

void multiply(int a[10][10], int b[10][10], int m, int n, int p, int prod[10][10]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            prod[i][j] = 0;
            for (int k = 0; k < n; k++)
                prod[i][j] += a[i][k] * b[k][j];
        }
}

int main() {
    int a[10][10], b[10][10], r[10][10];
    int m, n, p;

    cout << "Enter rows and columns of A: ";
    cin >> m >> n;
    readMat(a, m, n);

    cout << "\nOriginal Matrix:\n";
    printMat(a, m, n);

    transpose(a, m, n, r);
    cout << "\nTransposed Matrix:\n";
    printMat(r, n, m);

    cout << "\nEnter Matrix B (same size as A) rows and columns: ";
    cin >> m >> n;
    readMat(b, m, n);

    add(a, b, m, n, r);
    cout << "\nSum Matrix:\n";
    printMat(r, m, n);

    cout << "\nEnter columns of B for multiplication (rows = columns of A): ";
    cin >> p;
    readMat(b, n, p);

    multiply(a, b, m, n, p, r);
    cout << "\nProduct Matrix:\n";
    printMat(r, m, p);

    return 0;
}
