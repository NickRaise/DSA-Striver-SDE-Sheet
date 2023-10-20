#include <bits/stdc++.h>
using namespace std;

int print2largest(int arr[], int n) {
    int max = arr[0];
    int secondMax = -1;
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            secondMax = max;
            max = arr[i];
        }
        else if(arr[i] > secondMax && arr[i] < max) {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int ans = print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
