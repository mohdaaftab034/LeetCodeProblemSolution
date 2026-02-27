LeetCode Link - "https://leetcode.com/problems/valid-parentheses"


class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            temp.push(s[i]);

            else{
                if(temp.empty())
                return 0;

                if((s[i] == ')' && temp.top() != '(') || 
                (s[i] == '}' && temp.top() != '{') ||
                (s[i] == ']' && temp.top() != '['))  return false;
                temp.pop();
                 
            }
        }

        return temp.empty();
    }
};
