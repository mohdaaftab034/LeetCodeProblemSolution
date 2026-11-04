#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st;

        // Split the path by '/'
        while (getline(ss, token, '/')) {
            // Ignore empty segments and current directory '.'
            if (token == "" || token == ".") {
                continue;
            }
            // Parent directory '..' moves up one level if possible
            else if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } 
            // Valid directory name
            else {
                st.push_back(token);
            }
        }

        // Reconstruct the simplified path
        string result = "";
        for (const string& dir : st) {
            result += "/" + dir;
        }

        // Return root "/" if result is empty
        return result.empty() ? "/" : result;
    }
};