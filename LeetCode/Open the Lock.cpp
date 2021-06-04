class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector <bool> visited(10000,false);
        for (string s:deadends){
            visited[stoi(s)]=true;
        }
        if (visited[0]){
            return -1;
        }
        if (target=="0000"){
            return 0;
        }
        int t=stoi(target);
        queue <int> q;
        q.push(0);
        
        int res=0;
        while(!q.empty()){
            res++;
            int n=q.size();
            for (int i=0;i<n;i++){
                int curr=q.front();
                q.pop();
                for (int i=1;i<10000;i*=10){
                    int dig=curr%(i*10)/i;
                    int temp[2];
                    temp[0]=(curr-dig*i)+((dig+1)%10*i);
                    temp[1]=(curr-dig*i)+((dig+9)%10*i);
                    for (int j=0;j<2;j++){
                        if (temp[j]==t){
                            return res;
                        }
                        if (!visited[temp[j]]){
                            q.push(temp[j]);
                            visited[temp[j]]=true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};