class Solution {
public:
    int uniquePaths(int m, int n) {
        // STEP - 1
        vector<vector<int>> dp(m, vector<int>(n));

        // STEP - 2
        dp[0][0] = 0;
        for(int col = 0; col < n; col++){
            dp[0][col] = 1;
        }

        for(int row = 0; row < m; row++) {
            dp[row][0] = 1;
        }

        // STEP - 3

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        
        return dp[m-1][n-1];
    }
};