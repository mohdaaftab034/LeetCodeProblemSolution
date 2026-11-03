class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        // Count the required frequencies of letters from the license plate (ignoring case and numbers)
        vector<int> targetCount(26, 0);
        for (char c : licensePlate) {
            if (isalpha(c)) {
                targetCount[tolower(c) - 'a']++;
            }
        }
        
        string shortestWord = "";
        
        for (const string& word : words) {
            vector<int> wordCount(26, 0);
            for (char c : word) {
                wordCount[c - 'a']++;
            }
            
            // Check if the current word is a completing word
            bool isValid = true;
            for (int i = 0; i < 26; ++i) {
                if (wordCount[i] < targetCount[i]) {
                    isValid = false;
                    break;
                }
            }
            
            // If valid and either it's the first found or shorter than the previous shortest
            if (isValid) {
                if (shortestWord == "" || word.length() < shortestWord.length()) {
                    shortestWord = word;
                }
            }
        }
        
        return shortestWord;
    }
};