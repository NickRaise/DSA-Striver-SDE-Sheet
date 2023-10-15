// Majority Elements(>N/3 times)  
// Find the elements that appears more than N/3 times in the array

// Problem Statement: Given an array of N integers. 
// Find the elements that appear more than N/3 times in the array. 
// If no such element exists, return an empty vector.


// Example 1:
// Input Format: N = 5, array[] = {1,2,2,3,2}
// Result: 2
// Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.
// Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.




#include <iostream>
#include <vector>

using namespace std;

// Function to find majority elements in the given vector
vector<int> majorityElement(vector<int> v) {
    int ele1 = -1, ele2 = -1;  // Initialize two potential majority elements
    int cnt1 = 0, cnt2 = 0;   // Initialize their respective counts
    int n = v.size();         // Get the size of the input vector

    // Step 1: Find the potential majority elements
    for (int i = 0; i < n; i++) {
        // If cnt1 is 0 and ele2 is not equal to the current element, update ele1
        if (cnt1 == 0 && ele2 != v[i]) {
            ele1 = v[i];
            cnt1 = 1;
        }
        // If cnt2 is 0 and ele1 is not equal to the current element, update ele2
        else if (cnt2 == 0 && ele1 != v[i]) {
            ele2 = v[i];
            cnt2 = 1;
        }
        // If the current element is equal to ele1, increment cnt1
        else if (ele1 == v[i]) {
            cnt1++;
        }
        // If the current element is equal to ele2, increment cnt2
        else if (ele2 == v[i]) {
            cnt2++;
        }
        // If the current element is different from both, decrement counts
        else {
            cnt1--;
            cnt2--;
        }
    }

    // Step 2: Recount and verify the majority elements
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == ele1)
            cnt1++;
        else if (v[i] == ele2)
            cnt2++;
    }

    vector<int> result;  // Create a vector to store the majority elements

    // Check if ele1 and ele2 are majority elements based on counts
    if (cnt1 > n / 3 && cnt2 > n / 3) {
        result.push_back(ele1);
        result.push_back(ele2);
    } else if (cnt1 > n / 3) {
        result.push_back(ele1);
    } else if (cnt2 > n / 3) {
        result.push_back(ele2);
    }
    else {

    }

    return result;
}

int main() {
    vector<int> input = {3, 3, 3, 1, 2, 2, 2};
    
    // Find the majority elements in the input vector
    vector<int> result = majorityElement(input);

    // Print the majority elements (if any)
    cout << "Majority Elements: ";
    for (int element : result) {
        cout << element << " ";
    }

    return 0;
}
