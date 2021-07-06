class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map <int,int> mp;
        int n=arr.size();
        for (auto i:arr){
            mp[i]++;
        }
        vector <int> v;
        for (auto ite:mp){
            v.push_back(ite.second);
        }
        sort(v.begin(),v.end(),greater <int> () );
        int i=0,j=0;
        while(j<n/2){
            j+=v[i];
            i++;
        }
        return i;
    }
};