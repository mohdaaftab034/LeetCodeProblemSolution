
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        vector<string> ans;

        stringstream ss(text);
        string word;

        // Split text into words
        while (ss >> word) {
            words.push_back(word);
        }

        // Check consecutive three-word sequences
        for (int i = 0; i + 2 < words.size(); i++) {
            if (words[i] == first && words[i + 1] == second) {
                ans.push_back(words[i + 2]);
            }
        }

        return ans;
    }
};
