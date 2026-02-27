// GFG Link - https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?utm=codolio


// Solution ---> 

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        
        int start = 0;
        int end = n - 1;
        int ans = -1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(arr[mid] <= x) {
                ans = mid;
                start = mid + 1;
            } else if(arr[mid] > x) {
                end = mid - 1;
            }
        }
        
        return ans;
    }
};
