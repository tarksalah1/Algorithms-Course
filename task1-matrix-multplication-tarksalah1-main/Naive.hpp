#include <iostream>
#include "Auxiliary.hpp"

using type = int;
using Matrix = type**;
using size = std::size_t;

// Linear Matrix Multiplication
Matrix sq_matrix_multiply(Matrix A, Matrix B, size N) {

	Matrix C = createMatrix(N);

	type sum = 0;									// O(1)

	for (unsigned int i = 0; i < N; i++) {						// O(n^3)
		for (unsigned int j = 0; j < N; j++) {
			for (size k = 0; k < N; k++) {
				sum += A[i][k] * B[k][j];				// O(1)
			}
			C[i][j] = sum;							// O(1)
			sum = 0;							// O(1)
		}
	}
	return C;
}
