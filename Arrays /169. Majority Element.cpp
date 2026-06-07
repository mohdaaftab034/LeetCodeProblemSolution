// Problem - https://leetcode.com/problems/majority-element/description/?utm=codolio




// -----------------Solution------------------
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        int maj = nums[0];

        for (int i = 1; i < n; i++) {

            if(count == 0) {
                maj = nums[i];
                count = 1;
            } else if(maj == nums[i]) {
                count++;
            } else {
                count--;
            }
        }

        return maj;
    }
};
