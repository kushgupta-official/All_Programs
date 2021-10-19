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
    int solve(TreeNode *node){
        if (!node)
            return 0;
        int lt=solve(node->left);
        int rt=solve(node->right);
        if (lt==-1 or rt==-1)
            return -1;
        if (abs(lt-rt)>1)
            return -1;
        return 1+max(lt,rt);
    }
    bool isBalanced(TreeNode* root) {
        if (solve(root)!=-1)
            return true;
        else
            return false;
    }
};