// LeetCode Link - https://leetcode.com/problems/minimum-depth-of-binary-tree/description/




// ------------------Solution--------------------
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        queue<pair<TreeNode*, int>> que;
        que.push({root, 1});

        while(!que.empty()) {
            auto front = que.front();
            que.pop();

            TreeNode* node = front.first;
            int depth = front.second;

            if(node -> left == NULL && node -> right ==  NULL) {
                return depth;
            }

            if(node -> left) {
                que.push({node -> left, depth + 1});
            } 
            
            if(node -> right) {
                que.push({node -> right, depth + 1});
            }
        }
        return 0;
    }
};


// ----------------------Solution-----------------------
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        if(root->left == NULL)
            return 1 + minDepth(root->right);

        if(root->right == NULL)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
