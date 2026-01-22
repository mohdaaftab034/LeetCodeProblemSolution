// LeetCode Link - https://leetcode.com/problems/unique-paths-ii/description


// Top Down Approach ---> Recursion + Memoization

class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        if(i < 0 || i > m || j < 0 || j > n || grid[i][j] == 1) {
            return 0;
        }

        if(i == m && j == n) return 1;

        // STEP - 3
        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, grid, m, n, dp);
        int down = solve(i + 1, j, grid, m, n, dp);

        // STEP - 2
        return dp[i][j] = (right + down);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // STEP - 1
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

        return solve(0, 0, obstacleGrid, m-1, n-1, dp);
    }
};




// Bottom up Approach ---> Tabulation Method
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n));
        
        // fill the first row
        for(int col = 0; col < n; col++) {
            if(grid[0][col] == 1) {
                dp[0][col] = 0;
            } else if(col >= 1 && grid[0][col-1] == 1) {
                dp[0][col] = 0;
                grid[0][col] = 1;
            } else {
                dp[0][col] = 1;
            }
        }

        // Fill the first column
        for(int row = 0; row < m; row++) {
            if(grid[row][0] == 1) {
                dp[row][0] = 0;
            } else if(row >= 1 && grid[row - 1][0] == 1) {
                dp[row][0] = 0;
                grid[row][0] = 1;
            } else {
                dp[row][0] = 1;
            }
        }

        // Fill the remaing row and column
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(grid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }

        return dp[m-1][n-1];
    }
};
