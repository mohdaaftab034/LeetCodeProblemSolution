// LeetCode Link - "https://leetcode.com/problems/restore-the-array/description"


// Approach - 1 ---> Memo + Recursion
class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    int solve(int start, string& s, int &k, vector<int>& memo) {
        if(start >= n) {
            return 1;
        }

        if(s[start] == '0') {
            return 0;
        }

        if(memo[start] != -1) {
            return memo[start];
        } 

        long ans = 0;
        long long num = 0;

        for(int end = start; end < n; end++) {
            num = (num * 10) + (s[end] - '0');

            if(num > k) {
                break;
            }

            ans = (ans%MOD + solve(end + 1, s, k, memo)%MOD)%MOD;
        }
        return memo[start] = ans;
    }

    int numberOfArrays(string s, int k) {
        n = s.size();

        vector<int> memo(n, -1);

        return solve(0, s, k, memo);
    }
};
