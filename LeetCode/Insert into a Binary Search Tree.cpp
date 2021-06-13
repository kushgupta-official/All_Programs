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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *toReturn=root;
        TreeNode *t=new TreeNode(val);
        if (root==NULL){
            return t;
        }
        while(1){
            if (root->val > val){
                if (root->left){
                    root=root->left;
                }
                else{
                    root->left=t;
                    break;
                }
            }
            else{
                if (root->right){
                    root=root->right;
                }
                else{
                    root->right=t;
                    break;
                }
            }
        }
        return toReturn;
        
    }
};