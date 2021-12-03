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

    int checkBits(vector <int> &arr, int n, int pattern) {
       int cnt = 0;
       for (int i = 0; i < n; ++i) {
          if ((pattern & arr[i]) == pattern) {
             ++cnt;
          }
       }
       return cnt;
    }
    bool isKthBitSet(int n, int k){
        if ((n >> (k - 1)) & 1)
            return true;
        return false;
    }
    int maxAnd(int n, vector<int> v){
        // code here
        // int t=INT_MAX;
        // cout<<t<<endl;
        int cnt;
        int x=-1;
        int result=0;
        int sol=-1;
        for (int i = 31; i >= 0; --i) {
          cnt = checkBits(v, n, result | (1 << i));
          // if (cnt){
          //   cout<<i<<" "<<cnt<<endl;
          // }
          if (cnt==n-1){
            for (int j=0;j<n;j++){
                if (!isKthBitSet(v[j],i+1)){
                    // x=i;
                    // cout<<v[j]<<endl;
                    if (sol!=-1){
                        sol&=2147483647;
                    }
                    else{
                        sol=2147483647;
                    }
                }
                else{
                    if (sol!=-1){
                        sol&=v[j];
                    }
                    else{
                        sol=v[j];
                    }
                }
                // cout<<sol<<endl;
            }
            return sol;
          }
       }
       for (int j=0;j<n;j++){
            if (sol!=-1){
                sol&=v[j];
            }
            else{
                sol=v[j];
            }
        }
        // cout<<sol<<endl;
       return sol;
    }

void kush_gupta_solves(){
    int n=3;
    vector <int> v={3,5,11};
    int res=maxAnd(3,v);
    cout<<res<<endl;
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