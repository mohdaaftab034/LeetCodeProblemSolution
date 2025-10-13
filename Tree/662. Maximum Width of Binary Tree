// LeetCode Link - "https://leetcode.com/problems/maximum-width-of-binary-tree"



class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> que;
        int maxWidth = 0;

        que.push({root, 0});

        while (!que.empty()) {
            unsigned long long L = que.front().second;
            unsigned long long R = que.back().second;

            maxWidth = max(maxWidth, int(R - L + 1));

            int n = que.size();

            while (n--) {
                TreeNode* curr = que.front().first;
                unsigned long long idx = que.front().second - L; // normalize
                que.pop();

                if (curr->left)
                    que.push({curr->left, 2 * idx + 1});
                if (curr->right)
                    que.push({curr->right, 2 * idx + 2});
            }
        }

        return maxWidth;
    }
};
