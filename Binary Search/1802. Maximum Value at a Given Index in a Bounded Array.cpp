// LeetCode - https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/




// -----------------------Solution---------------------------
class Solution {
public:

    typedef long long ll;
    ll getaSumByFormula(ll count, ll x) {
        return count * x - count * (count + 1) / 2;
    }

    int maxValue(int n, int index, int maxSum) {
        ll left = 1;
        ll right = maxSum;
        ll midVal;
        int result = 0;

        while(left <= right) {
            midVal = left + (right - left) / 2;

            // ------------------Left Sum---------------
            ll left_count = min((ll)index, midVal - 1);
            ll left_sum = getaSumByFormula(left_count, midVal);
            left_sum += max((ll)0, index - (midVal -1));

            //------------------Right Sum--------------------
            ll right_count = min((ll)n - index - 1, midVal - 1);
            ll right_sum = getaSumByFormula(right_count, midVal);
            right_sum += max((ll)0, (n - index - 1) - (midVal - 1));

            // -----------------Calculations--------------------
            ll total_sum = left_sum + right_sum + midVal;

            if(total_sum <= maxSum) {
                result = max((ll)result, midVal);
                left = midVal + 1;
            } else {
                right = midVal - 1;
            }

        }
        return result;
    }
};
