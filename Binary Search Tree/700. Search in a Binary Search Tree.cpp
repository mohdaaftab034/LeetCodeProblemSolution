// LeetCode Link - https://leetcode.com/problems/search-in-a-binary-search-tree/description/?utm=codolio



// ------------------Solution ----------------------
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case
        if(root == NULL || root -> val == val) {
            return root;
        }

        // left call
        if(root -> val > val) {
            return searchBST(root -> left, val);
        }
        // right call
        else {
            return searchBST(root -> right, val);
        }

    }
};
