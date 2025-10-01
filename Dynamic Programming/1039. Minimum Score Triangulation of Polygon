// LeetCode Link - "https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description"



// Recursion Approach ---> Top down

class Solution {
public:

    int solve(vector<int>& values, int i, int j, vector<vector<int>>& memo) {

        if(j - i + 1 < 3) {
            return 0;
        }

        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int result = INT_MAX;

        for(int k = i + 1; k < j; k++) {
            
            int wt = values[i] * values[j] * values[k] 
                    + solve(values, i, k, memo)
                    + solve(values, k, j, memo);
            
            result = min(result, wt);
        }

        return memo[i][j] = result;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        vector<vector<int>> memo(51, -1);

        return solve(values, 0, n-1, memo);
    }
};
