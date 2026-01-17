// Leetcode Link - https://leetcode.com/problems/reverse-string-prefix



// Solution --->

class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();

        int start = 0;
        int end = k - 1;

        while(start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};
