
class Solution {
public:
    TreeNode* dummy = new TreeNode(-1);
    TreeNode* curr = dummy;

    void inorder(TreeNode* root) {

        if (root == NULL) {
            return;
        }

        inorder(root->left);

        // Connect current node
        root->left = NULL;
        curr->right = root;
        curr = root;

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {

        inorder(root);

        return dummy->right;
    }
};
