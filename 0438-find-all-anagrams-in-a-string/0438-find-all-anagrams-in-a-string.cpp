class Solution {
public:

    bool allZero(vector<int>& counter) {
        int count = 0;

        for (int &n : counter) {
            if (n == 0) {
                count++;
            }
        }

        if (count == counter.size()) {
            return true;
        }

        return false;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();

        vector<int> counter(26, 0);

        for (int i = 0; i < p.length(); i++) {
            char ch = p[i];

            counter[ch - 'a']++;
        }

        int i = 0, j = 0;
        vector<int> result;

        while (j < n) {
            counter[s[j] - 'a']--;

            if (j - i + 1 == p.length()) {
                if(allZero(counter)) {
                    result.push_back(i);
                }
                counter[s[i] - 'a']++;
                i++;
            }

            j++;
        }

        return result;
    }
};