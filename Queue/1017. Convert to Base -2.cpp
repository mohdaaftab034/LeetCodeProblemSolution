// LeetCode Link - https://leetcode.com/problems/convert-to-base-2



// Solution --->
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        
        string result = "";
        
        while (n != 0) {
            int remainder = n % -2;
            n /= -2;
            
            // Fix negative remainder
            if (remainder < 0) {
                remainder += 2;
                n += 1;
            }
            
            result += to_string(remainder);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
