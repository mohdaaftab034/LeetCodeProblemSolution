class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m != n) return false;

        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int num : count) {
            if(num != 0) {
                return false;
            }
        }
        return true;
    }
};