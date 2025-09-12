// LeetCode Link - "https://leetcode.com/problems/vowels-game-in-a-string/description/?envType=daily-question&envId=2025-09-12"



class Solution {
public:

    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }

        return false;
    }

    bool doesAliceWin(string s) {
        int n = s.length();

        int count = 0;
        for(char &ch: s) {
            if(isVowel(ch)) {
                count++;
            }
        }

        if(count == 0) {
            return false;
        }

        return true;
    }
};
