// LeetCode Link - "https://leetcode.com/problems/binary-tree-maximum-path-sum/description"
// Topic - Binary Tree
// Variable name thode funny hai but only see the Approach

class Solution {
public:

    int maxSum;

    int solve(TreeNode * root) {
        if(root == NULL){
            return 0;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        int neeche_hi_milgaya_answer = left + right + root->val; //(1)

        int koi_ek_achha = max(left, right) + root->val;//(2)

        int only_root_achha = root->val;//(3)

        maxSum = max({maxSum, koi_ek_achha, only_root_achha, neeche_hi_milgaya_answer});

        return max(koi_ek_achha, only_root_achha);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        solve(root);

        return maxSum;
    }
};
