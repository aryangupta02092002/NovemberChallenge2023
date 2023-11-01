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
    void inorder(TreeNode *root, vector<int> &in){
        if(!root){
            return;
        }
        in.push_back(root->val);
        inorder(root->left, in);
        inorder(root->right, in);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        unordered_map<int, int> u;
        int mx = 0;

        for(int val : in){
            u[val]++;
            mx = max(mx, u[val]);
        }

        vector<int> ans;
        for(auto &it : u){
            if(it.second == mx){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
