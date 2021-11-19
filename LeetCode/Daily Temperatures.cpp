class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> stack;
        int n=temperatures.size();
        vector <int> res(n);
        for (int i=n-1;i>=0;i--){
            while(!stack.empty() and temperatures[stack.top()]<=temperatures[i]){
                stack.pop();
            }
            res[i]=stack.empty() ? 0 : stack.top()-i;
            stack.push(i);
        }
        return res;
    }
};