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
//5 2 2
void kush_gupta_solves(){
    ll n,k,x;
    cin>>n>>k>>x;
    vll v(n);
    loop(i,0,n){
        cin>>v[i];
    }
    ll grps=1;
    sort(v.begin(), v.end());
    priority_queue <ll,vector <ll>,greater <ll> > pq;
    for (ll i=1;i<n;i++){
        if (v[i]-v[i-1]>x){
            grps++;
            pq.push(v[i]-v[i-1]);
        }
    }
    while(!pq.empty() and k>0){
        ll req=pq.top()/x;
        if (pq.top()%x==0)
            req--;
        if (req<=k){
            k-=req;
            grps--;
            pq.pop();
        }
        else{
            break;
        }
    }
    cout<<grps<<endl;
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