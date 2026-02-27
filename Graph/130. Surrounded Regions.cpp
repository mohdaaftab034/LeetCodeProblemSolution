// LeetCode Link - https://leetcode.com/problems/surrounded-regions/description/?utm=codolio


// Solution ----> 

class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void DFS(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
        vis[row][col] = 1;

        for(auto &dir : directions) {
            int nrow = row + dir[0];
            int ncol = col + dir[1];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                DFS(nrow, ncol, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
         m = board.size();
         n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Traverse first row and last row to call the DFS
        for (int j = 0; j < n; j++) {
            
            // First row
            if(!vis[0][j] && board[0][j] == 'O') {
                DFS(0, j, vis, board);
            }

            // Last row
            if(!vis[m-1][j] && board[m-1][j] == 'O') {
                DFS(m-1, j, vis, board);
            }
        }

        // Traverse first column and last column
        for(int i = 0; i < m; i++) {

            // first column
            if(!vis[i][0] && board[i][0] == 'O') {
                DFS(i, 0, vis, board);
            }

            // Last row
            if(!vis[i][n-1] && board[i][n-1] == 'O') {
                DFS(i, n-1, vis, board);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

    }
};
