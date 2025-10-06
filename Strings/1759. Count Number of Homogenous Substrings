// LeetCode Link - "https://leetcode.com/problems/count-number-of-homogenous-substrings/description"



class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int mod = 1e9 + 7;

        int length = 0;
        int result = 0;

        for (int i = 0; i < n; i++) {

            if( i > 0 && s[i] == s[i-1]) {
                length++;
            } else {
                length = 1;
            }
            result = (result + length) % mod;
        }

        return result;
    }
};
