class Solution {
private:
    int minDiff = INT_MAX;
    int prevVal = -1;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        if (prevVal != -1) {
            minDiff = min(minDiff, node->val - prevVal);
        }
        prevVal = node->val;

        inorder(node->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        minDiff = INT_MAX;
        prevVal = -1;
        inorder(root);
        return minDiff;
    }
};