// LeetCode Link - "https://leetcode.com/problems/find-pivot-index/description"


// Approach - 1

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();

        vector<int>cumSum(n);
        cumSum[0] = nums[0];

        for(int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i-1] + nums[i];
        }

        int total_sum = cumSum[n-1];

        for(int i = 0; i < n; i++) {

            int left_sum = i == 0 ? 0 : cumSum[i-1];

            int right_sum = total_sum - left_sum - nums[i];

            if(left_sum == right_sum) {
                return i;
            }
        }

        return -1;
    }
};


// Approach - 2

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();

        int sum = 0;

        for(int &x : nums) {
            sum += x;
        }

        int cum_sum = 0;

        for(int i = 0; i < n; i++) {
            int left_sum = cum_sum;

            int right_sum = sum - cum_sum - nums[i];

            if(left_sum == right_sum) {
                return i;
            }

            cum_sum += nums[i];
        }

        return -1;
    }
};
