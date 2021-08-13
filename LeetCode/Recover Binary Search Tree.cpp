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
    TreeNode *first,*second,*prevNode;
    void inorder(TreeNode* root){
        if (!root)
            return;
        inorder(root->left);
        if (prevNode!=NULL and prevNode->val > root->val){
            if (first==NULL)
                first=prevNode;
            second=root;
        }
        prevNode=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=second=prevNode=NULL;
        inorder(root);
        swap(first->val,second->val);
    }
};