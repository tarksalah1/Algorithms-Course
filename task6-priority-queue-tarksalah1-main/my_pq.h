#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int size2 = -1;
class PriorityQueue {
    // Function to return the index of the
    // parent node of a given node
public:

    int size() {
        return size2 + 1;
    }
    int parent(int i)
    {

        return (i - 1) / 2;
    }

    // Function to return the index of the
    // left child of the given node
    int leftChild(int i)
    {

        return ((2 * i) + 1);
    }

    // Function to return the index of the
    // right child of the given node
    int rightChild(int i)
    {

        return ((2 * i) + 2);
    }

    // Function to shift up the node in order
    // to maintain the heap property
    void shiftUp(int i)
    {
        while (i > 0 && H[parent(i)] < H[i]) {

            // Swap parent and current node
            swap(H[parent(i)], H[i]);

            // Update i to parent of i
            i = parent(i);
        }
    }

    // Function to shift down the node in
    // order to maintain the heap property
    void shiftDown(int i)
    {
        int maxIndex = i;

        // Left Child
        int l = leftChild(i);

        if (l <= size2 && H[l] > H[maxIndex]) {
            maxIndex = l;
        }

        // Right Child
        int r = rightChild(i);

        if (r <= size2 && H[r] > H[maxIndex]) {
            maxIndex = r;
        }

        // If i not same as maxIndex
        if (i != maxIndex) {
            swap(H[i], H[maxIndex]);
            shiftDown(maxIndex);
        }
    }

    // Function to insert a new element
    // in the Binary Heap
    void insert(int p)
    {
        size2 = size2 + 1;
        H[size2] = p;

        // Shift Up to maintain heap property
        shiftUp(size2);
    }

    // Function to extract the element with
    // maximum priority
    int extractMax()
    {
        int result = H[0];

        // Replace the value at the root
        // with the last leaf
        H[0] = H[size2];
        size2 = size2 - 1;

        // Shift down the replaced element
        // to maintain the heap property
        shiftDown(0);
        return result;
    }

    void extractMax2()
    {
        sort(H, H + size2 + 1);
        for (int i = size2;i >= 0;i--) {
            cout << H[i] << " ";
        }
    }

    // Function to change the priority
    // of an element
    void changePriority(int i, int p)
    {
        int oldp = H[i];
        H[i] = p;

        if (p > oldp) {
            shiftUp(i);
        }
        else {
            shiftDown(i);
        }
    }

    // Function to get value of the current
    // maximum element
    int getMax()
    {

        return H[0];
    }

    // Function to remove the element
    // located at given index
    void remove(int i)
    {
        H[i] = getMax() + 1;

        // Shift the node to the root
        // of the heap
        shiftUp(i);

        // Extract the node
        extractMax();
    }
};
