// LeetCode Link - https://leetcode.com/problems/triangle/description/?utm=codolio


// Top-down Approach ---> Recursion + Memoization

class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col, int n, vector<vector<int>>& dp) {

        if(row == n - 1) {
            return triangle[row][col];
        }

        // Memo check
        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int down = solve(triangle, row + 1, col, n, dp);
        int diagonal = solve(triangle, row + 1, col + 1, n, dp);

        dp[row][col] = triangle[row][col] + min(down, diagonal);

        return dp[row][col];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(201, vector<int>(201, -1));

        return solve(triangle, 0, 0, n, dp);
    }
};



// Bottom-up Approach ---> Tabulation Method

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;

        for(int row = n - 2; row >= 0; row--) {
            for(int col = 0; col <= row; col++) {
                dp[row][col] = dp[row][col] + min(dp[row+1][col], dp[row+1][col+1]);
            }
        }
        return dp[0][0];
    }
};
