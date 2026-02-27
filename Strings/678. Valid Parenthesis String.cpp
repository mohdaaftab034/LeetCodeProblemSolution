// Leetcode Link - https://leetcode.com/problems/valid-parenthesis-string/description/?utm=codolio


class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;   // stores indices of '('
        stack<int> star;   // stores indices of '*'
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open.push(i);
            } 
            else if (s[i] == '*') {
                star.push(i);
            } 
            else { // s[i] == ')'
                if (!open.empty()) {
                    open.pop();
                } 
                else if (!star.empty()) {
                    star.pop();
                } 
                else {
                    return false;
                }
            }
        }
        
        // Match remaining '(' with '*' (as ')')
        while (!open.empty() && !star.empty()) {
            if (open.top() < star.top()) {
                open.pop();
                star.pop();
            } 
            else {
                return false;
            }
        }
        
        // If '(' still remains, invalid
        return open.empty();
    }
};
