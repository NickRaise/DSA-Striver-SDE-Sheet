// Maximum Product Subarray in an Array

// Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

// Example 1:
// Input:
// Nums = [1,2,3,4,5,0]
// Output:
// 120
// Explanation:
// In the given array, we can see 1×2×3×4×5 gives maximum product value.

// Example 2:
// Input:
// Nums = [1,2,-3,0,-4,-5]
// Output:
// 20
// Explanation:
// In the given array, we can see (-4)×(-5) gives maximum product value.



#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum product of a subarray within a given array
int subarrayWithMaxProduct(vector<int> &arr) {
    int prefixPro = 1;  // Variable to store the product of elements from the start of the array
    int sufficPro = 1;  // Variable to store the product of elements from the end of the array
    int result = arr[0];  // Variable to store the maximum product found, initialized with the first element
    int n = arr.size();   // Size of the array

    for (int i = 0; i < n; i++) {
        // Reset the prefix product to 1 if it becomes 0, to start calculating a new product from the next element
        if (prefixPro == 0)
            prefixPro = 1;
        
        // Reset the suffix product to 1 if it becomes 0, to start calculating a new product from the next element
        if (sufficPro == 0)
            sufficPro = 1;

        prefixPro *= arr[i];          // Update prefix product by multiplying the current element
        sufficPro *= arr[n - i - 1];  // Update suffix product by multiplying the element from the end of the array

        // Update the 'result' with the maximum of itself, prefix product, and suffix product
        result = max(result, max(prefixPro, sufficPro));
    }

    return result;  // Return the maximum product found in any subarray
}

int main() {
    // Example usage of the function and testing
    vector<int> array = {2, 3, -2, 4}; // Sample array
    int maxProduct = subarrayWithMaxProduct(array); // Calculate the maximum product

    // Output the maximum product of a subarray within the given array
    cout << "Maximum product of a subarray: " << maxProduct << endl;

    return 0;
}
