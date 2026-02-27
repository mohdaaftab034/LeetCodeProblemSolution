// LeetCode Link - "https://leetcode.com/problems/coin-change/description"


// Top-Down Approach ---> Recersion + Memoization
class Solution {
public:

    int solveRec(vector<int>& coins, int X, vector<int>& dp) {
        // BASE CASE
        if(X == 0) {
            return 0;
        }

        if(X < 0) {
            return INT_MAX;
        }
        // STEP - 3
        if(dp[X] != -1) {
            return dp[X];
        }

        int mini = INT_MAX;

        for(int i = 0; i < coins.size(); i++) {
            int ans = solveRec(coins, X - coins[i], dp);
            if(ans != INT_MAX) {
                mini = min(mini, ans + 1);
            }
        }
        // STEP - 2
        dp[X] = mini;
        return mini;
    }

    int coinChange(vector<int>& coins, int amount) {

        // STEP - 1
        vector<int> dp(amount+1, -1);

        int ans = solveRec(coins, amount, dp);

        if(ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};


// Bottom-Up Approach ---> Tabulatio method
class Solution {
public:

    int solveByTab(vector<int>& coins, int x) {
        vector<int> dp(x+1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= x; i++) {
            // I'm trying to solve for every element from 1 to x
            for(int j = 0; j < coins.size(); j++) {
                // I'm trying to iterate every coins in the array
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if(dp[x] == INT_MAX) {
            return -1;
        }

        return dp[x];
    }

    int coinChange(vector<int>& coins, int amount) {
        return solveByTab(coins, amount);
    }
};
