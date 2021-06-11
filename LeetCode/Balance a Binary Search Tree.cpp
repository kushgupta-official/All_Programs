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
    vector <TreeNode*> inorder;
    
    void calculateInorder(TreeNode* root){
        if (!root)
            return;
        calculateInorder(root->left);
        inorder.push_back(root);
        calculateInorder(root->right);
    }
    TreeNode* solve(int start,int end){
        if (start>end){
            return NULL;
        }
        int mid=end+(start-end)/2;
        TreeNode *root=inorder[mid];
        root->left=solve(start,mid-1);
        root->right=solve(mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        calculateInorder(root);
        return solve(0,inorder.size()-1);
    }
};