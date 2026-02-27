// GFG Link - https://www.geeksforgeeks.org/problems/binary-search-1587115620/1?utm=codolio


// Solution ---> 

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int n = arr.size();
        
        int start = 0; 
        int end = n - 1;
        int ans = -1;
        
        while(start <= end) {
            int mid = start + (end - start) /2;
            
            if(arr[mid] == k) {
                ans = mid;
                end = mid - 1;
            } else if(arr[mid] < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return ans;
    }
};
