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

ll n;
vector <vector <ll> > v;
vector <ll> ans;

pair <ll,ll> bfs(ll curr){
    vector <bool> vis(n+1,false);
    queue <pair <ll,ll> > q;
    q.push({curr,0});
    vis[curr]=true;
    pair <ll,ll> u;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for (auto ite:v[u.first]){
            if (vis[ite])
                continue;
            vis[ite]=true;
            q.push({ite,u.second+1});
            ans[ite]=max(ans[ite],u.second+1);
        }
    }
    return u;
}

void kush_gupta_solves(){
    cin>>n;
    v.resize(n+1);
    ans.resize(n+1,0);
    for (ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    pair <ll,ll> u=bfs(1);
    pair <ll,ll> first_end=bfs(u.first);
    pair <ll,ll> second_end=bfs(first_end.first);
    loop(i,1,n+1){
        cout<<ans[i]<<" ";
    }
    // cout<<ans.second;
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