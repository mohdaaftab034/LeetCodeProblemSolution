class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            // If the current node has a left child, find the rightmost node of the left subtree
            if (curr->left) {
                TreeNode* predecessor = curr->left;
                while (predecessor->right) {
                    predecessor = predecessor->right;
                }
                
                // Connect the right subtree of the current node to the rightmost node of the left subtree
                predecessor->right = curr->right;
                
                // Move the left subtree to the right side and set left to null
                curr->right = curr->left;
                curr->left = nullptr;
            }
            
            // Move to the next node on the right
            curr = curr->right;
        }
    }
};