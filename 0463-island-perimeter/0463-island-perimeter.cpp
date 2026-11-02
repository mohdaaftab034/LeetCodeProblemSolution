class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int land_cells = 0;
        int common = 0;

        vector<pair<int,int>> dir = {
            {-1,0}, {1,0}, {0,-1}, {0,1}
        };

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    land_cells++;

                    for(auto &[dx, dy] : dir){
                        int x = i + dx;
                        int y = j + dy;

                        if(x >= 0 && y >= 0 && x < n && y < m){
                            if(grid[x][y] == 1) common++;
                        }
                    }
                }
            }
        }

        return (land_cells * 4) - common;
    }
};