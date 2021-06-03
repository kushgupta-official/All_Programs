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
    vector <int> inOrder;
    unordered_map <int,int> ump;
public:
    void in (TreeNode* root){
        if (!root)
            return;
        in(root->left);
        inOrder.push_back(root->val);
        in(root->right);
    }
    void dfs(TreeNode* root){
        if (!root){
            return;
        }
        root->val=ump[root->val];
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        in(root);
        for (int i=inOrder.size()-2;i>=0;i--){
            int temp=inOrder[i]+inOrder[i+1];
            ump[inOrder[i]]=temp;
            inOrder[i]=temp;
        }
        ump[inOrder[inOrder.size()-1]]=inOrder[inOrder.size()-1];
        dfs(root);
        return root;
    }
};