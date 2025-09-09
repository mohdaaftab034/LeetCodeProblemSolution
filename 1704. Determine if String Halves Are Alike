// LeetCode Link - "https://leetcode.com/problems/determine-if-string-halves-are-alike"
// Topic - String


class Solution {
public:

    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        
        return false;
    }

    bool halvesAreAlike(string s) {
        int countLeft = 0;
        int countRight = 0;
        int n = s.length();
        int i = 0, j = n/2;

        while(i < n/2 && j < n) {
            if(isVowel(s[i])){
                countLeft++;
            }

            if(isVowel(s[j])){
                countRight++;
            }

            i++;
            j++;
        }

        if(countLeft == countRight) {
            return true;
        }

        return false;
    }
};
