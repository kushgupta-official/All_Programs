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
        ll n;
        cin>>n;
        vll a(n);
        set <ll> sn;//,sp;
        ll countZero=0;
        ll countNegative=0;
        ll mnPos=INT_MAX;
        loop(i,0,n){
            cin>>a[i];
            if (a[i]>0){
                // sp.insert(a[i]);
                mnPos=min(mnPos,a[i]);
            }
            else if (a[i]<0){
                sn.insert(abs(a[i]));
                countNegative++;
            }
            else{
                countZero++;
            }
        }
        ll res=countNegative+countZero;
        ll mnAbsDiff=INT_MAX;
        
        if (mnPos!=INT_MAX and countZero<=1 and 
            countZero+countNegative>=2 and 
            countNegative==sn.size())
        {
            if (countZero)
                sn.insert(0);
            ll pre=*sn.begin();
            for (auto ite=++sn.begin();ite!=sn.end();ite++){
                mnAbsDiff=min(mnAbsDiff,abs(*ite-pre));
                pre=*ite;
            }
            // cout<<mnAbsDiff<<endl;
            if (mnPos<=mnAbsDiff){
                // cout<<abs(*sn.begin()-*(++sn.begin()))<<endl;
                res++;
            }
        }
        if (countZero==0 and countNegative==1 and mnPos!=INT_MAX){
            res=countNegative+1;
        }
        else if (countNegative==0 and countZero==1 and mnPos!=INT_MAX){
            res=2;
        }
        cout<<max(res,(ll)1)<<endl;
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