class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;

        // Space-optimized DP variables
        int prev2 = 1; // Represents ways to decode up to i-2
        int prev1 = 1; // Represents ways to decode up to i-1

        for (int i = 1; i < n; i++) {
            int current = 0;
            
            // 1. Single-digit decoding (must be '1' to '9')
            if (s[i] != '0') {
                current += prev1;
            }
            
            // 2. Two-digit decoding (must be between "10" and "26")
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }
            
            // Shift pointers forward
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};