// LeetCode Link - https://leetcode.com/problems/binary-tree-level-order-traversal/description


// Level Order Traversal 

// Code

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            // Iterate all the nodes present in the queue
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop(); // Remove the front node from the queue

                if(node -> left != NULL)
                    q.push(node -> left);
                
                if(node -> right != NULL)
                    q.push(node -> right);
                
                level.push_back(node -> val);
            }
            ans.push_back(level);
        }
        return ans; 
    }
};
