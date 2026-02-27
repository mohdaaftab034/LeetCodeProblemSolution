// LeetCode Link - "https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description"


// Approach - 1

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> mp;

        for(string &word : words) {

            for(char &ch : word) {
                
                mp[ch]++;
            }
        }

        for(auto &it : mp) {

            int freq = it.second;

            if(freq % n != 0) {
                return false;
            }
        }

        return true;
    }
};


// Approach - 2

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int count[26] = {0};

        for(string &word : words) {

            for(char &ch : word) {

                count[ch - 'a']++;
            }
        }

        for(int &freq : count) {
            if(freq % n != 0) {
                return false;
            }
        }
        return true;
    }
};


// Approach - 3

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int count[26] = {0};

        for(string &word : words) {

            for(char &ch : word) {

                count[ch - 'a']++;
            }
        }

        auto lambda = [&](int freq) {
            return freq % n == 0;
        };

        return all_of(begin(count), end(count), lambda);
       
    }
};
