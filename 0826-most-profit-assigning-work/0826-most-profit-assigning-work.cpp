
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();

        vector<pair<int, int>> jobs;

        // Store difficulty and profit together
        for (int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        // Sort jobs by difficulty
        sort(jobs.begin(), jobs.end());

        // Sort workers by ability
        sort(worker.begin(), worker.end());

        int ans = 0;
        int maxProfit = 0;
        int j = 0;

        // Process each worker
        for (int ability : worker) {

            // Find all jobs this worker can complete
            while (j < n && jobs[j].first <= ability) {
                maxProfit = max(maxProfit, jobs[j].second);
                j++;
            }

            // Assign the most profitable available job
            ans += maxProfit;
        }

        return ans;
    }
};
