// LeetCode Link - https://leetcode.com/problems/palindromic-substrings/description/


// --------------Recursion----------------
class Solution {
public:

    bool isPalindrome(string& s, int i, int j) {
        if(i >= j) return true;

        if(s[i] == s[j]) {
            return isPalindrome(s, i+1, j-1);
        } 

        return false;
    }

    int countSubstrings(string s) {
        int n = s.size();

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPalindrome(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};



// ------------- Recursion + Memoization------------------
class Solution {
public:

    bool isPalindrome(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i >= j) return true;

        // STEP - 3
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == s[j]) {
            // STEP - 2
            return dp[i][j] = isPalindrome(s, i+1, j-1, dp);
        } 

        return false;
    }

    int countSubstrings(string s) {
        int n = s.size();

        int count = 0;

        // STEP - 1
        vector<vector<int>> dp(n, vector<int> (n, -1));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPalindrome(s, i, j, dp)) {
                    count++;
                }
            }
        }

        return count;
    }
};


// --------------Bottom - up Approach------------------
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int j = 0;

        // Make the blue print of palindrome
        for(int l = 1; l <= n; l++) {
            for(int i = 0; i + l -1 < n; i++) {

                j = i + l - 1;
                if(i == j) { // string ek length ki hogi
                    dp[i][j] = true;
                } else if (i + 1 == j) { // string do length ki hogi
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
            }
        }

        // count all the true's
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] == true) {
                    count++;
                }
            }
        }

        return count;
    }
};
