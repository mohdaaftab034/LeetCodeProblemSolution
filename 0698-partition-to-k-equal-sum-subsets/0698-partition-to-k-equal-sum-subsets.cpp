
class Solution {
public:
    bool solve(int idx, vector<int>& nums, vector<int>& bucket, int target, int k) {

        // All elements are assigned
        if (idx == nums.size()) {
            return true;
        }

        for (int i = 0; i < k; i++) {

            // Skip duplicate bucket states
            if (i > 0 && bucket[i] == bucket[i - 1]) {
                continue;
            }

            // Check whether current number fits
            if (bucket[i] + nums[idx] <= target) {

                bucket[i] += nums[idx];

                if (solve(idx + 1, nums, bucket, target, k)) {
                    return true;
                }

                // Backtrack
                bucket[i] -= nums[idx];
            }

            // Empty bucket failed, no need to try other empty buckets
            if (bucket[i] == 0) {
                break;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % k != 0) {
            return false;
        }

        int target = totalSum / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) {
            return false;
        }

        vector<int> bucket(k, 0);

        return solve(0, nums, bucket, target, k);
    }
};
