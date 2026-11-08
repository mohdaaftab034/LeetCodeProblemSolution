class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        // Count frequency of each string
        for(string &s : arr) {
            mp[s]++;
        }

        // Find the kth distinct string
        for(string &s : arr) {
            if(mp[s] == 1) {
                k--;

                if(k == 0) {
                    return s;
                }
            }
        }

        return "";
    }
};