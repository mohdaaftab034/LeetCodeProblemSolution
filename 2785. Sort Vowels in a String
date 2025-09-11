// LeetCode Link - "https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2025-09-11"
// Topic - Strings


class Solution {
public:

    bool isVowel(char ch) {
        ch = tolower(ch);
        if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }

        return false;
    }

    string sortVowels(string s) {

        unordered_map<char, int> mp;
        
        for(char & ch : s) {
            if(isVowel(ch)) {
                mp[ch]++;
            }
        }

        string temp = "AEIOUaeiou";
        int j = 0;

        for(int i = 0; i < s.length(); i++) {
            if(isVowel(s[i])) {
                while(mp[temp[j]] == 0) {
                    j++;
                }

                s[i] = temp[j];
                mp[temp[j]]--;
            }

        }

        return s;
    }
};
