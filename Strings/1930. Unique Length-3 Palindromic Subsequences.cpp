// LeetCode Link - "https://leetcode.com/problems/unique-length-3-palindromic-subsequences"


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        unordered_set<char> letters;

        for(int i = 0; i < n; i++) {
            letters.insert(s[i]);
        }

        int result = 0;

        for(int letter : letters) {
            int left_idx = -1;
            int right_idx = -1;

            for(int i = 0; i < n; i++) {
                if(s[i] == letter) {
                    if(left_idx == -1) {
                        left_idx = i;
                    }

                    right_idx = i;
                }
            }

            unordered_set<char> st;
            for(int middle = left_idx + 1; middle <= right_idx -1; middle++) {
                st.insert(s[middle]);
            }

            result += st.size();
        }

        return result;

    }
};
