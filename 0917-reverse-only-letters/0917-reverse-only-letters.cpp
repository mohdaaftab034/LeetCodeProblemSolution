
class Solution {
public:
    string reverseOnlyLetters(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Skip non-letter characters from left
            if (!isalpha(s[left])) {
                left++;
            }

            // Skip non-letter characters from right
            else if (!isalpha(s[right])) {
                right--;
            }

            // Swap only letters
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};
