#include <iostream>
#include <chrono>
#include <random>
#include <chrono>
#include <thread>
#include "Strassen.hpp";

bool areEqual(Matrix C1, Matrix C2, int N);
// Test
int main() {


	while (true) {

		//Matrix Size n*n
		size N = 128;

		

		// Matrices
		Matrix A = createMatrix(N), B = createMatrix(N), C1 = createMatrix(N), C2 = createMatrix(N);

		// Initialize the matrices
		randomize(A, N);
		randomize(B, N);

		auto naive_start = std::chrono::high_resolution_clock::now();

		// Compute A * B using Naive's Algorithm
		C1 = sq_matrix_multiply(A, B, N);


		auto naive_finish = std::chrono::high_resolution_clock::now();


		auto strassen_start = std::chrono::high_resolution_clock::now();

		// Compute A * B using strassen's Algorithm
		C2 = strassen(A, B, N);

		auto strassen_finish = std::chrono::high_resolution_clock::now();

		auto naive_time = (naive_finish - naive_start).count();
		auto strassen_time = (strassen_finish - strassen_start).count();

		if (areEqual(C1, C2, N))
		{

			std::cout << "equivalent result " << std::endl;
			std::cout << "naive_time ==> " << naive_time << std::endl;
			std::cout << "strassen_time ==> " << strassen_time << std::endl;
			std::cout << "performance enhancment ==>" << naive_time / strassen_time << std::endl;
		}
		else
		{
			std::cout << "error, check your inputs and algortihms " << std::endl;
			// you may want to store your variables in a file to re-run the test on the same inputs;
			//break;
		}
	}
	return 0;
}

bool areEqual(Matrix C1, Matrix C2,int N)
{

	// Linearly compare elements

	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = 0; j < N; j++) {
			if (C1[i][j] != C2[i][j])
				return false;
		}
	}

	// If all elements were same.
	return true;
}
