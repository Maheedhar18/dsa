#include <vector>
#include <iostream>
using namespace std;

// QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.
// Time complexity: O(n^2) This occurs when the pivot element is the smallest or largest element in the array, leading to highly unbalanced partitions and The depth of the recursion tree becomes n. At each level of the recursion tree, the partitioning step involves scanning all elements of the sub-array, which takes linear time O(n).
// Space complexity: O(n) due to recursive stack space

// Function to partition the array based on the pivot element
int partition(std::vector<int>& array, int low, int high) {
    int pivot = array[high]; // Choose the pivot element it can be anything like start, mid, end, random element of array slice
    int index = low; // Index of the start of array slice

    // Traverse through all elements, compare each element with the pivot
    for (int i = low; i < high; i++) {
        // If the current element is smaller or equal to the pivot then swap elements
        if (array[i] <= pivot) { 
            swap(array[index], array[i]); 
            index++; 
        }
    }
    // Swap the pivot element with the element at the index
    swap(array[index], array[high]); 
    return index;
}

// Function to perform quicksort on a vector of integers
void quickSort(std::vector<int>& array, int low, int high) {
    if (low < high) { 
        // Get the partition index
        int partitionIndex = partition(array, low, high); 
        // Recursively sort the elements before and after partition index
        quickSort(array, low, partitionIndex - 1); 
        quickSort(array, partitionIndex + 1, high); 
    }
}

int main() {
    // Initialize a vector with some values
    vector<int> array = {3, 1, 6, 10, 12};
    int n=array.size();
    // Call the quick sort function to sort the array
    quickSort(array, 0, n-1);

    // Print the sorted array
    for (auto i : array) {
        cout << i << endl;
    }

    return 0;
}