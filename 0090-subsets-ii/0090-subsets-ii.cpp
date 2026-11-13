class Solution {
public:
    vector<vector<int>> result;

    void getAllSubsets(vector<int>& nums, int i, vector<int>& temp) {

        // Base Case
        if (i >= nums.size()) {
            result.push_back(temp);
            return;
        }

        // if ---> taking a current element
        temp.push_back(nums[i]);
        getAllSubsets(nums, i + 1, temp);

        // if ---> not taking a current element

        // remove duplicates element
        int index = i + 1;
        while (index < nums.size() && nums[index] == nums[index - 1]) {
            index++;
        }

        temp.pop_back();
        getAllSubsets(nums, index, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> temp;

        getAllSubsets(nums, 0, temp);

        return result;
    }
};