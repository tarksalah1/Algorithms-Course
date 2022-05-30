#include "hash.h"
#include "naive.h"
#include <iostream>
#include <vector>
using namespace std;


void print(vector<int> const& input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << ' ';
    }
}

int main(int argc, char** argv) {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> occurance_naive = search_pattern_naive(text, pattern);
    print(occurance_naive);
    cout << endl;

    vector<int> occurance_hash = search_pattern_hash(text, pattern);
    print(occurance_hash);
}
