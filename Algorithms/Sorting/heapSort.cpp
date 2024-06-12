#include <vector>
#include <iostream>
using namespace std;

// Heap sort is a sorting algorithm that organizes elements in an array into a max heap and then repeatedly extract the largest element (the root) from the heap, move it to the end of the array, and then heapify the remaining elements.
// Time complexity: O(nlogn) The process of building a heap from an unsorted array takes O(n) time. We extract the maximum element n times, and each extraction involves calling heapify, which takes O(log n) time. So total is O(nlogn)
// Space complexity: O(1)


// Function to heapify a subtree rooted with node 'index' which is an index in 'array'.
// 'boundary' is the size of the heap (or the boundary of the current heap).
void heapify(vector<int>& array, int boundary, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // If left child is larger than root
    if (left < boundary && array[left] > array[largest]) {
        largest = left;
    }
    // If right child is larger than largest so far
    if (right < boundary && array[right] > array[largest]) {
        largest = right;
    }
    // If largest is not root
    if (largest != index) {
        swap(array[index], array[largest]); // Swap root with the largest child

        // Recursively heapify the affected subtree
        heapify(array, boundary, largest);
    }
}

// Function to perform heap sort on a vector of integers
void heapSort(vector<int>& array) {
    int n = array.size();

    // Build a max-heap from the array
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(array[0], array[i]); // Move current root to end

        // Call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

int main() {
    // Initialize a vector with some values
    vector<int> array = {3, 1, 6, 10, 12};

    // Call the heap sort function to sort the array
    heapSort(array);

    // Print the sorted array
    for (auto i : array) {
        cout << i << endl;
    }

    return 0;
}