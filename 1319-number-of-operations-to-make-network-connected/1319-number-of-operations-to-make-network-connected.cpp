#include <vector>

class Solution {
private:
    vector<int> parent;
    
    // Find with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    // Union two components; returns true if they were merged, false if redundant
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // A graph with n nodes requires at least n - 1 cables to be fully connected
        if (connections.size() < n - 1) return -1;
        
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        int components = n;
        for (const auto& conn : connections) {
            // If the two computers are not already connected, merge them
            if (unite(conn[0], conn[1])) {
                components--;
            }
        }
        
        // The minimum operations needed to connect `components` independent components 
        // is (components - 1), provided we have enough cables (validated above).
        return components - 1;
    }
};