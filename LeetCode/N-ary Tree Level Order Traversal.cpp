/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector <vector <int> > res;
        if (!root)
            return res;
        queue <Node*> q;
        q.push(root);
        while(!q.empty()){
            int l=q.size();
            vector <int> temp;
            for (int i=0;i<l;i++){
                Node *t=q.front();
                temp.push_back(t->val);
                q.pop();
                for (auto ite:t->children){
                    q.push(ite);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};