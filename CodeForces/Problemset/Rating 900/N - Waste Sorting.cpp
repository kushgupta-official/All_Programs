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
        ll x,y,z;
        cin>>x>>y>>z;
        vll v(5);
        loop(i,0,5){
            cin>>v[i];
        }
        x-=v[0];
        y-=v[1];
        z-=v[2];
        if (x<0 or y<0 or z<0){
            cout<<"NO\n";
            continue;
        }
        if (x>0){
            v[3]-=x;
        }
        if (y>0){
            v[4]-=y;
        }
        if (v[3]>0 and z>0){
            z-=v[3];
            if (z>=0){
                v[3]=0;
            }
        }
        if (v[4]>0 and z>0){
            z-=v[4];
            if (z>=0){
                v[4]=0;
            }
        }
        if (x>=0 and y>=0 and z>=0 and v[3]<=0 and v[4]<=0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
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