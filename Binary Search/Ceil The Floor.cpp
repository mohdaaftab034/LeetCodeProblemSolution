// GFG Link - https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm=codolio


// Solution --->

class Solution {
public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int start = 0;
        int end = n - 1;
        
        int floor_ans = -1;
        int ceil_ans = -1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(arr[mid] == x) {
                return {x, x};   // exact match
            }
            
            else if(arr[mid] < x) {
                floor_ans = arr[mid];  // store value
                start = mid + 1;
            } 
            
            else {  // arr[mid] > x
                ceil_ans = arr[mid];   // store value
                end = mid - 1;
            }
        }
        
        return {floor_ans, ceil_ans};
    }
};
