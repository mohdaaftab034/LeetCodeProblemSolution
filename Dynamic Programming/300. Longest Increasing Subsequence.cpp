// LeetCode Link - https://leetcode.com/problems/longest-increasing-subsequence/description/?utm=codolio


// --------------Recursion + Memoization---------------
class Solution {
public:

    int solve(vector<int>& nums, int i, int prev, int n, vector<vector<int>>& dp) {
        if(i >= n) return 0;

        // Shift prev by +1
        if(dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(nums, i + 1, i, n, dp);
        }

        int not_take = solve(nums, i + 1, prev, n, dp);

        return dp[i][prev + 1] = max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // prev can be -1 → so size n+1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(nums, 0, -1, n, dp);
    }
};



// ---------------Bottom-up Approach ----> Tabulation Method----------------
