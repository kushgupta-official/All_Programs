class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        k--;
        vector <int> v;
        int fact=1;
        for (int i=1;i<n;i++){
            v.push_back(i);
            fact*=i;
        }
        v.push_back(n);
        while(true){
            ans+=to_string(v[k/fact]);
            v.erase(v.begin()+k/fact);
            if (!v.size()){
                break;
            }
            k%=fact;
            fact/=v.size();
        }
        return ans;
    }
};