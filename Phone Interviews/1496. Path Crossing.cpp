// LeetCode Link - "https://leetcode.com/problems/path-crossing"


// Approach - 1

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int, int>> visited;
        visited.insert({0, 0}); // starting point

        for (char dir : path) {
            if (dir == 'N') y++;
            else if (dir == 'S') y--;
            else if (dir == 'E') x++;
            else if (dir == 'W') x--;

            // if we've already been here
            if (visited.count({x, y})) return true;

            visited.insert({x, y});
        }

        return false;
    }
};


// Approach - 2

class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        unordered_set<string> st;

        int x = 0;
        int y = 0;

        string key = to_string(x) + "_" + to_string(y);
        st.insert(key);

        for(int i = 0; i < n; i++) {

            if (path[i] == 'E') {
                x++;
            } else if (path[i] == 'W') {
                x--;
            } else if (path[i] == 'N') {
                y++;
            } else {
                y--;
            }

            
            key = to_string(x) + "_" + to_string(y);

            if(st.find(key) != st.end()) {
                return true;
            }

            st.insert(key);
        }

        return false;

    }
};
