// GFG link - https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1?utm=codolio



// Solution --->

class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        int n = arr.size();
        
        int start = 0;
        int end = n - 1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(arr[mid] == k) {
                return true;
            } else if(arr[mid] < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return false;
    }
};
