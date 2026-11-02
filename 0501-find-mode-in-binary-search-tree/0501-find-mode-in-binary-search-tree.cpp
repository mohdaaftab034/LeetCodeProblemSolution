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
    std::vector<int> elements;
    void inorder(TreeNode* root){
        if(root!=nullptr){
            inorder(root->left);
            elements.push_back(root->val);
            inorder(root->right);
        }
    }
public:
    vector<int> findMode(TreeNode* root) {
        std::vector<int> ans;
        inorder(root);
        int max=0,count=0,prev;
        for(int i=0;i<elements.size();++i){
            if(i==0||elements[i]==prev){
                count++;
                if(count==max){
                    ans.push_back(elements[i]);
                }
                if(count>max){
                    max=count;
                    ans.clear();
                    ans.push_back(elements[i]);
                }
            }
            else{
                count=1;
                if(count==max){
                    ans.push_back(elements[i]);
                }
            }
            prev=elements[i];
        }
        return ans;
    }
};