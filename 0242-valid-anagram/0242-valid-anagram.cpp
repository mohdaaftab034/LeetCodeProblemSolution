class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m != n) return false;

        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            if (count[t[i] - 'a'] != 0) {
                count[t[i] - 'a']--;
            }
        }

        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += count[i];
        }

        if (sum == 0) return true;

        return false;
    }
};