#include <vector>
#include <iostream>
using namespace std;

// Selection sort is a sorting algorithm that repeatedly finds the minimum element from the unsorted portion of the list and swaps it with the first unsorted element, moving the boundary of the sorted portion one element to the right each time.
// Time complexity: O(n^2)
// Space complexity: O(1)

// Function to perform selection sort on a vector of integers
void selectionSort(vector<int>& array) {
    int n = array.size();
    // Loop over each element in the array
    for(int i=0;i<n-1;i++) {
        // Assume the current element is the minimum
        int currentMinimumIndex=i;
        // Loop over the remaining elements to find the true minimum
        for(int j=i+1;j<n;j++) {
            if(array[currentMinimumIndex]>array[j]) {
                currentMinimumIndex=j;
            }
        }
        // If the minimum element is not the current element, swap them
        if(currentMinimumIndex!=i) {
            swap(array[currentMinimumIndex], array[i]);
        }
    }
}

int main() {
    // Initialize a vector with some values
    vector<int> array = {3, 1, 6, 10, 12};

    // Call the selectionSort function to sort the array
    selectionSort(array);

    // Print the sorted array
    for (auto i : array) {
        cout << i << endl;
    }

    return 0;
}