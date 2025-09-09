// LeetCode Link - "https://leetcode.com/problems/orderly-queue/description"
// Topic - String


class Solution {
public:
    string orderlyQueue(string s, int k) {

        // Simply sort and return the string
       if (k > 1) {
        sort(s.begin(), s.end());
        return s;
       } 

       string result = s;
       int n = s.length();
       for(int i = 1; i <= n-1; i++) {
            string temp = s.substr(i) + s.substr(0, i);
            result = min(result, temp);
       }

       return result;
    }
};
