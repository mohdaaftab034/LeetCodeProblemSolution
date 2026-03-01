// GFG link - https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-substring3411/1?utm=codolio


// -----------Brute Force Solution---------------
class Solution {
  public:
    
    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        
        return true;
    }
    
    
    string longestPalindrome(string &s) {
        int n = s.size();
        string ans = "";
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPalindrome(s, i, j)) {
                    if(j-i+1 > ans.length()) {
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        
        return ans;
    }
};


// ------------Recursion + Memoization------------------
class Solution {
  public:
  
    bool isPalindrome(string& s, int i, int j, vector<vector<int>> &dp) {
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
  
    string getLongestPal(string &s) {
        int n = s.size();
        string ans = "";
        
        // STEP - 1
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPalindrome(s, i, j, dp)) {
                    if(j-i+1 > ans.length()) {
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        
        return ans;
    }
};
