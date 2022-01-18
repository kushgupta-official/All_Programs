class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int s) {
        if (s==0)
            return true;
        int n=flowerbed.size();
        int sz=0;
        bool isThereOne=0;
        for (int i=0;i<n;i++){
            // cout<<s<<endl;
            if (flowerbed[i]==0){
                sz++;
            }
            else{
                if (sz&1){
                    s-=sz/2;
                }
                else if (sz){
                    if (!isThereOne){
                        s-=sz/2;
                    }
                    else{
                        s-=sz/2-1;
                    }
                }
                sz=0;
                isThereOne=true;
            }
        }
        // cout<<s<<endl;
        if (!isThereOne or sz>1){
            s-=ceil(sz/2.0);
        }
        if (!isThereOne and n==1){
            s--;
        }
        if (s<=0){
            return true;
        }
        return false;
    }
};