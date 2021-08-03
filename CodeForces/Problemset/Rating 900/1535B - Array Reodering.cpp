# include <bits/stdc++.h>
# define ll long long int
using namespace std;

void kush_gupta(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

bool comp(ll i,ll j){
    return i%2<j%2;
}

int main(){
    kush_gupta();
    ll t=0;
    cin>>t;
    while(t--){
        ll n=0;
        cin>>n;
        vector <ll> v(n);
        for (ll i=0;i<n;i++){
            cin>>v[i];
        }
        ll res=0;
        sort(v.begin(), v.end(),comp);
        for (ll i=0;i<n;i++){
            for (ll j=i+1;j<n;j++){
                if (__gcd(v[i],2*v[j])>1){
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}