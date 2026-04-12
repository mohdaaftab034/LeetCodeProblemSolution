// Leetcode - https://leetcode.com/problems/max-consecutive-ones-iii/description/?utm=codolio




// --------------------Solution -> 1---------------------
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right = 0, left = 0, zeros = 0, maxLength = 0;

        while(right < nums.size()) {
            if(nums[right] == 0) zeros++;

            while(zeros > k) {
                if(nums[left] == 0) {
                    zeros--;
                }

                left++;
            }

            if(zeros <= k) {
                int length = right - left + 1;
                maxLength = max(length, maxLength);
            }
            right++;
        }

        return maxLength;
        
    }
};


// -----------------------Solution --> 2------------------------
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right = 0, left = 0, zeros = 0, maxLength = 0;

        while(right < nums.size()) {
            if(nums[right] == 0) zeros++;

            if(zeros > k) {
                if(nums[left] == 0) zeros--;
                left++;
            }

            if(zeros <= k) {
                int length = right - left + 1;
                maxLength = max(length, maxLength);
            }
            right++;
        }

        return maxLength;
        
    }
};
