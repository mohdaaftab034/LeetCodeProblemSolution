
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {

        int n = nums.size();
        long long MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        long long power = 1;
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long contribution = (nums[i] * power) % MOD;

            ans = (ans + contribution - nums[n - 1 - i] * power % MOD + MOD) % MOD;

            power = (power * 2) % MOD;
        }

        return ans;
    }
};
