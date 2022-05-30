#include <iostream>
#include <chrono>
#include <random>
#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
void quickSort(int arr[], int low, int high);
void introsort(int a[], int* begin, int* end, int maxdepth);
void printArray(int arr[], int n);
bool isEqual(int arr1[], int arr2[], int n);

int main(int argc, char** argv)
{

    int array1[] = { 5,9,4,5,2,1,6,10,12,15,16 };
    int array2[] = { 5,9,4,5,2,1,6,10,12,15,16 };
    int sorted_array[] = { 5,9,4,5,2,1,6,10,12,15,16 };
    int size = sizeof(array1);
    int n = size / sizeof(array1[0]);
    sort(sorted_array, sorted_array + n);
    while (true)
    {

        auto quick_start = std::chrono::high_resolution_clock::now();

        quickSort(array1, 0, n - 1);

        auto quick_finish = std::chrono::high_resolution_clock::now();

        auto intro_start = std::chrono::high_resolution_clock::now();

        // assign the proper value for max_depth 
        int maxdepth = log(n) * 2;

        introsort(array2, array2, array2 + n - 1, maxdepth);

        auto intro_finish = std::chrono::high_resolution_clock::now();

        auto quick_time = (quick_finish - quick_start).count();
        auto intro_time = (intro_finish - intro_start).count();

        if (isEqual(array1,sorted_array,n) && isEqual(array2, sorted_array, n))
        {
            cout << "equivalent result ";
            cout << "quick_time ==> " << quick_time;
            cout << "intro_time ==> " << intro_time;
            cout << "performance enhancment ==>" << quick_time / intro_time << endl;
        }
        else
        {
            cout << "error, check your inputs and algortihms " << endl;
            // you may want to store your variables in a file to re-run the test on the same inputs;
            break;
        }
    }
    return 0;
}


// Function to perform insertion sort on subarray `a[low…high]`
void insertionsort(int a[], int low, int high)
{
    // start from the second element in the subarray
    // (the element at index `low` is already sorted)
    for (int i = low + 1; i <= high; i++)
    {
        int value = a[i];
        int j = i;

        // find index `j` within the sorted subset a[0…i-1]
        // where element a[i] belongs
        while (j > low && a[j - 1] > value)
        {
            a[j] = a[j - 1];
            j--;
        }

        // Note that the subarray `a[j…i-1]` is shifted to
        // the right by one position, i.e., `a[j+1…i]`

        a[j] = value;
    }
}

// Function to partition the array using Lomuto partition scheme
int partition(int a[], int low, int high)
{
    // Pick the rightmost element as a pivot from the array
    int pivot = a[high];

    // elements less than the pivot will be pushed to the left of `pIndex`
    // elements more than the pivot will be pushed to the right of `pIndex`
    // equal elements can go either way
    int pIndex = low;

    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    // swap `pIndex` with pivot
    swap(a[pIndex], a[high]);

    // return `pIndex` (index of the pivot element)
    return pIndex;
}

// Quicksort randomized partition to rearrange elements across pivot
int randPartition(int a[], int low, int high)
{
    // choose a random index between `[low, high]`
    int pivotIndex = rand() % (high - low + 1) + low;

    // swap the end element with the element present at a random index
    swap(a[pivotIndex], a[high]);

    // call the partition procedure
    return partition(a, low, high);
}

// Function to perform heapsort on the given range of elements
void heapsort(int* begin, int* end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}

// Function to perform introsort on the given array
void introsort(int a[], int* begin, int* end, int maxdepth)
{
    // perform insertion sort if partition size is 16 or smaller
    if ((end - begin) < 16) {
        insertionsort(a, begin - a, end - a);
    }
    // perform heapsort if the maximum depth is 0
    else if (maxdepth == 0) {
        heapsort(begin, end + 1);
    }
    else {
        // otherwise, perform Quicksort
        int pivot = randPartition(a, begin - a, end - a);
        introsort(a, begin, a + pivot - 1, maxdepth - 1);
        introsort(a, a + pivot + 1, end, maxdepth - 1);
    }
}

void swap2(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition2(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot 
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element 
            swap2(&arr[i], &arr[j]);
        }
    }
    swap2(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition2(arr, low, high);

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

bool isEqual(int arr1[], int arr2[],int n) {
    for (int i = 0;i < n;i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}