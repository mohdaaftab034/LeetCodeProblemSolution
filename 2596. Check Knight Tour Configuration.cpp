// LeetCode Link - "https://leetcode.com/problems/check-knight-tour-configuration/description"
// Topic - Recursion


// Solution ---> 


class Solution {
public:

    bool isValidHelper(vector<vector<int>>& grid, int r, int c, int n, int expVal) {

        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal){
            return false;
        }

        if(expVal == n*n -1){
            return true;
        }
        // 8 Moves 
        int ans1 = isValidHelper(grid, r-2, c+1, n, 1 + expVal);
        int ans2 = isValidHelper(grid, r-1, c+2, n, 1 + expVal);
        int ans3 = isValidHelper(grid, r+1, c+2, n, 1 + expVal);
        int ans4 = isValidHelper(grid, r+2, c+1, n, 1 + expVal);
        int ans5 = isValidHelper(grid, r+2, c-1, n, 1 + expVal);
        int ans6 = isValidHelper(grid, r+1, c-2, n, 1 + expVal);
        int ans7 = isValidHelper(grid, r-1, c-2, n, 1 + expVal);
        int ans8 = isValidHelper(grid, r-2, c-1, n, 1 + expVal);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        return isValidHelper(grid, 0, 0, n, 0);
    }
};
