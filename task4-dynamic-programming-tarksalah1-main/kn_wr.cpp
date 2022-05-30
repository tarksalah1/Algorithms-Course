#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
using namespace std;
using std::vector;

/**
* Responsible for dealing with the unbounded knapsack problem.
*/
class UnboundedKnapsack
{
    //-------------------------------------------------------------------------
    //      Attributes
    //-------------------------------------------------------------------------
    /**
    * Stores maximum value of the knapsack for a certain capacity.
    */
    vector<int> knapsack;

    /**
    * Stores elements that are part of the knapsack with a certain capacity.
    * <li><b>Line:</b> Knapsack capacity</li>
    * <li><b>Column:</b> Elements</li>
    */
    vector<vector<int> > selectedElements;

    /**
    * Stores maximum knapsack capacity.
    */
    int maximumCapacity;


public:
    //-------------------------------------------------------------------------
    //      Constructor
    //-------------------------------------------------------------------------
    UnboundedKnapsack()
    {
        maximumCapacity = -1;
    }


    //-------------------------------------------------------------------------
    //      Destructor
    //-------------------------------------------------------------------------
    ~UnboundedKnapsack()
    {
        delete this;
    }


    //-------------------------------------------------------------------------
    //      Methods
    //-------------------------------------------------------------------------
    /**
    * Unbounded knapsack allows to use one or more occurrences of an item.
    *
    * @param        w Weight of the elements
    * @param        v Value of the elements
    * @param        N Number of itens
    * @param        W Maximum weight capacity
    * @return       This object to allow chained calls
    */
    UnboundedKnapsack* knapsack_unbounded(vector<int>& w, vector<int>& v, int N, int W)
    {
        // Stores the maximum value which can be reached with a certain capacity
        knapsack.clear();
        knapsack.resize(W + 1);

        maximumCapacity = W + 1;

        // Stores selected elements with a certain capacity
        selectedElements.resize(W + 1);

        // Initializes maximum value vector with zero
        for (int i = 0; i < W + 1; i++) {
            knapsack[i] = 0;
        }

        // Computes the maximum value that can be reached for each capacity
        for (int capacity = 0; capacity < W + 1; capacity++) {
            // Goes through all the elements
            for (int n = 0; n < N; n++) {
                if (w[n] <= capacity) {
                    // max(knapsack[capacity], knapsack[capacity - w[n]] + v[n])
                    if (knapsack[capacity] <= knapsack[capacity - w[n]] + v[n]) {
                        knapsack[capacity] = knapsack[capacity - w[n]] + v[n];

                        // Stores selected elements
                        selectedElements[capacity].clear();
                        selectedElements[capacity].push_back(n + 1);

                        for (int elem : selectedElements[capacity - w[n]]) {
                            selectedElements[capacity].push_back(elem);
                        }
                    }
                }
            }
        }

        return this;
    }

    /**
    * Returns maximum value for a certain number of elements and a certain
    * capacity.
    *
    * @param        capacity Capacity of the knapsack
    * @return       Maximum possible value with capacity provided
    * @throws       std::invalid_argument If capacity provided is out of bounds
    */
    int getMaximumValue(int capacity)
    {
        if (capacity < 0 || capacity >= maximumCapacity)
            throw invalid_argument("Capacity out of bounds");

        return knapsack[capacity];
    }

    /**
    * Returns elements that belong to the knapsack with a certain capacity.
    *
    * @param        capacity Capacity of the knapsack
    * @return       Elements that are part of the knapsack with the capacity
    * provided
    * @throws       std::invalid_argument If capacity provided is out of bounds
    * @apiNote      Elements are referenced by their index + 1
    */
    vector<int>& getSelectedElements(int capacity)
    {
        if (capacity < 0 || capacity >= maximumCapacity)
            throw invalid_argument("Capacity out of bounds");

        return selectedElements[capacity];
    }

    /**
    * Returns elements that are part of the knapsack with a certain capacity.
    * This method will return a {@link std::string} with the following format:
    * <code>[elem1, elem2, elem3...]</code>
    *
    * @param        capacity Capacity of the knapsack
    * @return       Elements that are part of the knapsack with the capacity
    * provided
    * @apiNote      Elements are referenced by their index + 1
    */
    string selectedElements_toString(int capacity)
    {
        string response = "[";

        for (int element : selectedElements[capacity]) {
            response.append(to_string(element));
            response.append(", ");
        }

        // Removes last ", "
        response.pop_back();
        response.pop_back();

        response.append("]");

        return response;
    }
};


//-------------------------------------------------------------------------
//      Main
//-------------------------------------------------------------------------
/**
* Example made based on this exercise:
*/
int main()
{
    UnboundedKnapsack* knapsack = new UnboundedKnapsack();
    int totalCapacity, elements_num, element;
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

    knapsack->knapsack_unbounded(elements_weight, elements_values, elements_num, totalCapacity);

    cout << "Maximum value: "
        << knapsack->getMaximumValue(totalCapacity)
        << endl;

    system("pause");

    return 0;
}