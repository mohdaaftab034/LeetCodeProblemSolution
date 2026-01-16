// LeetCode Link - https://leetcode.com/problems/find-missing-and-repeated-values/description


// Solution --->

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans;
        unordered_set<int> st;
        int a, b;

        int actualSum = 0;
        int expectedSum = 0;

        // Traverse all the elements in the 2D matrix for calculate the repeated elements

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // Find the sum of the grid
                actualSum += grid[i][j];

                if(st.find(grid[i][j]) != st.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                st.insert(grid[i][j]);
            }
        }

        // Expected sum for the grid
        expectedSum = n*n * (n*n + 1) /2;

        // find the missing element
        b = expectedSum + a - actualSum;
        ans.push_back(b);

        return ans;
    }
};
