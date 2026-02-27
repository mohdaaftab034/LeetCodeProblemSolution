// LeetCode Link - "https://leetcode.com/problems/jump-game/description"
// Topic - Dynamic Programming

// Approach - 1 (Top Down Approach)
class Solution {
public:

    int memo[10001];
    bool solve(vector<int>& nums, int n, int idx) {
        if(idx == n-1) {
            return true;
        }

        if(memo[idx] != -1) {
            return memo[idx];
        }

        for(int i = 1; i <= nums[idx]; i++) {
            if(solve(nums, n, idx + i) == true) {
                return memo[idx] = true;
            }
        }

        return memo[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(memo, -1, sizeof(memo));

        return solve(nums, n, 0);
    }
};

// Approach - 2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> t(n, false);

        // t[i] = true : means, mai i tak pahuch sakta hu
        // t[i] = false : means, nhi pahuch sakta hu
        t[0] = true;
    
        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--){

                if(t[j] == true && j + nums[j] >= i) {
                    t[i] = true;
                    break;
                }
            }
        }
        return t[n-1];
    }
};
