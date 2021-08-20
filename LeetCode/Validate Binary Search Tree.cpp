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
    bool isValidBST(TreeNode* root, long mn=LONG_MIN, long mx=LONG_MAX) {
        if (!root){
            return true;
        }
        if ((long long)root->val>mn and (long long)root->val<mx){
            return (isValidBST(root->left,mn,(long long)root->val) && 
                    isValidBST(root->right,(long long)root->val,mx) );
        }
        else{
            return false;
        }
    }
};