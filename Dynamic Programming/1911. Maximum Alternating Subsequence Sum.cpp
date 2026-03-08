// LeetCode Link - https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/?utm=codolio


// -------------------Solution ---> top-down --> Recursion + Memoization-----------------------------
class Solution {
public:

    long long solve(int idx, vector<int>& nums, bool flag, int n, vector<vector<long long>>& dp) {
        if(idx >= n) {
            return 0;
        }

        // STEP - 3
        if(dp[idx][flag] != -1) {
            return dp[idx][flag];
        } 

        long long skip = solve(idx + 1, nums, flag, n, dp);
        
        long long val = nums[idx];
        if(flag == false) {
            val = -val;
        }

        long long take = solve(idx + 1, nums, !flag, n, dp) + val;

        // STEP - 2
        return dp[idx][flag] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // STEP - 1
        vector<vector<long long>> dp(n, vector<long long> (2, -1));

        return solve(0, nums, true, n, dp);
    }
};
