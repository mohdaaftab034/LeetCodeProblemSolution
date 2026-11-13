
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target,
                    vector<vector<int>>& specialRoads) {

        int n = specialRoads.size();

        auto dist = [](int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        };

        // Min Heap: {cost, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Each node represents the endpoint of a special road.
        vector<int> costs(n, INT_MAX);
        vector<bool> visited(n, false);

        // Initially, reach every special road's endpoint
        // using normal walking from start.
        for (int i = 0; i < n; i++) {
            int walkingCost = dist(
                start[0], start[1],
                specialRoads[i][0], specialRoads[i][1]
            );

            costs[i] = walkingCost + specialRoads[i][4];
            pq.push({costs[i], i});
        }

        int ans = dist(
            start[0], start[1],
            target[0], target[1]
        );

        while (!pq.empty()) {

            auto [cost, i] = pq.top();
            pq.pop();

            if (visited[i]) continue;
            visited[i] = true;

            int x = specialRoads[i][2];
            int y = specialRoads[i][3];

            // Reach target directly from current position.
            ans = min(ans, cost + dist(
                x, y, target[0], target[1]
            ));

            // Try every other special road.
            for (int j = 0; j < n; j++) {

                if (visited[j]) continue;

                int walkingCost = dist(
                    x, y,
                    specialRoads[j][0],
                    specialRoads[j][1]
                );

                int newCost = cost + walkingCost
                              + specialRoads[j][4];

                if (newCost < costs[j]) {
                    costs[j] = newCost;
                    pq.push({newCost, j});
                }
            }
        }

        return ans;
    }
};
