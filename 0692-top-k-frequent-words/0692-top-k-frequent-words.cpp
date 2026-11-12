
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        // Count frequency
        for (string &word : words) {
            freq[word]++;
        }

        vector<string> ans;

        // Store unique words
        for (auto &it : freq) {
            ans.push_back(it.first);
        }

        // Custom sorting
        sort(ans.begin(), ans.end(), [&](string &a, string &b) {

            if (freq[a] == freq[b]) {
                return a < b;
            }

            return freq[a] > freq[b];
        });

        // Keep only top k words
        ans.resize(k);

        return ans;
    }
};
