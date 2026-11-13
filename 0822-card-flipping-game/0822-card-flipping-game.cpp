class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {

        unordered_set<int> invalid;

        // Numbers appearing on both sides of the same card
        for (int i = 0; i < fronts.size(); i++) {
            if (fronts[i] == backs[i]) {
                invalid.insert(fronts[i]);
            }
        }

        int ans = INT_MAX;

        // Check all front values
        for (int num : fronts) {
            if (!invalid.count(num)) {
                ans = min(ans, num);
            }
        }

        // Check all back values
        for (int num : backs) {
            if (!invalid.count(num)) {
                ans = min(ans, num);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};