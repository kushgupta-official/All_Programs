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
    int deepestLeavesSum(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        // vector <vector <int> > res;
        int toReturn=0;
        while(!q.empty()){
            // vector <int> level;
            toReturn=0;
            int n=q.size();
            for (int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                toReturn+=curr->val;
                // level.push_back(curr->val);
                if (curr->left!=NULL)
                    q.push(curr->left);
                if (curr->right!=NULL)
                    q.push(curr->right);
            }
            // res.push_back(level);
        }
        
//         for (int i=res.size()-1,j=0 ; j<res[res.size()-1].size() ; j++){
//             toReturn+=res[i][j];
//         }
        return toReturn;
    }
};