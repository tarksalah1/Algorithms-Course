#include "naive.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> search_pattern_naive(string Text, string pattern){
    vector<int> occurance;
    int found = Text.find(pattern);
    while (found != string::npos) {
        occurance.push_back(found);
        found = Text.find(pattern, found + 1);
    }
    return occurance;
}
