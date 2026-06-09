// Problem - https://leetcode.com/problems/min-cost-to-connect-all-points/description/?utm=codolio



// --------------------Solution-----------------------
class Solution {
public:
    typedef pair<int, int> P;

    int primsAlgo(vector<vector<P>>& adj, int V) {
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, 0});
        vector<bool> inMST(V, false);
        int sum = 0;

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if (inMST[node] == true) {
                continue;
            }

            inMST[node] = true;
            sum += wt;

            for (auto& temp : adj[node]) {
                int neigh = temp.first;
                int neigh_wt = temp.second;

                if (inMST[neigh] == false) {
                    pq.push({neigh_wt, neigh});
                }
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        vector<vector<P>> adj(V);

        for (int i = 0; i < V; i++) {

            for (int j = i + 1; j < V; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        return primsAlgo(adj, V);
    }
};
