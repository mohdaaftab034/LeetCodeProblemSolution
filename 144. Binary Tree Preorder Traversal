// LeetCode Link - "https://leetcode.com/problems/binary-tree-preorder-traversal/description"
// Topic - Binary Tree

class Solution {
public:

    void preOrderTraversal(TreeNode* root, vector<int> & result) {
        if(root == NULL) {
            return;
        }

        result.push_back(root->val); // Visited
        preOrderTraversal(root->left, result);
        preOrderTraversal(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> result;

        preOrderTraversal(root, result);

        return result;
    }
};
