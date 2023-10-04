// Find the Majority Element that occurs more than N/2 times
// Problem Statement: Given an array of N integers, write a program to return an element 
// that occurs more than N/2 times in the given array. 
// You may consider that such an element always exists in the array.

// Example 1:
// Input Format: N = 3, nums[] = {3,2,3}
// Result: 3
// Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution. 

// Example 2:
// Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}
// Result: 2


#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> v) {
    int count = 0; // Initialize a count variable to keep track of the majority element's count
    int ele = v[0]; // Initialize ele as the first element
    for (int i = 0; i < v.size(); i++) {
        if (ele == v[i]) {
            count++; // If the current element is the same as ele, increment the count
        } else {
            if (count > 0) {
                count--; // If the current element is different and count is positive, decrement the count
            } else {
                ele = v[i]; // If count becomes zero, update ele to the current element and reset count
                count++;
            }
        }
    }

    return ele; // Return the majority element
}

int main() {
    vector<int> v = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    
    int result = majorityElement(v);
    
    cout << "Majority Element in the vector: " << result << endl;

    return 0;
}
