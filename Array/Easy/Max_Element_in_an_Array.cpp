#include <bits/stdc++.h> 
using namespace std;

int largestElement(vector<int> &arr, int n) {
    int max = INT_MIN;
    for(auto it: arr) {
        if(it > max) {
            max = it;
        }
    }
    return max;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int maxElement = largestElement(arr, n);
    
    cout << "The largest element in the vector is: " << maxElement << endl;
    
    return 0;
}
