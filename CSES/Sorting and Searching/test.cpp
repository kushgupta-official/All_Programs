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
    w(t){
        ll n=0,k=0;
        cin>>n>>k;
        vp v(n);
        unordered_map <ll,ll> mp;
        loop(i,0,n){
            cin>>v[i].first;
            v[i].second=i;
            mp[v[i].first]++;
        }
        ll res=0;
        ll x=0;
        vll arr;
        for (auto ite:mp){
            if (ite.second>=k){
                res++;
                mp[ite.first]=1;
            }
            else{
                x+=ite.second;
                arr.push_back(ite.first);
            }
        }
        res+=x/k;
        // cout<<res<<endl;
        loop(i,0,arr.size()){
            cout<<arr[i]<<" y ";
        }
        cout<<endl;
        vp temp=v;
        sort(temp.begin(), temp.end());
        x=1;
        loop(i,0,n){
            if (x==k+1){
                x=1;
            }
            // cout<<temp[i].second<<" ";
            if (x==1 and i>0 and temp[i].first==temp[i-1].first){
                // x=1;
                // cout<<"y";
                v[temp[i].second].first=0;
            }
            else{
                v[temp[i].second].first=x;
                x++;
            }
            // v[temp[i].second].first=temp[i].first;
        }
        // cout<<endl;
        loop(i,0,n){
            cout<<v[i].first<<" ";
        }
        cout<<endl;
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