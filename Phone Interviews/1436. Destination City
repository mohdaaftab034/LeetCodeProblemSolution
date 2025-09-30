// LeetCode Link - "https://leetcode.com/problems/destination-city/description"



// Approach - 1

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;

        for(auto &path : paths) {
            string source = path[0];

            mp[source] = 1;
        }

        for(auto & path : paths) {

            string dest = path[1];

            if(mp[dest] != 1) {
                return dest;
            }
        }

        return "";
    }
};


// Approach - 2

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;

        for(auto & path : paths) {
            string source = path[0];

            st.insert(source);
        }

        for(auto & path : paths) {

            string dest = path[1];

            if(st.find(dest) == st.end()) {
                return dest;
            }
        }
        return "";
    }
};
