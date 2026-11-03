class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> res(n, n);
        
        // Left to right pass
        int prev = -n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                prev = i;
            }
            res[i] = i - prev;
        }
        
        // Right to left pass
        prev = 2 * n;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) {
                prev = i;
            }
            res[i] = min(res[i], prev - i);
        }
        
        return res;
    }
};