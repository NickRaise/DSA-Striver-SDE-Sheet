// Frog Jump

// Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair.
// -> At a time the frog can climb either one or two steps. A height[N] array is also given.
// -> Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]).
// -> We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.

// Input:
// n = 4
// height = {10 20 30 10}
// Output:
// 20
// Explanation:
// Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost).
// Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost).
// so, total energy lost is 20 which is the minimum.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum energy required for the frog to reach the nth stone
int frogJump(int n, vector<int> &heights) {
    // Base case: If there is only one stone or no stone, no energy is needed
    if(n <= 1) return 0;

    // Variables to store the minimum energy needed to reach the previous stone and the stone before that
    int oneStepPrev = 0, twoStepPrev = 0;

    // Loop through each stone starting from the second stone (index 1)
    for(int i = 1; i < n; i++) {
        // Calculate the energy required to jump from the previous stone to the current stone
        int oneBack = oneStepPrev + abs(heights[i] - heights[i - 1]);

        // Initialize the energy required to jump from the stone before the previous stone to the current stone
        int twoBack = INT_MAX;
        if(i > 1) 
            twoBack = twoStepPrev + abs(heights[i] - heights[i - 2]);

        // The current energy is the minimum of the two possible jumps
        int curr = min(oneBack, twoBack);

        // Update the variables for the next iteration
        twoStepPrev = oneStepPrev;
        oneStepPrev = curr;
    }

    // The minimum energy needed to reach the nth stone is stored in oneStepPrev
    return oneStepPrev;
}

int main() {
    int n = 5; // Predefined number of stones
    vector<int> heights = {10, 30, 40, 20, 10}; // Predefined heights of the stones

    // Call the function and print the result
    int result = frogJump(n, heights);
    cout << "Minimum energy required for the frog to reach the " << n << "th stone: " << result << endl;

    return 0;
}
