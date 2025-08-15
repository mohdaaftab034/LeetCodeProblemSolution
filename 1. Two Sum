LeetCode Link - "https://leetcode.com/problems/two-sum/submissions/1528349746"


class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int>ans;
         int n = arr.size();
         for(int i = 0; i<n-1; i++)
         {
              for(int j = i+1; j<n; j++)
              {
                if(arr[i]+arr[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
              }
         }
         return ans;
    }
};
