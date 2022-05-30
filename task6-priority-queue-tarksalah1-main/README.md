# PriorityQueue_Template

## Fill these info

### Name: ....

### Sec: ....

### B.N.: ....

## Task Explanation

- In this task you are required to build all the functions in my_pq.h
- There is my_pq_original.h file in case you need messed up my_pq.h, **don't edit my_tree_original.h**
- The functions are "constructors, extract_max, change_priority, peek, insert, remove"
- in main.cpp, you will get the input from the user
- The input format will be as follows
  - first line: two numbers, **initial_heap_size** **number_of_operations**
  - second line: **initial_heap_size** elemnets, the initial elements to be inserted in the heap
  - **number_of_operations** lines: operations to be done on the heap, operations can be one of the following
    - 1 priority --> insert priority in the heap
    - 2 index new_priority --> change priority of element at index i to new_priority
    - 3 index --> remove element at index i
    - 4 --> extract max element
    - 5 --> peek max element and print it
    - 6 --> apply extract_max on every element in the heap and print the result
    - 7 --> print size of the heap

## input example

- 7 7 // the initial heap size is 5, you are expecting 7 operations
- 4 1 2 8 6 3 5 // the elements to be inserted in the heap
- 1 7 // first operation, insert 7
- 2 0 5 // second operation, change priority of element at index 0 to 5
- 3 1   // remove element at index 1, which is supposed to be 6
- 4     // remove the root, which is supposed to be 7
- 5     // print max element, which is supposed to be 5
- 7     // print size, which is supposed to be 6
- 6     // print all eleemnts in PQ ==> 5 5 4 3 2 1

### General Notes

- This is an individual based assignment.
- The due date for the submission of this phase is Sunday, 2/1/2022 at 11:59 pm.
- Each hour delay will lead to one-point reduction in the homework’s grade.
- Your code should be clear, understandable, and documented (comments). Follow a consistent naming convention for variables and functions.
- You are permitted to discuss the following problems with others in the class. However, you must write up your own solutions to these problems. Any indication to the contrary will be considered an act of academic dishonesty.