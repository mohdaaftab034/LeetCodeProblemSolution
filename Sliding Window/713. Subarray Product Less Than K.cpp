// LeetCode Link - "https://leetcode.com/problems/subarray-product-less-than-k/description"


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // edge case

        int n = nums.size();
        int count = 0;
        int prod = 1;
        int i = 0;

        for (int j = 0; j < n; j++) {
            prod *= nums[j];

            while (prod >= k) {
                prod /= nums[i];
                i++;
            }

            count += j - i + 1; // number of subarrays ending at j
        }

        return count;
    }
};
