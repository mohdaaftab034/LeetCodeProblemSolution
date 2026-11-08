class Solution {
public:
    bool isValid(string word) {
        int hyphen = 0;
        int n = word.size();

        for(int i = 0; i < n; i++) {

            // Digits are not allowed
            if(isdigit(word[i])) {
                return false;
            }

            // Check punctuation
            if(word[i] == '!' || word[i] == '.' || word[i] == ',') {
                if(i != n - 1) {
                    return false;
                }
            }

            // Check hyphen
            if(word[i] == '-') {
                hyphen++;

                if(hyphen > 1 || i == 0 || i == n - 1) {
                    return false;
                }

                if(!islower(word[i - 1]) || !islower(word[i + 1])) {
                    return false;
                }
            }
        }

        return true;
    }

    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string word;

        int count = 0;

        while(ss >> word) {
            if(isValid(word)) {
                count++;
            }
        }

        return count;
    }
};