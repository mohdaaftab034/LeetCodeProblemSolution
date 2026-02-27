// LeetCode Link - "https://leetcode.com/problems/flip-string-to-monotone-increasing/description"
// Topic - Dynamic Programming

class Solution {
public:

    int n;

    int solve(string& s, int curr_index, int prev, vector<vector<int>>& memo) {
        if(curr_index >= n){
            return 0;
        }

        if(memo[curr_index][prev] != -1){
            return memo[curr_index][prev];
        }

        int flip = INT_MAX;
        int no_flip = INT_MAX;

        if(s[curr_index] == '0'){
            if(prev == 1){
                flip = 1 + solve(s, curr_index + 1, 1, memo);
            } else { // prev == 1
                flip = 1 + solve(s, curr_index + 1, 1, memo);
                no_flip = solve(s, curr_index + 1, 0, memo);
            }
        } else {
            if(prev == 1){
                no_flip = solve(s, curr_index + 1, 1, memo);
            } else {
                flip = 1 + solve(s, curr_index + 1, 0, memo);
                no_flip = solve(s, curr_index + 1, 1, memo);
            }
        }


        return memo[curr_index][prev] = min(flip, no_flip);
    }

    int minFlipsMonoIncr(string s) {
        n = s.size();

        vector<vector<int>> memo(n+1, vector<int>(2, -1));

        return solve(s, 0, 0, memo);
    }
};
