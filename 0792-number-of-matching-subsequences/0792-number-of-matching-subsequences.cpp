
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> pos[26];

        // Store indices of each character
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        int count = 0;

        // Check every word
        for (string &word : words) {
            int prev = -1;
            bool found = true;

            for (char ch : word) {
                auto it = upper_bound(
                    pos[ch - 'a'].begin(),
                    pos[ch - 'a'].end(),
                    prev
                );

                if (it == pos[ch - 'a'].end()) {
                    found = false;
                    break;
                }

                prev = *it;
            }

            if (found) {
                count++;
            }
        }

        return count;
    }
};
