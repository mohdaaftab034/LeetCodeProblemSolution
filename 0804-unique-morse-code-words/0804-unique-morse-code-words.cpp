class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseTable = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        unordered_set<string> uniqueTransformations;
        
        for (const string& word : words) {
            string transformation = "";
            for (char c : word) {
                transformation += morseTable[c - 'a'];
            }
            uniqueTransformations.insert(transformation);
        }
        
        return uniqueTransformations.size();
    }
};