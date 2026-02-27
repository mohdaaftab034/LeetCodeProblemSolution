// LeetCode Link - "https://leetcode.com/problems/maximum-product-difference-between-two-pairs"


// Approach - 1
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int a = nums[n-1];
        int b = nums[n-2];
        int c = nums[0];
        int d = nums[1];

        return (a * b) - (c * d);
    }
};


// Approach - 2

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();

        int largest = INT_MIN;
        int sec_largest = INT_MIN;

        int smallest = INT_MAX;
        int sec_smallest = INT_MAX;

        for(int num : nums) {

            if(num > largest) {
                sec_largest = largest;
                largest = num;
            } else {
                sec_largest = max(sec_largest, num);
            }

            if(num < smallest) {
                sec_smallest = smallest;
                smallest = num;
            } else {
                sec_smallest = min(sec_smallest, num);
            }
        }

        return (largest * sec_largest) - (smallest * sec_smallest);
    }
};
