class Solution {
public:
    void getPermute(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if(idx==nums.size()) {
            ans.push_back(nums);
        }

        unordered_set<int> st;
        for (int i=idx; i<nums.size(); i++) {
            if(st.find(nums[i]) != st.end()) {
                continue;
            }

            st.insert(nums[i]); // insert unique element 

            // recursion
            swap(nums[i], nums[idx]);
            getPermute(nums, idx+1, ans);
            swap(nums[i], nums[idx]); // Backtracking
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        getPermute(nums, 0, ans);
        return ans;
    }
};