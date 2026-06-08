// Problem - https://leetcode.com/problems/edit-distance/description/?utm=codolio





// ---------------------Solution - 1-----------------------
class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        int m = s1.size();
        int n = s2.size();
        if(i == m) {
            return (n - j);
        }

        if(j == n) {
            return m - i;
        }

        // STEP - 3
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] == s2[j]) {
            return solve(s1, s2, i + 1, j + 1, dp);
        }

        int insert = 1 + solve(s1, s2, i, j + 1, dp);

        int delet = 1 + solve(s1, s2, i + 1, j, dp);

        int replace = 1 + solve(s1, s2, i + 1, j + 1, dp);

        // STEP - 2
        return dp[i][j] = min({insert, delet, replace});
    }

    int minDistance(string word1, string word2) {

        // STEP - 1
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));
        
        return solve(word1, word2, 0, 0, dp);
    }
};




// -----------------Solution - 2---------------------
