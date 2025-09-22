// LeetCode Link - "https://leetcode.com/problems/find-the-difference/description"

// Approach - 1
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;

        for(char &ch : s) {
            mp[ch]++;
        }

        for(char &ch: t) {
            mp[ch]--;

            if(mp[ch] < 0) {
                return ch;
            }
        }

        return 'x';
    }
};



// Approach - 2
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum_s = 0;

        for(char &ch: s) {
            sum_s += ch;
        }

        int sum_t = 0;
        for(char &ch: t) {
            sum_t += ch;
        }

        return (char)(sum_t - sum_s);
    }
};


// Approach - 3
class Solution {
public:
    char findTheDifference(string s, string t) {
        int XOR = 0;

        for(char &ch: s) {
            XOR ^= ch;
        }

        for(char &ch: t) {
            XOR ^= ch;
        }

        return (char)XOR;
    }
};
