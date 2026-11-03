class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = 0;
        
        // Find the index of the maximum element
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        
        // Verify if the maximum element is at least twice as large as every other element
        for (int i = 0; i < nums.size(); ++i) {
            if (i != maxIndex && nums[maxIndex] < 2 * nums[i]) {
                return -1;
            }
        }
        
        return maxIndex;
    }
};