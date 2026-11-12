
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);

        // Count frequency of characters in s
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string ans = "";

        // Append characters according to order
        for (char ch : order) {
            while (freq[ch - 'a'] > 0) {
                ans += ch;
                freq[ch - 'a']--;
            }
        }

        // Append remaining characters
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                ans += char(i + 'a');
                freq[i]--;
            }
        }

        return ans;
    }
};
