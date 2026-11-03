class Solution {
private:
    int maxLength = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftLen = dfs(node->left);
        int rightLen = dfs(node->right);

        int arrowLeft = 0;
        int arrowRight = 0;

        if (node->left && node->left->val == node->val) {
            arrowLeft = leftLen + 1;
        }
        if (node->right && node->right->val == node->val) {
            arrowRight = rightLen + 1;
        }

        // Update the global maximum path passing through the current node
        maxLength = max(maxLength, arrowLeft + arrowRight);

        // Return the maximum extension length that can be continued upwards
        return max(arrowLeft, arrowRight);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        maxLength = 0;
        dfs(root);
        return maxLength;
    }
};