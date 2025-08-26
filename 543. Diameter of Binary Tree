// LeetCode Link - "https://leetcode.com/problems/diameter-of-binary-tree/description"
//Topic - Binary Tree


// Approach1 - 
class Solution {
public:

    int height(TreeNode *root){
        if(root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        int currDiameter = height(root->left) + height(root->right);

        return max(currDiameter, max(leftDiameter, rightDiameter));
    }
};


//Approach2 - 
class Solution {
public:
    int ans = 0;
    int height(TreeNode *root){
        if(root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        ans = max(ans, leftHeight + rightHeight); 

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        height(root);

        return ans;
    }
};
