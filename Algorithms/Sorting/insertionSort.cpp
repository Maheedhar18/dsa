#include <vector>
#include <iostream>
using namespace std;

// Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time by repeatedly picking the next item and inserting it into its correct position among the already sorted items.
// Time complexity: O(n^2)
// Space complexity: O(1)

// Function to perform insertion sort on a vector of integers
void insertionSort(vector<int>& array) {
    int n = array.size();
    // Iterate through each element in the array
    for(int i = 0; i < n; i++) { 
        // Initialize j to the current index i
        int j = i; 
        // Shift elements of the sorted segment to find the correct position for array[i] and swap the elements 
        while(j > 0 && array[j] < array[j - 1]) {
            swap(array[j], array[j - 1]);
            j--; 
        }
    }
}


int main() {
    // Initialize a vector with some values
    vector<int> array = {3, 1, 6, 10, 12};

    // Call the insertionSort function to sort the array
    insertionSort(array);

    // Print the sorted array
    for (auto i : array) {
        cout << i << endl;
    }

    return 0;
}