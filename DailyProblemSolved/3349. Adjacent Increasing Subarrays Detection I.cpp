// LeetCode Link - "https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14"


// Brute Force Approach - >

class Solution {
public:

    bool isIncreasing(vector<int>& nums, int i, int j) {
        for(int k = i; k < j; k++) {
            if(nums[k] >= nums[k+1]) {
                return false;
            }
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int start = 0; start + 2*k - 1 < n; start++) {
            if(isIncreasing(nums, start, start+k-1) && isIncreasing(nums, start + k, start + 2*k-1)) {
                return true;
            }
        }

        return false;
    }
};



// Approach - 2 ---> Optimal Approach
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;

        int maxResult = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                currRun++;
            } else {
                prevRun = currRun;
                currRun = 1;
            }

            if(currRun >= 2*k) {
                return true;
            }

            if(min(currRun, prevRun) >= k) {
                return true;
            }
        }

        return false;
    }
};
