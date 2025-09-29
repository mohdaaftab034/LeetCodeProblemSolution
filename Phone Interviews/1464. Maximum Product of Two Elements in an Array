// LeetCode Link - "https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array"


// Approach - 1 ---> 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int curr_max = nums[0];
        int result = 0;

        for(int i = 1; i < n; i++) {
            result = max(result, (nums[i]-1) * (curr_max - 1));

            curr_max = max(curr_max, nums[i]);
        }

        return result;
    }
};


// Approach - 2 --->
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int first = 0, second = 0;
        
        for(int x : nums) {
            if(x > first) {
                second = first;
                first = x;
            } else if(x > second) {
                second = x;
            }
        }
        
        return (first - 1) * (second - 1);
    }
};


// Approach - 3 --->
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int largest = 0;
        int sec_largest = 0;

        for(int &num : nums) {
            if(num > largest) {
                sec_largest = largest;
                largest = num;
            } else {
                sec_largest = max(sec_largest, num);
            }
        }

        return (largest - 1) * (sec_largest - 1);
    }
};
