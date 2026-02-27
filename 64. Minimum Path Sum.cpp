// Leetcode Link - "https://leetcode.com/problems/minimum-path-sum/description"
// Topic - Dynamic programming


// Approach - 1
class Solution {
public:

    int memo[201][201];
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if(i == m-1 && j == n-1) {
            return grid[i][j];
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        if (i == m-1) { // only can move right side
            return memo[i][j] = grid[i][j] + solve(grid, i, j+1, m, n);
        } else if (j == n-1) {
            return memo[i][j] = grid[i][j] + solve(grid, i+1, j, m, n);
        } else {
            return memo[i][j] = grid[i][j] + min(solve(grid, i+1, j, m, n), solve(grid, i, j+1, m, n));
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(memo, -1, sizeof(memo));

        return solve(grid, 0, 0, m, n);
    }
};


// Approach - 2
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int >> t(m, vector<int> (n));

        // t[0][0] = grid[0][0] min path sim to reach [i][j] to [0][0]
        t[0][0] = grid[0][0];

        for(int col = 1; col < n; col++) { // 1 st row fill
            t[0][col] = grid[0][col] + t[0][col-1];
        }

        for (int row = 1; row < m; row++) {
            t[row][0] = grid[row][0] + t[row-1][0];
        }

        for(int i = 1; i < m; i++) {

            for(int j = 1; j < n; j++) {

                t[i][j] = grid[i][j] + min(t[i-1][j], t[i][j-1]);
            }
        }

        return t[m-1][n-1];

    }
};
