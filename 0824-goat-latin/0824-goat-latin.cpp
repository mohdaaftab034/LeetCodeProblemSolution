class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string result = "";
        string word = "";
        int index = 1;

        for (int i = 0; i <= sentence.length(); ++i) {
            if (i < sentence.length() && sentence[i] != ' ') {
                word += sentence[i];
            } else {
                if (!word.empty()) {
                    if (vowels.count(word[0])) {
                        word += "ma";
                    } else {
                        char firstChar = word[0];
                        word = word.substr(1) + firstChar + "ma";
                    }
                    word += string(index, 'a');
                    
                    if (!result.empty()) {
                        result += " ";
                    }
                    result += word;
                    
                    word = "";
                    index++;
                }
            }
        }

        return result;
    }
};