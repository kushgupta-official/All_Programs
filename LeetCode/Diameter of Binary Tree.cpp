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
    int diameter;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter=0;
        solve(root);
        return diameter;
    }
    int solve(TreeNode* node){
        if (!node)
            return 0;
        int lh=solve(node->left);
        int rh=solve(node->right);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
};