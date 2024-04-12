// Allocate Minimum Number of Pages

// Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. 
// There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:

// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

// Input Format:
//  n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
// Result:
//  71
// Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.


#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to assign 'students' students to read 'books' books
// with each student reading at most 'pages' pages
bool isPossible(vector<int>& arr, int books, int students, int pages) {
    int cntStudent = 0; // Counter for the number of students
    int sum = 0; // Variable to track the total number of pages read by a student
    for(int i=0; i<books; i++) {
        if(sum + arr[i] > pages) {
            cntStudent++; // Increment the number of students
            sum = arr[i]; // Start counting pages for a new student
        } 
        else
            sum += arr[i]; // Accumulate the pages for the current student
    }
    if(sum != 0) cntStudent++; // If there are remaining pages, consider one more student
    
    // If the number of students required is less than or equal to the given number of students,
    // return true; otherwise, return false
    if(cntStudent <= students) return true;
    return false;
}

// Function to find the minimum number of pages that each student must read such that
// each student is assigned at least one book and the maximum number of pages assigned to a student
// is minimized
int findPages(vector<int>& arr, int n, int m) {
    int left = *max_element(arr.begin(), arr.end()); // Minimum possible number of pages
    int right = accumulate(arr.begin(), arr.end(), 0); // Maximum possible number of pages
    int mid, ans = -1; // Initialize the result to -1
    if(m > n) return -1; // If the number of students is greater than the number of books, return -1
    
    // Binary search to find the minimum number of pages
    while(left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle value
        // If it is possible to assign 'm' students to read books with each student reading at most 'mid' pages
        if(isPossible(arr, n, m, mid)) {
            ans = mid; // Update the answer to the current value of 'mid'
            right = mid - 1; // Move to the left half of the search space
        }
        else
            left = mid + 1; // Otherwise, move to the right half of the search space
    }

    return ans; // Return the minimum number of pages
}
