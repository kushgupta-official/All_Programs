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
    void solve(TreeNode* root,int level,int &mxLevel,int &res){
        if (!root)
            return;
        if (level>mxLevel){
            mxLevel=level;
            res=root->val;
        }
        solve(root->left,level+1,mxLevel,res);
        solve(root->right,level+1,mxLevel,res);
    }
    int findBottomLeftValue(TreeNode* root) {
        int res=0;
        int mxLevel=0;
        solve(root,1,mxLevel,res);
        return res;
    }
};