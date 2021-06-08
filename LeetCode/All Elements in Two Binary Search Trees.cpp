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
    void inorder(TreeNode* root, vector <int> &v){
        if (!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector <int> res1,res2;
        inorder(root1,res1);
        inorder(root2,res2);
        vector <int> res;
        int i=0,j=0;
        while(i<res1.size() && j<res2.size()){
            if (res1[i]<res2[j]){
                res.push_back(res1[i]);
                i++;
            }
            else{
                res.push_back(res2[j]);
                j++;
            }
        }
        while(i<res1.size()){
            res.push_back(res1[i++]);
        }
        while(j<res2.size()){
            res.push_back(res2[j++]);
        }
        return res;
    }
};