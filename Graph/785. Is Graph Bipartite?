// LeetCode Link - "https://leetcode.com/problems/is-graph-bipartite/description"


// Approach - 1 ---> DFS

class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>> &adj, int curr, vector<int> &color, int currColor) {
        color[curr] = currColor;

        for (int &v : adj[curr]) {
            if (color[v] == color[curr]) {
                return false;
            }

            if (color[v] == -1) {
                int colorofV = 1 - currColor;
                if (checkBipartiteDFS(adj, v, color, colorofV) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (checkBipartiteDFS(graph, i, color, 1) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};


// Approach - 2 ----> BFS

class Solution {
public:

    bool checkBipartiteBFS(vector<vector<int>>& adj, int curr, vector<int>& color, int currColor) {

        queue<int> que;
        que.push(curr);
        color[curr] = currColor;

        while(!que.empty()) {

            int u = que.front();
            que.pop();

            for(int & v : adj[u]) {

                if(color[v] == color[u]) {
                    return false;
                } else if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
        }
        return true;

    }

    bool isBipartite(vector<vector<int>>& adj) {
        int v = adj.size();

        vector<int> color(v, -1);

        for(int i = 0; i < v; i++) {
            if(color[i] == -1) {
                
                if(checkBipartiteBFS(adj, i, color, 1) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};
