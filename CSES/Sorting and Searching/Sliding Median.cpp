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
    ll n=0,k=0;
    cin>>n>>k;
    vll v(n);
    loop(i,0,n){
        cin>>v[i];
    }
    multiset <ll> ls,rs;
    ll p,q;
    if (k%2==0){
        p=k/2;
        q=k/2;
    }
    else{
        p=ceil(k/2.0);
        q=k/2;
    }
    for (ll i=0;i<k;i++){
        ls.insert(v[i]);
    }
    for (ll i=0;i<q;i++){
        rs.insert(*ls.rbegin());
        ls.erase(ls.find(*ls.rbegin()));
    }
    cout<<*ls.rbegin()<<" ";
    for(ll i=k,j=0;i<n;i++,j++){
        if (v[i]>*ls.rbegin()){
            rs.insert(v[i]);
        }
        else{
            ls.insert(v[i]);
        }
        if (ls.find(v[j])!=ls.end()){
            ls.erase(ls.find(v[j]));
        }
        else{
            rs.erase(rs.find(v[j]));
        }
        while(ls.size()>p){
            rs.insert(*ls.rbegin());
            ls.erase(ls.find(*ls.rbegin()));
        }
        while(rs.size()>q){
            ls.insert(*rs.begin());
            rs.erase(rs.find(*rs.begin()));
        }
        cout<<*ls.rbegin()<<" ";
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