#ifndef AUX_HPP
#define AUX_HPP

#include <iostream>
#include <chrono>
#include <random>

// Aliases
using type = int;
using Matrix = type**;
using size = std::size_t;


// Randomize matrix function
void randomize(Matrix& A, size N) {	// O(n^2)
	
	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = 0; j < N; j++) {
			int randomNum = rand()%100;
			A[i][j] = randomNum;
		}
	}
}

// Returns a new NxN matrix
Matrix createMatrix(size N) {
	Matrix newMatrix = new type * [N];
	for (unsigned int i = 0; i < N; i++) {
		newMatrix[i] = new type[N];
	}
	return newMatrix;
}


/***** Matrix Operations *******/


// Add two matrices
Matrix add(Matrix A, Matrix B, size N) {

	Matrix C = createMatrix(N);

	for (unsigned int i = 0; i < N; i++)
		for (unsigned int j = 0; j < N; j++)
			C[i][j] = A[i][j] + B[i][j];

	return C;
}

// Subtract two matrices
Matrix subtract(Matrix A, Matrix B, size N) {
	Matrix C = createMatrix(N);

	for (unsigned int i = 0; i < N; i++)
		for (unsigned int j = 0; j < N; j++)
			C[i][j] = A[i][j] - B[i][j];

	return C;
}


#endif // !AUX_HPP