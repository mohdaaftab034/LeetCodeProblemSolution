// LeetCode Link - https://leetcode.com/problems/validate-binary-search-tree/description/?utm=codolio



// -------------------Solution -> 1--------------------
class Solution {
public:

    bool isBST(TreeNode* root, long min, long max) {
        // Base case
        if(root == NULL) {
            return true;
        }

        // second base case
        if(root -> val <= min && root -> val >= max) {
            return false;
        }

        // validate BST
        if(root -> val > min && root -> val < max) {
            bool left = isBST(root -> left, min, root -> val);
            bool right = isBST(root -> right, root -> val, max);

            return left && right;
        } else {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        
        return isBST(root, LONG_MIN, LONG_MAX);

    }
};
