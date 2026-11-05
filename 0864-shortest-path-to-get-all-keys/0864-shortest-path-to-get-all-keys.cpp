
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int keys = 0;
        int sx = 0, sy = 0;

        // Find starting point and total keys
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                }

                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    keys++;
                }
            }
        }

        int totalKeys = (1 << keys) - 1;

        // visited[row][col][keyMask]
        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(1 << keys, false))
        );

        queue<tuple<int, int, int>> que;

        que.push({sx, sy, 0});
        visited[sx][sy][0] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int steps = 0;

        while (!que.empty()) {

            int size = que.size();

            while (size--) {

                auto [x, y, mask] = que.front();
                que.pop();

                if (mask == totalKeys) {
                    return steps;
                }

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    char ch = grid[nx][ny];

                    if (ch == '#')
                        continue;

                    // Check lock
                    if (ch >= 'A' && ch <= 'F') {
                        int bit = ch - 'A';

                        if ((mask & (1 << bit)) == 0)
                            continue;
                    }

                    int newMask = mask;

                    // Collect key
                    if (ch >= 'a' && ch <= 'f') {
                        int bit = ch - 'a';
                        newMask |= (1 << bit);
                    }

                    if (!visited[nx][ny][newMask]) {

                        visited[nx][ny][newMask] = true;
                        que.push({nx, ny, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
