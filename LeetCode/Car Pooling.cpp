class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        int s=0;
        vector <pair <int,int> > st,end;
        for (int i=0;i<n;i++){
            st.push_back({trips[i][1],trips[i][0]});
            end.push_back({trips[i][2],trips[i][0]} );
        }
        sort(st.begin(),st.end());
        sort(end.begin(),end.end());
        
        int i=0,j=0;
        while(i<n){
            if (st[i].first<end[j].first){
                s+=st[i].second;
                i++;
            }
            else{
                s-=end[j].second;
                j++;
            }
            if (s>capacity){
                return 0;
            }
        }
        return 1;
    }
};