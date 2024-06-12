#include <vector>
#include <map>
#include <iostream>
using namespace std;

// The intuition behind counting sort is to count the frequency of each element in the input array and then place the elements in their correct positions based on their values and frequencies. 
// Counting sort is a non-comparative sorting algorithm and is useful in situations where the elements in the array have a limited range.
// Time complexity: O(n + k) where n is the number of elements in the array and k is the range of the input (i.e., the difference between the maximum and minimum element values).
// Space complexity: O(n+k)

// Function to perform counting sort on a vector of integers
void countingSort(vector<int>& array) {
    int n = array.size();  // Get the size of the array

    unordered_map<int, int> frequency;  // HashMap to store the frequency of elements
    int maxValue = INT_MIN, minValue = INT_MAX;  // Initialize max and min values

    // Calculate the frequency of each element and find the min and max values
    for (auto i : array) {
        frequency[i]++;
        maxValue = max(i, maxValue);
        minValue = min(i, minValue);
    }

    int index = 0;  // Index to place the sorted elements back into the array

    // Iterate from minValue to maxValue to place the elements in sorted order
    for (int i = minValue; i <= maxValue; i++) {
        while (frequency[i] > 0) {
            array[index] = i;  // Place the element in the array
            index++;  // Move to the next index
            frequency[i]--;  // Decrease the frequency
        }
    }
}


int main() {
    // Initialize a vector with some values
    vector<int> array = {3, 1, 6, 10, 12};

    // Call the counting sort function to sort the array
    countingSort(array);

    // Print the sorted array
    for (auto i : array) {
        cout << i << endl;
    }

    return 0;
}