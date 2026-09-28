class Solution {
public:
    
    void permut(vector<int>& arr,vector<vector<int>>& ans,int index)
    {
        if(index==arr.size()){
            ans.push_back(arr);
            return ;
        }
        vector<bool>visited(21,0);
        for(int i=index; i<arr.size(); i++)
        {
            if(visited[arr[i]+10]==0){
                swap(arr[i],arr[index]);
                permut(arr,ans,index+1);
                swap(arr[i], arr[index]);
                visited[arr[i]+10]=1;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permut(nums,ans,0);
        return ans;
    }
};