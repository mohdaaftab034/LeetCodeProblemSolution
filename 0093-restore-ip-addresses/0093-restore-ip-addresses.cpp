class Solution {
public:
    vector<string> ans;

    void backtrack(string &s, int idx, int parts, string ip) {
        if (parts == 4) {
            if (idx == s.size()) {
                ip.pop_back(); // Remove last dot
                ans.push_back(ip);
            }
            return;
        }

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);

            // Leading zero check
            if (len > 1 && part[0] == '0') {
                break;
            }

            // Value must be <= 255
            if (stoi(part) > 255) {
                break;
            }

            backtrack(s, idx + len, parts + 1, ip + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        if (s.size() < 4 || s.size() > 12) {
            return ans;
        }

        backtrack(s, 0, 0, "");

        return ans;
    }
};