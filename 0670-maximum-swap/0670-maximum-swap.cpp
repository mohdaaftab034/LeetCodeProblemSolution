class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        
        // Store the last occurrence index of each digit (0-9)
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[s[i] - '0'] = i;
        }
        
        // Traverse the string from left to right
        for (int i = 0; i < n; ++i) {
            // Check if there is a larger digit (from '9' down to s[i] + 1) appearing later
            for (int d = 9; d > s[i] - '0'; --d) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }
        
        return num;
    }
};