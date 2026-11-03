class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> directions = {
            {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
            {1, -2}, {1, 2}, {2, -1}, {2, 1}
        };
        
        // dp[r][c] stores the probability of the knight being at cell (r, c)
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        dp[row][column] = 1.0;
        
        for (int step = 0; step < k; ++step) {
            vector<vector<double>> nextDp(n, vector<double>(n, 0.0));
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dp[r][c] > 0.0) {
                        for (auto& dir : directions) {
                            int nr = r + dir.first;
                            int nc = c + dir.second;
                            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                                nextDp[nr][nc] += dp[r][c] / 8.0;
                            }
                        }
                    }
                }
            }
            dp = move(nextDp);
        }
        
        // Sum up all probabilities of remaining on the board after k steps
        double totalProbability = 0.0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                totalProbability += dp[r][c];
            }
        }
        
        return totalProbability;
    }
};