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

bool comp(pair <ll,ll> p1, pair <ll,ll> p2){
    if (p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second<p2.second;
}

void kush_gupta_solves(){
    ll n=0,k=0;
    cin>>n>>k;
    vp v(n);
    loop(i,0,n){
        cin>>v[i].first;
        cin>>v[i].second;
    }
    sort(v.begin(), v.end(),comp);
    multiset <ll> s;
    for (ll i=0;i<k;i++){
        s.insert(0);
    }
    ll res=0;
    for (ll i=0;i<n;i++){
        if (s.lower_bound(-(v[i].first))!=s.end()){
            s.erase(s.lower_bound(-(v[i].first)));
            s.insert(-v[i].second);
            res++;
        }
    }
    cout<<res;
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