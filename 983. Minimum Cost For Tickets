// LeetCode Link - "https://leetcode.com/problems/minimum-cost-for-tickets/description"
// Topic - Dynamic Programming



// Approach - 1
class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs, int n, int i, vector<int>& memo) {
        if(i >= n) {
            return 0;
        }

        if(memo[i] != -1){
            return memo[i];
        }

        int costs_1 = costs[0] + solve(days, costs, n, i+1, memo);

        int j = i;
        int max_day = days[i] + 7;
        while(j<n && days[j] < max_day) {
            j++;
        }

        int costs_7 = costs[1] + solve(days, costs, n, j, memo);

        j = i;
        max_day = days[i] + 30; 
        while(j<n && days[j] < max_day) {
            j++;
        }
        int costs_30 = costs[2] + solve(days, costs, n, j, memo);


        return memo[i] = min({costs_1, costs_7, costs_30});

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<int> memo(366, -1);

        return solve(days, costs, n, 0, memo);
    }
};
