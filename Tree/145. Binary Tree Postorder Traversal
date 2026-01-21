// LeetCode Link - https://leetcode.com/problems/binary-tree-postorder-traversal/description


// Iterative Post Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans; // Take the vector array for return the answer

        if(root == NULL) return ans;

        st.push(root);  // Push the root node in the stack

        while(!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();  // Remove the top node from the stack

            ans.push_back(temp -> val);

            if(temp -> left != NULL) 
                st.push(temp -> left);

            if(temp -> right != NULL)
                st.push(temp -> right);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
