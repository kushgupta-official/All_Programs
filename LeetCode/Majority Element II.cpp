class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=v.size();
        int ele1=-1,ele2=-1,c1=0,c2=0;
        for (auto i:v){
            if (ele1==i){
                c1++;
            }
            else if (ele2==i){
                c2++;
            }
            else if (c1==0){
                ele1=i;
                c1++;
            }
            else if (c2==0){
                ele2=i;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for (auto i:v){
            if (i==ele1){
                c1++;
            }
            else if (i==ele2){
                c2++;
            }
        }
        vector <int> res;
        if (c1>n/3){
            res.push_back(ele1);
        }
        if (c2>n/3){
            res.push_back(ele2);
        }
        return res;
    }
};