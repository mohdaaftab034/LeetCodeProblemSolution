class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();

        if (n1 < n2)
            num1 = string(n2 - n1, '0') + num1;
        else
            num2 = string(n1 - n2, '0') + num2;

        string ans;
        int carry = 0;

        for (int i = num1.size() - 1; i >= 0; i--) {
            int sum = carry + (num1[i] - '0') + (num2[i] - '0');

            ans += (sum % 10) + '0';
            carry = sum / 10;
        }

        if (carry)
            ans += carry + '0';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};