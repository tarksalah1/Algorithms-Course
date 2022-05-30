[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6401026&assignment_repo_type=AssignmentRepo)
# sbe307_Task 3 --> Counting Inversions

## Name: tark salah
## Sec: 1
## B.N.: 44


**Important Note**
- *A note to be remembered* IDE builds all cpp files then link them together
- Both stress.cpp and test.cpp has its own main function
so remember to do one of the following approaches

1. if you use your IDE blindly *which is totally ok* then comment one of these files then rebuild and run
2. remove one these files form the project, be careful not to delete the file, just remove it from the project then rebuild and run
3. if you control the building process then don't link both files

### Implement this task using c++
In this task you are required to fill 3 files
1. naive_inversion.hpp --> implement the naive solution to counting inversions problem
2. dandq_inversion.hpp --> implement the divide and conquer solution to counting inversions problem
3. stress.cpp --> implement stress test using both files

Read the comments carefully and fill the missing lines

### Problem description
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in the reverse order, the inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 

[hackerrank link for the problem](https://www.hackerrank.com/challenges/ctci-merge-sort/problem)

**Example 1**
Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

**Example 2**
Input: arr[] = {3, 1, 2}
Output: 2

Explanation: Given array has two inversions:
(3, 1), (3, 2) 


### General Notes
- This is an individual based assignment.
- The due date for the submission of this phase is Wednesday, 24/11/2021 at 11:59 pm.
- Each hour delay will lead to one-point reduction in the homework’s grade.
- **Your code should be clear, understandable, and documented (comments). Follow a consistent naming convention for variables and functions and Use clear names for your variables**.
- You are permitted to discuss the following problems with others in the class. However, you must write up your own solutions to these problems. Any indication to the contrary will be considered an act of academic dishonesty. 
- Please review the definition of cheating in the first presentation.
