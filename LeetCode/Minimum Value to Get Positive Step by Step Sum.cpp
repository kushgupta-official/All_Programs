class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sv=0;
        int sum=0;
        for (auto i:nums){
            sum+=i;
            if (sum<1){
                sv+=1-(sum);
                sum+=1-(sum);
            }
        }
        if (sv==0){
            sv=1;
        }
        return sv;
    }
};