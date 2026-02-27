// LeetCode Link - "https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description"
// Topic - Binary Tree

class Solution {
public:

    long SUM = 0;
    long maxP = 0; 
    int totalSum(TreeNode * root){
        if(root == NULL) return 0;

        int leftTreeSum  = totalSum(root->left);
        int rightTreeSum = totalSum(root->right);

        int SUM = root->val + leftTreeSum + rightTreeSum;

        return SUM;
    }

    int find(TreeNode * root){
        if(root == NULL) return 0;

        int leftSubTreeSum = find(root->left);
        int rightSubTreeSum = find(root->right);
        long subTreeSum = root->val + leftSubTreeSum + rightSubTreeSum;

        long remainingSubTreeSum = SUM - subTreeSum;

        maxP = max(maxP, subTreeSum * remainingSubTreeSum);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0;

        maxP = 0;
        SUM = totalSum(root);

        find(root);

        return maxP%(1000000007);
    }
};
