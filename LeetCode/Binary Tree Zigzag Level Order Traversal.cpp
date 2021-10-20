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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int> > res;
        if (!root)
            return res;
        queue <TreeNode*> q;
        q.push(root);
        bool isLtoR=1;
        while(!q.empty()){
            int s=q.size();
            vector <int> v(s);
            for (int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                isLtoR==1?v[i]=curr->val:v[s-i-1]=curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            res.push_back(v);
            isLtoR=!isLtoR;
        }
        return res;
    }
};