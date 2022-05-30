#ifndef MY_PQ_H
#define MY_PQ_H

#include <vector>
using namespace std;

class My_PQ{

public:
    My_PQ(){}
    
    My_PQ(vector<int> arr){}
    
    int extract_max(){}

    int change_priority(int index, int new_priority){}

    int peek(){}

    void insert(int value){} 

    void remove(int index){}

};

#endif