#include <iostream>
#include "Auxiliary.hpp"
#include "Naive.hpp"


// Aliases
using type = int;
using Matrix = type**;
using size = std::size_t;


// Strassen's Algorithm
Matrix strassen(Matrix A, Matrix B, size N) {

	// Base case
	if (N == 4) {
		return sq_matrix_multiply(A, B, N);
	}

	// Create a new matrix to hold the result
	Matrix C = createMatrix(N);

	size K = N / 2;

	// New sub-matrices
	Matrix A11 = createMatrix(K);
	Matrix A12 = createMatrix(K);
	Matrix A21 = createMatrix(K);
	Matrix A22 = createMatrix(K);
	Matrix B11 = createMatrix(K);
	Matrix B12 = createMatrix(K);
	Matrix B21 = createMatrix(K);
	Matrix B22 = createMatrix(K);

	

	// Populate the values accordingly
	for (unsigned int i = 0; i < K; i++) {
		for (unsigned j = 0; j < K; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][K + j];		// Bug solved: I had a type: A22 instead of A12
			A21[i][j] = A[K + i][j];
			A22[i][j] = A[K + i][K + j];
			B11[i][j] = B[i][j];
			B12[i][j] = B[i][K + j];		// Bug solved: I had a type: B22 instead of B12
			B21[i][j] = B[K + i][j];
			B22[i][j] = B[K + i][K + j];
		}
	}

	Matrix P1 = strassen(A11, subtract(B12, B22, K), K);
	Matrix P2 = strassen(add(A11, A12, K), B22, K);
	Matrix P3 = strassen(add(A21, A22, K), B11, K);
	Matrix P4 = strassen(A22, subtract(B21, B11, K), K);
	Matrix P5 = strassen(add(A11, A22, K), add(B11, B22, K), K);
	Matrix P6 = strassen(subtract(A12, A22, K), add(B21, B22, K), K);
	Matrix P7 = strassen(subtract(A11, A21, K), add(B11, B12, K), K);

	// C_i	
	Matrix C11 = subtract(add(add(P5, P4, K), P6, K), P2, K);				// P5 + P4 - P2 + P6
	Matrix C12 = add(P1, P2, K);											// P1 + P2
	Matrix C21 = add(P3, P4, K);											// P3 + P4
	Matrix C22 = subtract(subtract(add(P5, P1, K), P3, K), P7, K);			// P1 + P5 - P3 - P7

	for (unsigned int i = 0; i < K; i++) {
		for (unsigned int j = 0; j < K; j++) {

			C[i][j] = C11[i][j];

			C[i][j + K] = C12[i][j];

			C[K + i][j] = C21[i][j];

			C[K + i][K + j] = C22[i][j];
		}
	}

	// Return the result
	return C;
}
