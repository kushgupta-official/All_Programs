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
    unordered_map <int,int> ump;
    int i=0;
    TreeNode* solve(vector <int> &preorder,vector <int> &inorder,int start,int end){
            if (start>end){
                return NULL;
            }
            int v=preorder[i];
            TreeNode *node=new TreeNode(preorder[i++]);
            if (start==end){
                return node;    //for leaf node
            }
            node->left=solve(preorder,inorder,start,ump[v]-1);
            node->right=solve(preorder,inorder,ump[v]+1,end);
            return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0;i<inorder.size();i++){
            ump[inorder[i]]=i;
        }
        // TreeNode *root=new TreeNode(preorder[i++]);
        return solve(preorder,inorder,0,preorder.size()-1);
    }
};