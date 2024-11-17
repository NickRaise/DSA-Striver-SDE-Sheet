// Ninja’s Training

// Ninja is planning a training schedule for N days. Each day, he can choose one of three activities: Running, Fighting Practice, or Learning New Moves. 
// Each activity has associated merit points for each day. Ninja cannot repeat the same activity on consecutive days.

// Given a 2D array POINTS of size N x 3, where POINTS[i][j] represents the merit points for the j-th activity on the i-th day, find the maximum merit points Ninja can earn.

// For POINTS = [[1, 2, 5], [3, 1, 1], [3, 3, 3]], the maximum merit points Ninja can earn is 11 by choosing activities with merit points 5 (Day 1) + 3 (Day 2) + 3 (Day 3).


#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points) {
    if (n == 0) return 0; // If there are no days, return 0

    // dp[i] represents the maximum points earned up to the previous day with task i performed
    vector<int> dp(3, -1);

    // Initialize dp for the first day
    // For task 0 on the first day, the maximum points are the maximum of task 1 and task 2
    dp[0] = max(points[0][1], points[0][2]);
    // For task 1 on the first day, the maximum points are the maximum of task 0 and task 2
    dp[1] = max(points[0][0], points[0][2]);
    // For task 2 on the first day, the maximum points are the maximum of task 0 and task 1
    dp[2] = max(points[0][0], points[0][1]);

    // Fill dp for subsequent days
    for (int day = 1; day < n; day++) {
        // temp vector to store maximum points for the current day
        vector<int> temp(3, -1);
        for (int prevTask = 0; prevTask < 3; prevTask++) {
            // Initialize maxCredits for the current day and task
            int maxCredits = 0;
            for (int task = 0; task < 3; task++) {
                // Ensure the current task is different from the previous day's task
                if (task != prevTask) {
                    // Calculate the merit for performing the current task
                    int merit = points[day][task] + dp[task];
                    // Update maxCredits with the maximum merit
                    maxCredits = max(maxCredits, merit);
                }
            }
            // Store the maximum credits in the temp array for the current day and task
            temp[prevTask] = maxCredits;
        }
        // Update dp with temp for the next day's calculations
        dp = temp;
    }

    // Return the maximum points possible on the last day by considering all possible tasks
    return max({dp[0], dp[1], dp[2]});
}

int main() {
    int n = 3; // Number of days
    vector<vector<int>> points = {
        {1, 2, 5}, // Points for tasks on day 1
        {3, 1, 1}, // Points for tasks on day 2
        {3, 3, 3}  // Points for tasks on day 3
    };

    // Call the function and print the result
    int result = ninjaTraining(n, points);
    cout << "Maximum points the ninja can earn: " << result << endl;

    return 0;
}
