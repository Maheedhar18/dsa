#include <vector>
#include <iostream>
using namespace std;

// Bucket sort is a comparison-based sorting algorithm that distributes elements into several 'buckets.' Each bucket is then sorted individually, either using a different sorting algorithm or by recursively applying the bucket sort algorithm. The final result is obtained by concatenating the sorted buckets.
// Time Compelexity : Average-O(n+k), Worst-O(n^2)
// Space Complexity : O(n+k) where n = number of elements in the array, and k = number of buckets formed Space taken by each bucket is O(k), and inside each bucket, we have n elements scattered

// Function to perform bucket sort
void bucketSort(vector<float>& array) {
    int n=array.size();
    vector<vector<float>> buckets(n, vector<float>());
    
    // Distribute array elements into buckets
    for(auto i : array) {
        int index=i*10;
        buckets[index].push_back(i);
    }
    
    // use any sorting algorithm to sort elements in the buckets
    for(int i=0;i<n;i++) {
        sort(buckets[i].begin(), buckets[i].end());
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


int main() {
    // Initialize a vector with some values
    vector<float> array = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    // Call the bucket Sort function to sort the array
    bucketSort(array);

    // Print the sorted array
    for (auto i : array) {
        cout << i << endl;
    }

    return 0;
}