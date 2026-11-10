
class Solution {
public:
    Node* connect(Node* root) {

        if (root == nullptr) return root;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            Node* prev = nullptr;

            for (int i = 0; i < size; i++) {

                Node* curr = q.front();
                q.pop();

                // Connect previous node to current node
                if (prev != nullptr) {
                    prev->next = curr;
                }

                prev = curr;

                // Add left and right children
                if (curr->left) {
                    q.push(curr->left);
                }

                if (curr->right) {
                    q.push(curr->right);
                }
            }

            // Last node of each level points to NULL
            prev->next = nullptr;
        }

        return root;
    }
};
