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
    // vector <int> v;
    vector<vector<int>> res;
    
    void dfs(TreeNode *root,int targetSum,vector <int> &v){
        v.push_back(root->val);
        targetSum-=root->val;
        if (!root->left and !root->right and targetSum==0){
            res.push_back(v);
        }
        if (root->left){
            dfs(root->left,targetSum,v);
        }
        if (root->right){
            dfs(root->right,targetSum,v);
        }
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector <int> v;
        if (!root){
            return res;
        }
        dfs(root,targetSum,v);
        return res;
    }
};