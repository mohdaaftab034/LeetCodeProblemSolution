class Solution {
public:
    // Helper function to find nodes at exactly distance 'k' below a given root
    void find(TreeNode* root, int k, vector<int>& ans) {
        if (root == nullptr || k < 0)
            return;

        // Found a node at the required distance
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }

        // Continue searching downward
        find(root->left, k - 1, ans);
        find(root->right, k - 1, ans);
    }

    // Main DFS function to look for target and calculate distances from ancestors
    void dfs(TreeNode* root, TreeNode* target, int k,
             int& distance, bool& found, vector<int>& ans) {

        if (root == nullptr)
            return;

        // Base Case: Target node is found
        if (root == target) {
            found = true;
            distance = 0;
            find(root, k, ans); // Find all valid nodes below target
            return;
        }

        // Search in the left subtree
        dfs(root->left, target, k, distance, found, ans);

        // If target was found in the left subtree, we are now moving back up to an ancestor
        if (found) {
            distance++; // Increase distance from target to this ancestor

            // If the ancestor itself is at distance 'k'
            if (distance == k)
                ans.push_back(root->val);

            // Search the opposite (right) subtree for the remaining distance
            find(root->right, k - distance - 1, ans);
            return;
        }

        // Search in the right subtree
        dfs(root->right, target, k, distance, found, ans);

        // If target was found in the right subtree, we are now moving back up to an ancestor
        if (found) {
            distance++; // Increase distance from target to this ancestor

            // If the ancestor itself is at distance 'k'
            if (distance == k)
                ans.push_back(root->val);

            // Search the opposite (left) subtree for the remaining distance
            find(root->left, k - distance - 1, ans);
            return;
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        bool found = false;
        int distance = 0;

        // Start the DFS tracking from the root
        dfs(root, target, k, distance, found, ans);

        return ans;
    }
};