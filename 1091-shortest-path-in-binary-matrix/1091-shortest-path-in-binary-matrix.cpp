
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Starting or ending cell is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        // 8 possible directions
        vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        queue<pair<int, int>> q;

        q.push({0, 0});
        grid[0][0] = 1;

        int pathLength = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                // Destination reached
                if (r == n - 1 && c == n - 1) {
                    return pathLength;
                }

                for (auto &dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    // Check boundaries and whether cell is empty
                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 0) {

                        q.push({nr, nc});

                        // Mark visited
                        grid[nr][nc] = 1;
                    }
                }
            }

            pathLength++;
        }

        return -1;
    }
};
