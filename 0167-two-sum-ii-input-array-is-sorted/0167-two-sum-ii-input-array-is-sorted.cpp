class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        vector<int> ans;

        while(start < end) {
            int num = numbers[start] + numbers[end];

            if(num > target) {
                end--;
            } else if (num < target) {
                start++;
            } else {
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                return ans;
            }
        }

        return ans;
    }
};