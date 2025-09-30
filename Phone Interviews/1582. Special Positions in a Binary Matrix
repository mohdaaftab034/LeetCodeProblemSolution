// LeetCode Link - "https://leetcode.com/problems/special-positions-in-a-binary-matrix/description"

// Approach - 1

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result = 0;
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) { // ✅ skip zeros
                    continue;
                }

                bool special = true;

                for(int r = 0; r < m; r++) {
                    if(r != i && mat[r][j] == 1) {
                        special = false;
                        break;
                    }
                }

                for(int c = 0; c < n; c++) {
                    if(c != j && mat[i][c] == 1) {
                        special = false;
                        break;
                    }
                }

                if(special) {
                    result++;
                }
            }
        }

        return result;
    }
};

// Approach - 2

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for(int i = 0; i < m; i++) {
            
            for(int j = 0; j < n; j++) {
                

                if(mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }


        int result = 0;

        for(int i = 0; i < m; i++) {
            
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    continue;
                }

                if(rowCount[i] == 1 && colCount[j] == 1) {
                    result++;
                }
            }
        }

        return result;
    }
};
