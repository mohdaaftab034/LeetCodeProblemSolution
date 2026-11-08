class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        // Calculate suffix minimum
        for(int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        int prefixMax = nums[0];
        int sum = 0;

        for(int i = 1; i < n - 1; i++) {

            // Condition 1
            if(prefixMax < nums[i] && nums[i] < suffixMin[i + 1]) {
                sum += 2;
            }

            // Condition 2
            else if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                sum += 1;
            }

            prefixMax = max(prefixMax, nums[i]);
        }

        return sum;
    }
};