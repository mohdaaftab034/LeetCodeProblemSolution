// LeetCode Link - https://leetcode.com/problems/bag-of-tokens/


// -----------------Solution--------------------
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(begin(tokens), end(tokens));

        int i = 0, j = n-1;
        int maxScore = 0;
        int score = 0;

        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i];
                score++;
                i++;

                maxScore = max(maxScore, score);
            } else if(score >= 1) {
                power += tokens[j];
                score--;
                j--;
            } else {
                return maxScore;
            }
        }

        return maxScore;
    }
};
