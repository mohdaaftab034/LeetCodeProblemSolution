class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        
        long long min1 = root->val;
        long long min2 = -1;
        
        dfs(root, min1, min2);
        
        return min2;
    }

private:
    void dfs(TreeNode* node, long long min1, long long &min2) {
        if (!node) return;
        
        // If we find a value strictly greater than min1 and smaller than current min2
        if (node->val > min1 && (min2 == -1 || node->val < min2)) {
            min2 = node->val;
        }
        
        // Optimization: if current node's value is already greater than min2 and min2 != -1, 
        // we can still explore, but if it equals min1 we continue to find the second minimum.
        if (node->val == min1) {
            dfs(node->left, min1, min2);
            dfs(node->right, min1, min2);
        }
    }
};