//GFG Link - https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1?utm=codolio


// ----------------Recursion + Memoization-----------------
class Solution {
  public:
    
    bool isPalindrome(string& s, int l, int r, vector<vector<int>>& dp) {
        if(l >= r) return true;
        
        // STEP - 3
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        
        if(s[l] == s[r]) {
            
            // STEP -2
            return dp[l][r] = isPalindrome(s, l+1, r-1, dp);
        }
        
        return false;
    }
    
    
    string longestPalindrome(string &s) {
        int n = s.size();
        string ans = "";
        
        // STEP - 1
        vector<vector<int>> dp(n, vector<int >(n, -1));
        
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
