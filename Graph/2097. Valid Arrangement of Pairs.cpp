// LeetCode Link - https://leetcode.com/problems/valid-arrangement-of-pairs/description


// Solution --->
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // STEP -> Build adjacency list
        unordered_map<int, vector<int>> adj;

        // Build indegree and outdegree
        unordered_map<int, int> indegree, outdegree;

        // key ---> node
        for(auto &edge : pairs) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v); // u ---> v
            indegree[v]++;
            outdegree[u]++;
        }

        // Find the start note for the Euler Path
        int startNode = pairs[0][0];
        for(auto& it : adj) {
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        vector<int> EulerPath; // To store my path
        stack<int> st;
        st.push(startNode); // Push the first node in stack

        // DFS
        while(!st.empty()) {
            int curr = st.top();

            if(!adj[curr].empty()) {
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        }

        // Rverese the EulerPath vector
        reverse(begin(EulerPath), end(EulerPath));
        vector<vector<int>> result;

        for(int i = 0; i < EulerPath.size() - 1; i++) {
            result.push_back({EulerPath[i], EulerPath[i+1]});
        }

        return result;

    }
};
