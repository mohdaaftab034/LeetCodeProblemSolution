// LeetCode Link - "https://leetcode.com/problems/longest-palindromic-subsequence"



class Solution {
public:
    int LCS(string& s1, string& s2, int m, int n, vector<vector<int>> &t) {
        if (m == 0 || n == 0) {
            return t[m][n] = 0;
        }

        if (t[m][n] != -1) {
            return t[m][n];
        }

        if (s1[m-1] == s2[n-1]) {
            return t[m][n] = 1 + LCS(s1, s2, m-1, n-1, t);
        }

        return t[m][n] = max(LCS(s1, s2, m-1, n, t), LCS(s1, s2, m, n-1, t));
    }

    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        int n = s1.length();
        vector<vector<int>> t(n+1, vector<int>(n+1, -1));

        return LCS(s1, s2, n, n, t);
    }
};
