// LeetCode Link - https://leetcode.com/problems/delete-node-in-a-bst/description/?utm=codolio


// ----------------Solution-------------------
class Solution {
public:
    TreeNode* minValue(TreeNode* root) {
        TreeNode* temp = root;

        while (temp->left != NULL) {
            temp = temp->left;
        }

        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case ---> if key is not present in BST
        if (root == NULL) {
            return root;
        }

        // Second base case ---> if key is present in BST
        if (root->val == key) {
            // delete node

            // If left of root and right of root is equal to NULL
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // if left of root is not NULL and right of root is NULL
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // if left of root is NULL and right of root is not null
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // if left of root is not null and right of root is not NULL
            if (root->left != NULL && root->right != NULL) {
                int mini = minValue(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }

        // left call
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else {
            root->right = deleteNode(root->right, key);
            return root;
        }
    }
};
