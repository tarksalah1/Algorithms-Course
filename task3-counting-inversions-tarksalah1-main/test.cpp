
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include "naive_inversion.hpp"
#include "dandsQ_inversion.hpp"
#include "catch.hpp"
using namespace std;


TEST_CASE("Example 1", "[multi-file:2]") {

	int a[] = { 8, 4, 2, 1 };
	int arrSize = sizeof(a) / sizeof(a[0]);

	int naive_result = getInvCount(a, arrSize);
	int dandq_result = mergeSort(a,arrSize);
	REQUIRE(naive_result == dandq_result);
	REQUIRE(dandq_result == 6);
}

TEST_CASE("Example 2", "[multi-file:2]") {
	int a[] = { 3, 1, 2 };
	int arrSize = sizeof(a) / sizeof(a[0]);
	int naive_result = getInvCount(a, arrSize);
	int dandq_result = mergeSort(a,arrSize);
	REQUIRE(naive_result == dandq_result);
	REQUIRE(dandq_result == 2);
}