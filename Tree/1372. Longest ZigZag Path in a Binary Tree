// LeetCode Link - "https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description"

// Approach - 1

class Solution {
public:

    void solve(TreeNode* root, int steps, bool goLeft, int& maxPath) {

        if(root == NULL) 
            return;

        maxPath = max(maxPath, steps);

        if(goLeft == true) { // Ge Left

            solve(root->left, steps + 1, false, maxPath);
            solve(root->right, 1, true, maxPath);

        } else { // Go Right

            solve(root->right, steps + 1, true, maxPath);
            solve(root->left, 1, false, maxPath);

        }
    }

    int longestZigZag(TreeNode* root) {
        int maxPath = 0;

        solve(root, 0, true, maxPath);
        solve(root, 0, false, maxPath);

        return maxPath;
    }
};



// Approach - 2

class Solution {
public:

    void solve(TreeNode* root, int left, int right, int& maxPath) {

        if(root == NULL) 
            return;

        maxPath = max({maxPath, left, right});

        solve(root->left, right + 1, 0, maxPath);
        
        solve(root->right, 0, left + 1, maxPath);
    }

    int longestZigZag(TreeNode* root) {
        int maxPath = 0;

        solve(root, 0, 0, maxPath);

        return maxPath;
    }
};
