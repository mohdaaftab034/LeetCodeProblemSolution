// LeetCode Link - "https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description"
// Topic - String

// Approach - 1

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";

        for(int i=0; i<word1.size(); i++){
            s1 += word1[i];
        }

        for(int i=0; i<word2.size(); i++){
            s2 += word2[i];
        }

        if(s1 == s2){
            return true;
        }

        return false;
    }
};

// Approach - 2

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size();
        int n = word2.size();
        int w1i = 0, i = 0;
        int w2j = 0, j = 0;

        while(w1i < m && w2j < n) {
            if(word1[w1i][i] != word2[w2j][j]){
                return false;
            }
            i++;
            j++;

            if(i == word1[w1i].length()){
                i = 0;
                w1i++;
            }

            if(j == word2[w2j].length()){
                j = 0;
                w2j++;
            }
           
        }

        if(w1i == word1.size() && w2j == word2.size()){
            return true;
        }

        return false;
    }
};
