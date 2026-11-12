
class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";

        int prev = 0;

        for (int curr = 1; curr < s.size(); curr++) {

            if (s[curr] == '.') {
                continue;
            }

            int middle = curr - prev - 1;

            // R ... L
            if (s[prev] == 'R' && s[curr] == 'L') {

                int left = prev + 1;
                int right = curr - 1;

                while (left < right) {
                    s[left++] = 'R';
                    s[right--] = 'L';
                }
            }

            // L ... L
            else if (s[prev] == 'L' && s[curr] == 'L') {
                for (int i = prev + 1; i < curr; i++) {
                    s[i] = 'L';
                }
            }

            // R ... R
            else if (s[prev] == 'R' && s[curr] == 'R') {
                for (int i = prev + 1; i < curr; i++) {
                    s[i] = 'R';
                }
            }

            prev = curr;
        }

        return s.substr(1, dominoes.size());
    }
};
