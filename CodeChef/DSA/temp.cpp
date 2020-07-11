#include<bits/stdc++.h>
#define m 61
#define ii long long int
using namespace std;

int f[m];

int main(){
ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif

f[0]=0;
f[1]=1;
for(int i=2;i<m;i++)
    f[i]=(f[i-1]+f[i-2])%10;


int t;
ii n,r,ind;

cin>>t;
while(t--){
    cin>>n;

     r=0;

    while(n >0){
      r++;
      n=n/2;
    }
r--;


     ind=pow(2,r);
    ind=(ind-1)%60;
        //cout<<r<<" "<<ind;
    cout<<f[ind]<<endl;
}

return 0;
}
