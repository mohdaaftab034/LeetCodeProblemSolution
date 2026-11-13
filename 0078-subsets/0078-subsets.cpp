class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int> &nums, int i, vector<int>& temp) {

        // Base Case
        if(i >= nums.size()) {
            result.push_back(temp);
            return;
        }

        // if ---> taking a value
        temp.push_back(nums[i]);
        // call next cases
        solve(nums, i+1, temp);

        // if ---> not tiking
        temp.pop_back();

        // call another cases
        solve(nums, i+1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;

        solve(nums, 0, temp);

        return result;
    }
};