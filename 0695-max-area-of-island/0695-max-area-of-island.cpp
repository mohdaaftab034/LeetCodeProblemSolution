
class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int i, int j) {

        // Boundary check and water check
        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == 0) {
            return 0;
        }

        // Mark as visited
        grid[i][j] = 0;

        // Count current cell
        int area = 1;

        // Explore all 4 directions
        area += dfs(grid, i + 1, j);
        area += dfs(grid, i - 1, j);
        area += dfs(grid, i, j + 1);
        area += dfs(grid, i, j - 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    int area = dfs(grid, i, j);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
