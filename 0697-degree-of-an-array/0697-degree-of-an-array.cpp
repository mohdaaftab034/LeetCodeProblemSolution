class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;       // Frequency of each element
        unordered_map<int, int> first_seen;  // First occurrence index of each element
        int degree = 0;
        int min_length = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (first_seen.find(nums[i]) == first_seen.end()) {
                first_seen[nums[i]] = i;
            }
            count[nums[i]]++;
            
            if (count[nums[i]] > degree) {
                degree = count[nums[i]];
                min_length = i - first_seen[nums[i]] + 1;
            } else if (count[nums[i]] == degree) {
                min_length = min(min_length, i - first_seen[nums[i]] + 1);
            }
        }
        
        return min_length;
    }
};