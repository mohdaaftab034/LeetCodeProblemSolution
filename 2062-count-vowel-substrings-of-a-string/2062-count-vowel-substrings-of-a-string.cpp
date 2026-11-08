class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<char> st;

            for(int j = i; j < n; j++) {

                // Stop if character is not a vowel
                if(word[j] != 'a' && word[j] != 'e' &&
                   word[j] != 'i' && word[j] != 'o' &&
                   word[j] != 'u') {
                    break;
                }

                st.insert(word[j]);

                // All five vowels must be present
                if(st.size() == 5) {
                    count++;
                }
            }
        }

        return count;
    }
};