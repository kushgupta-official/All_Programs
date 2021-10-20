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
    int sol;
    int maxPathSum(TreeNode* root) {
        sol=-1001;
        solve(root);
        return sol;
    }
    int solve(TreeNode *node){
        if (!node)
            return 0;
        int lh=max(0,solve(node->left));
        int rh=max(0,solve(node->right));
        sol=max(sol,node->val+lh+rh);
        return node->val+max(lh,rh);
    }
};