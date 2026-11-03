class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        
        vector<int> length(n, 1); // length[i] stores the length of LIS ending at index i
        vector<int> count(n, 1);  // count[i] stores the number of LIS ending at index i
        
        int maxLength = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = count[j]; // Reset count to the path count of j
                    } else if (length[j] + 1 == length[i]) {
                        count[i] += count[j]; // Accumulate paths of the same length
                    }
                }
            }
            maxLength = max(maxLength, length[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (length[i] == maxLength) {
                ans += count[i];
            }
        }
        
        return ans;
    }
};
