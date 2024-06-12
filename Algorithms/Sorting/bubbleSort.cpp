#include <vector>
#include <iostream>
using namespace std;

// Bubble Sort operates by repeatedly stepping through the list, comparing adjacent elements, and swapping them if they are in the wrong order. 
// The pass through the list is repeated until the list is sorted.
// Time complexity: O(n^2)
// Space complexity: O(1)

// Function to perform bubble sort on a vector of integers
void bubbleSort(vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n; i++) { // Loop through the size of the array
        for (int j = 0; j < n - i - 1; j++) { // Loop through the array up to the unsorted portion
            // If the current element is greater than the next element, swap them
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main() {
    // Initialize a vector with some values
    vector<int> array = {3, 1, 6, 10, 12};

    // Call the bubbleSort function to sort the array
    bubbleSort(array);

    // Print the sorted array
    for (auto i : array) {
        cout << i << endl;
    }

    return 0;
}