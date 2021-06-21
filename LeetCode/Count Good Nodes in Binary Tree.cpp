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
    int res=0;
    void dfs(TreeNode *root,int mx){
        if (root->val >= mx){
            mx=root->val;
            res++;
        }
        if (root->left)
            dfs(root->left,mx);
        if (root->right)
            dfs(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return res;
    }
};