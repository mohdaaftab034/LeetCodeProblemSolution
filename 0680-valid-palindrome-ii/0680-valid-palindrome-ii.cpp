class Solution {
private:
    bool isPalindromeRange(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                // Try deleting either the character at index i or index j
                return isPalindromeRange(s, i + 1, j) || isPalindromeRange(s, i, j - 1);
            }
        }
        
        return true;
    }
};