/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector <TreeNode*> p_path;
    vector <TreeNode*> q_path;
    bool dfs(TreeNode* root, TreeNode* p, vector <TreeNode*> &temp){
        temp.push_back(root);
        if (root==p){
            return true;
        }
        if ((root->left and dfs(root->left,p,temp))
             or
           (root->right and dfs(root->right,p,temp))){
            return true;
        }
        temp.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,p_path);
        dfs(root,q,q_path);
        int i;
        for (i=0;i<min(p_path.size(),q_path.size());i++){
            if (p_path[i]!=q_path[i])
                return p_path[i-1];
        }
        return p_path[i-1];
    }
};