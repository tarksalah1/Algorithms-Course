#include "hash.h"
#include<iostream>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

// d is the number of characters in the input alphabet
#define d 256

vector<int> search_pattern_hash(string Txt, string pat) {
    vector<int> occurance;
    const char* Text = Txt.c_str();

    const char* Pattern = pat.c_str();

    int m = strlen(Pattern);
    int n = strlen(Text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++) {
        h = (h * d) % 13;
    }
    // Calculate hash value for pattern and text
    for (i = 0; i < m; i++) {
        p = (d * p + Pattern[i]) % 13;
        t = (d * t + Text[i]) % 13;
    }

    // Find the match
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (Text[i + j] != Pattern[j])
                    break;
            }

            if (j == m)
                occurance.push_back(i);
        }

        if (i < n - m) {
            t = (d * (t - Text[i] * h) + Text[i + m]) % 13;

            if (t < 0)
                t = (t + 13);
        }
    }

    return occurance;
}