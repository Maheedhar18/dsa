#include <vector>
#include <iostream>
using namespace std;

// Merge Sort is a divide-and-conquer sorting algorithm. The intuition behind it is to divide the data set into smaller and smaller sub-arrays until it is easy to sort, and then merge the sorted sub-arrays back into a larger sorted array.
// Time complexity: O(nlogn) While sorting, we divide the arr array into two halves till there is only one element in the array, which will lead to O(logn) steps. After each division, we merge those respective halves which will take O(n)O(n)O(n) time each. Thus, sorting will take O(nlogn) time.
// Space complexity: O(n) The recursive call stack space is O(logn) but the space required for temporary Arrays is O(n).

// Function to merge two subarrays of array[].
// First subarray is array[left..mid]
// Second subarray is array[mid+1..right]
void merge(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the first subarray
    int n2 = right - mid;    // Size of the second subarray

    // Create temporary arrays
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    // Merge the temporary arrays back into array[left..right]
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to implement merge sort on array[left..right]
void mergeSort(vector<int>& array, int left, int right) {
    if (left >= right) return; // Base case: If the array has 1 or 0 elements, it is already sorted

    int mid = left + (right - left) / 2; // Find the middle point to divide the array into two halves

    // Recursively sort the first and second halves
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);

    // Merge the sorted halves
    merge(array, left, mid, right);
}

int main() {
    // Initialize a vector with some values
    vector<int> array = {3, 1, 6, 10, 12};

    int n = array.size();

    // Call the mergeSort function to sort the array
    mergeSort(array, 0, n - 1);

    // Print the sorted array
    for (auto i : array) {
        cout << i << endl;
    }

    return 0;
}
