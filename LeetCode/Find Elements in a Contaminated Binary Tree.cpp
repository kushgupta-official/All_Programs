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
class FindElements {
public:
    unordered_set <int> s;
    void dfs(TreeNode *root,int val){
        if (root==NULL){
            return;
        }
        s.insert(val);
        root->val=val;
        dfs(root->left,root->val*2+1);
        dfs(root->right,root->val*2+2);
    }
    FindElements(TreeNode* root) {
        root->val=0;
        dfs(root,0);
    }
    
    bool find(int target) {
        if (s.count(target)){
            return 1;
        }
        return 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
