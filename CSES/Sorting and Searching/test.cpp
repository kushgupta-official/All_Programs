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
    ll n=0;
    cin>>n;
    vll v(n);
    for (ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll lo=0,hi=n-1;
    while(lo<=hi){
        ll m=lo+(hi-lo)/2;
        // cout<<lo<<" "<<hi<<endl;
        if (hi==lo){
            cout<<lo<<endl;
            break;
        }
        if (v[m]<v[m-1]){
            cout<<m<<endl;
            break;
        }
        if (v[m+1]<v[m]){
            cout<<m+1<<endl;
            break;
        }
        if (v[m]>v[hi]){
            // cout<<"hi";
            lo=m+1;
        }
        else{
            // cout<<v[m]<<endl;
            hi=m-1;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        auto __start = chrono::high_resolution_clock::now(); 
        freopen("input.txt", "r", stdin) ;
          freopen("output.txt", "w", stdout) ;
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    kush_gupta_solves();

    #ifndef ONLINE_JUDGE
        auto __end = chrono::high_resolution_clock::now(); 
        double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
        __time_taken *= 1e-9; 
        cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
        cout << " sec" << endl;
    #endif

    return 0;
}