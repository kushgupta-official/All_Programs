class Solution {
public:
    vector <vector <int> > dp;
    int solve(vector<int>& stones,int sum,int l,int r){
        if (l>=r){
            return 0;
        }
        if (dp[l][r]!=-1){
            return dp[l][r];
        }
        return dp[l][r]=max(sum-stones[l]-solve(stones,sum-stones[l],l+1,r), 
                            sum-stones[r]-solve(stones,sum-stones[r],l,r-1));
    }
    int stoneGameVII(vector<int>& stones) {
        int s=0;
        dp.resize(stones.size(),vector <int> (stones.size(),-1));
        for(int i=0;i<stones.size();i++){
            s+=stones[i];
        }
        return solve(stones,s,0,stones.size()-1);
    }
};