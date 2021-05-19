# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp> 
# include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

# define ll long long
# define ld long double
# define loop(i,a,b) for(ll i=a;i<b;i++)
# define vi vector<int>
# define vll vector<ll>
# define vvl vector<vector <ll> >
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'
# define mid(l,r) l+(r-l)/2
# define fi first
# define se second

template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void kush_gupta_solves(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    ll k=0;
    cin>>k;
    ll required_steps=0;
    if (t[0]!=s[0]){
        required_steps=t.size()+s.size();
    }
    else{
        ll i=0;
        for (i=1;i<t.size();i++){
            if (i==s.size() or t[i]!=s[i])
                break;
        }
        required_steps=(t.size()-i)+(s.size()-i);
    }
    if (required_steps==k or k>=t.size()+s.size()){
        cout<<"Yes";
    }
    else if (k>required_steps){
        while(k>required_steps){
            k-=2;
            if (k==required_steps){
                cout<<"Yes";
                break;
            }
        }
        if (k<required_steps){
            cout<<"No";
        }

    }
    else{
        cout<<"No";
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    kush_gupta_solves();


    return 0;
}
