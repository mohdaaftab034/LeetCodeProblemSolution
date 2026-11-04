class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        // Traverse left subtree
        inorder(root->left);

        // Find the swapped nodes by checking the inorder sequence
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev; // First violation: record the larger element
            }
            second = root;    // Second violation: record the smaller element
        }
        prev = root;

        // Traverse right subtree
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        // Swap the values of the two incorrectly placed nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};