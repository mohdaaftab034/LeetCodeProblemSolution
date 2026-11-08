class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> s3(nums3.begin(), nums3.end());

        for(int num : s1) mp[num]++;
        for(int num : s2) mp[num]++;
        for(int num : s3) mp[num]++;

        vector<int> ans;

        for(auto &it : mp) {
            if(it.second >= 2) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};