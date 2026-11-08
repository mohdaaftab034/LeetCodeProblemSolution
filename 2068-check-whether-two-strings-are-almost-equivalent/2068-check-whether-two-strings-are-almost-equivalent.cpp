class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int freq[26] = {0};

        for(char ch : word1) {
            freq[ch - 'a']++;
        }

        for(char ch : word2) {
            freq[ch - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(abs(freq[i]) > 3) {
                return false;
            }
        }

        return true;
    }
};