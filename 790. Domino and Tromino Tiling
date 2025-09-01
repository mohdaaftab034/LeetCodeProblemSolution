// LeetCode Link - "https://leetcode.com/problems/domino-and-tromino-tiling"
// Topic - Dynamic Programming

// Approach - 1
class Solution {
public:

    int M = 1000000007;
    int memo[1001];

    int solve(int n) {
        if(n == 1 || n == 2) {
            return n;
        }
        if(memo[n] != -1) {
            return memo[n];
        }

        if(n == 3) {
            return 5;
        }


        return memo[n] =  (2 *solve(n - 1) % M + solve(n - 3) % M) % M;
    }

    int numTilings(int n) {
        memset(memo, -1, sizeof(memo));

        return solve(n);
    }
};


// Apprpach - 2
class Solution {
public:
    
    int M = 1000000007;
    int numTilings(int n) {
        if(n == 1 || n == 2) {
            return n;
        }

        vector<int> t(n+1, 0);

        t[1] = 1;
        t[2] = 2;
        t[3] = 5;

        for(int i = 4; i <= n; i++) {
            t[i] = (2*t[i-1] % M + t[i-3] % M) % M;
        }

        return t[n];
    }
};
