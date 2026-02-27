LeetCode Link - "https://leetcode.com/problems/3sum/description"


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++){
            if(i>0 && arr[i] == arr[i-1]){
                continue;
            }
            int start=i+1, end = n-1;
            while(start<end){
               int sum = arr[i]+arr[start]+arr[end];
               if(sum==0){
                ans.push_back({arr[i],arr[start],arr[end]});
                start++, end--;
                while(start<end && arr[start] == arr[start-1]){
                    start++;
                }
               } 
               else if(sum>0){
                end--;
               }
               else{
                start++;
               }
            }
            
        }
        return ans;
    }
};
