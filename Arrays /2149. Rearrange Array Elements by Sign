// Leetcode Link - https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?utm=codolio


// Solution --->

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        int posIndex = 0; // Even Index
        int negIndex = 1; // Odd Index

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                result[posIndex] = nums[i];
                posIndex += 2;
            } else {
                result[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return result;
    }
};
