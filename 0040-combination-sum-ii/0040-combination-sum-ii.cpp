class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        // Sort the candidates to handle duplicates easily
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same tree depth
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            // If the current candidate exceeds the remaining target, stop searching this branch
            if (candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);
            // Move to the next index (i + 1) because each element can only be used once
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back(); // Backtrack
        }
    }
};