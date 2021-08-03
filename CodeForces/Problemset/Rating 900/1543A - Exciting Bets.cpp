# include <bits/stdc++.h>
# define ll long long int
using namespace std;

void kush_gupta(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int main(){
    kush_gupta();
    ll t=0;
    cin>>t;
    while(t--){
        ll a=0,b=0;
        cin>>a>>b;
        cout<<abs(a-b)<<" ";
        ll x=0;
        if (abs(a-b)==0){
            cout<<0<<endl;
            continue;
        }
        x=min(a%abs(a-b),abs(a-b)-a%abs(a-b));
        x=min(x,min(a,b));
        cout<<x<<endl;
    }
    return 0;
}