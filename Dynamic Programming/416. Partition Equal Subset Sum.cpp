// Leetcode - https://leetcode.com/problems/partition-equal-subset-sum/description/?utm=codolio


// Solution --- > Recursion + Memoization

class Solution {
public:
    int dp[201][20001];
    bool solve(vector<int>& nums, int sum, int idx) {
        if(sum == 0) return true;

        if(idx >= nums.size()) return false;

        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }

        bool take = false;
        if(sum >= nums[idx]){
            take = solve(nums, sum - nums[idx], idx + 1);
        }
        bool notTake = solve(nums, sum, idx + 1);
        
        return dp[idx][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum % 2 != 0) {
            return false;
        }

        memset(dp, -1, sizeof(dp));
        return solve(nums, sum / 2, 0);
    }
};
