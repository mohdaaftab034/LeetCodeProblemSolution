class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int first = 0;
        int second = 1;

        while (second < n) {

            if (nums[first] == 0 && nums[second] != 0) {
                swap(nums[first], nums[second]);
                first++;
            } else if (nums[first] != 0) {
                first++;
            }

            second++;
        }
    }
};