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
    void dfs(TreeNode* node,int dig,int &sum){
        if (!node){
            return;
        }
        if (!node->left and !node->right){
            dig=dig*10+node->val;
            sum+=dig;
            return;
        }
        dfs(node->left,dig*10+node->val,sum);
        dfs(node->right,dig*10+node->val,sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        dfs(root,0,sum);
        return sum;
    }
};