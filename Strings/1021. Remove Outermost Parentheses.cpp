// LeetCode Link - https://leetcode.com/problems/remove-outermost-parentheses/description/?utm=codolio



// -------------------Solution 1 ----> With Stack-----------------------
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";


        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                if(!st.empty()) {
                    ans += s[i];
                }
                st.push(s[i]);
            } else {
                st.pop();
                if(!st.empty()) {
                    ans += s[i];
                }
            }
        }

        return ans;
    }
};



// -------------------Solution ----> Without Stack ----> Contant space and Time  ----------------------
class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter = 0;
        string ans = "";


        for (int i = 0; i < s.length(); i++) {
            
            if(s[i] == ')') counter++;

            if(counter != 0) {
                ans += s[i];
            }

            if(s[i] == '(') counter--;
        }

        return ans;
    }
};
