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
        ll k=0,n=0,m=0;
        cin>>k>>n>>m;
        vll a(n),b(m);
        vll res;
        bool flag=1;
        loop(i,0,n){
            cin>>a[i];
        }
        loop(i,0,m){
            cin>>b[i];
        }
        ll i=0,j=0;
        while(i<n and j<m){
            if (a[i]==0){
                res.push_back(a[i]);
                k++;
                i++;
            }
            else if (b[j]==0){
                res.push_back(b[j]);
                k++;
                j++;
            }
            else{
                if (a[i]<b[j]){
                    if (a[i]>k){
                        flag=0;
                        break;
                    }
                    res.push_back(a[i]);
                    i++;
                }
                else{
                    if (b[j]>k){
                        flag=0;
                        break;
                    }
                    res.push_back(b[j]);
                    j++;
                }
            }
        }
        while(i<n){
            if (a[i]==0){
                res.push_back(a[i]);
                i++;
                k++;
            }
            else if (a[i]>k){
                flag=0;
                break;
            }
            else{
                res.push_back(a[i]);
                i++;
            }
        }
        while(j<m){
            if (b[j]==0){
                res.push_back(b[j]);
                j++;
                k++;
            }
            else if (b[j]>k){
                flag=0;
                break;
            }
            else{
                res.push_back(b[j]);
                j++;
            }
        }
        if (!flag){
            cout<<-1<<endl;
        }
        else{
            for (auto i:res){
                cout<<i<<" ";
            }
            cout<<endl;
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