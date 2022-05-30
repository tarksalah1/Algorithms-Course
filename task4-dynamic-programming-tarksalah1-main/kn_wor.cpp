/* A Naive recursive implementation of
 0-1 Knapsack problem */
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
using namespace std;
using std::vector;


// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, vector<int>& w, vector<int>& v, int n)
{

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (w[n - 1] > W)
        return knapSack(W, w, v, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            v[n - 1]
            + knapSack(W - w[n - 1],
                w, v, n - 1),
            knapSack(W, w, v, n - 1));
}

// Driver code
int main()
{

    int totalCapacity, elements_num, element;
    cout << "asdasdasd";

    cin >> elements_num;
    cin >> totalCapacity;



    vector<int> elements_weight;
    vector<int> elements_values;

    for (int i = 0; i < elements_num; i++) {
        cin >> element;
        elements_weight.push_back(element);

    }

    for (int i = 0; i < elements_num; i++) {
        cin >> element;
        elements_values.push_back(element);

    }

    cout << knapSack(totalCapacity, elements_weight, elements_values, elements_num);
    return 0;
}