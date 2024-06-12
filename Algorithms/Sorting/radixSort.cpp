#include <vector>
#include <iostream>
using namespace std;

// Radix sort is a non-comparative sorting algorithm that processes integers by sorting them digit by digit, starting from the least significant digit to the most significant digit, using a stable sorting method like counting sort or bucket sort for each digit.
// Time complexity: O(d*(n+b)) where d is maximum number of digits, n is length of array and b is bucket size
// Space complexity: O(n+b) 

// Function to perform bucket sort on a vector of integers based on a specific decimal place
void bucketSort(vector<int>& array, int decimalPlace) {
    // Create 10 empty buckets (one for each digit 0-9)
    vector<vector<int>> buckets(10, vector<int>());
    
    // Distribute array elements into buckets based on the current digit
    for(auto i : array) {
        int digit = (i / decimalPlace) % 10; // Extract the current digit
        buckets[digit].push_back(i); // Place the element in the corresponding bucket
    }
    
    // Collect the elements from the buckets and put them back into the array
    int index = 0;
    for (int i = 0; i < buckets.size(); i++) {
        for (auto value : buckets[i]) {
            array[index] = value;
            index++;
        }
    }
}

// Function to perform Radix sort on a vector of integers
void radixSort(vector<int>& array) {
    int n = array.size();

    // Find the maximum element in the array to determine the number of digits
    int maxElement = INT_MIN;
    for(auto i : array) {
        maxElement = max(maxElement, i);
    }

    // Determine the number of digits in the maximum element
    int numberOfDigits = 0;
    while(maxElement != 0) {
        maxElement /= 10;
        numberOfDigits++;
    }

    // Perform bucket sort for each digit position
    int decimalPlace = 1;
    for(int i = 0; i < numberOfDigits; i++) {
        bucketSort(array, decimalPlace);
        decimalPlace *= 10; // Move to the next decimal place
    }
}


int main() {
    // Initialize a vector with some values
    vector<int> array = {3, 1, 6, 10, 12};

    // Call the Radix Sort function to sort the array
    radixSort(array);

    // Print the sorted array
    for (auto i : array) {
        cout << i << endl;
    }

    return 0;
}