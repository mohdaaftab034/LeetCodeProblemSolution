// LeetCode Link - https://leetcode.com/problems/intersection-of-two-arrays/description/?utm=codolio


// Solution --->
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for(int& num: nums2) {
            if(s.count(num)) {
                result.insert(num);
            }
        }

        vector<int> ans(result.begin(), result.end());

        return ans;
    }
};
