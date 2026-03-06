// LeetCode Link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/?utm=codolio


// ------------------Solution - 1---------------------
class Solution {
public:

    int solve(TreeNode* root, int& i, int k) {
        if(root == NULL) return -1;

        int left = solve(root -> left, i, k);

        if(left != -1) {
            return left;
        }

        i++;
        if(i == k) {
            return root -> val;
        }

        return solve(root -> right, i, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int ans =  solve(root, i, k);
        return ans;

    }
};


// ------------------Solution -> 2---------------------
class Solution {
public:

    void inorder(TreeNode* root, vector<int>& ans) {

        // base case
        if(root == NULL) {
            return ;
        }

        inorder(root -> left, ans);
        ans.push_back(root -> val);
        inorder(root -> right, ans);

    }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> ans;

        inorder(root, ans);

        return ans[k-1];
    }
};
