class Solution {
public:
    int numTrees(int n) {
        // dp[i] stores the number of unique BSTs that can be formed using i nodes
        vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // Empty tree is 1 unique BST
        dp[1] = 1; // Single node tree is 1 unique BST
        
        // Fill the DP table for 2 to n nodes
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // j is chosen as the root
                // Left subtree has (j - 1) nodes
                // Right subtree has (i - j) nodes
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};