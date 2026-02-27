// GFG Link - https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1?utm=codolio



// Solution --->

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int idx = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] != 0) {
                arr[idx] = arr[i];
                idx++;
            }
        }
        
        while(idx < n) {
            arr[idx] = 0;
            idx++;
        }
        
    }
};
