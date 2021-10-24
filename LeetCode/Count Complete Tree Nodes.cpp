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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int ln=0,rn=0;
        TreeNode *l=root,*r=root;
        while(l){
            ln++;
            l=l->left;
        }
        while(r){
            rn++;
            r=r->right;
        }
        if (ln==rn){
            return pow(2,ln)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};