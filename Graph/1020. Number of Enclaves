// Leetcode Link - https://leetcode.com/problems/number-of-enclaves/description/?utm=codolio


// Solution --->

class Solution {
public:

    int n, m;
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void DFS(int row, int col, vector<vector<int>>& grid) {
        grid[row][col] = 0;

        for(auto &dir : directions) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            if(new_row >= 0 && new_col >= 0 && new_row < m && new_col < n && grid[new_row][new_col] == 1) {
                DFS(new_row, new_col, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();

        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1) {
                DFS(0, j, grid);
            }
        }

        for(int j = 0; j < n; j++) {
            if(grid[m-1][j] == 1) {
                DFS(m-1, j, grid);
            }
        }

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) {
                DFS(i, 0, grid);
            }
        }

        for(int i = 0; i < m; i++) {
            if(grid[i][n-1] == 1) {
                DFS(i, n-1, grid);
            }
        }
        
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
