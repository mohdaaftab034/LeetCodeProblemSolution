// LeetCode Link - https://leetcode.com/problems/flood-fill/description/?utm=codolio


// Solution ---> 

class Solution {
public:
    void DFS(vector<vector<int>>& image, int i, int j, int newColor, int orgColor) {
        
        // Check All condition for image boundary
        if(i >= image.size() || i < 0 || j >= image[0].size() || j < 0 || image[i][j] == newColor || image[i][j] != orgColor) {
            return ;
        }

        image[i][j] = newColor; // Asign new color and move to next

        // Call the DFS function of all neighbours
        DFS(image, i - 1, j, newColor, orgColor);
        DFS(image, i, j - 1, newColor, orgColor);
        DFS(image, i + 1, j, newColor, orgColor);
        DFS(image, i, j + 1, newColor, orgColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        DFS(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
