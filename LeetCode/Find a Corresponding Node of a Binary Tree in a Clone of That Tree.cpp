/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue <TreeNode*> q1;
        q1.push(original);
        queue <TreeNode*> q2;
        q2.push(cloned);
        while(!q1.empty()){
            TreeNode* t1=q1.front();
            TreeNode* t2=q2.front();
            if (t1==target){
                return t2;
            }
            q1.pop();q2.pop();
            if (t1->left){
                q1.push(t1->left);
                q2.push(t2->left);
            }
            if (t2->right){
                q1.push(t1->right);
                q2.push(t2->right);
            }
            
        }
        return NULL;
    }
};