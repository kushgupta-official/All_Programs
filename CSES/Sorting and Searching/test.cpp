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
        vll front(n),back(n);
        loop(i,0,n){
            cin>>front[i];
        }
        loop(i,0,n){
            cin>>back[i];
        }
        map <ll,ll> mp1,mp2;
        ll mx1=INT_MIN,mx2=INT_MIN;
        ll e=INT_MIN;
        loop(i,0,n){
            if (front[i]==back[i]){
                mp1[front[i]]++;
            }
            else{
                mp1[front[i]]++;
                mp1[back[i]]++;
            }
            // mp1[front[i]]++;
            // if (mp1[front[i]]>mx1){
            //     mx1=mp1[front[i]];
            //     e1=front[i];
            // }
            // // mp2[back[i]]++;
            // if (mp2[back[i]]>mx2){
            //     mx1=mp2[back[i]];
            //     e1=back[i];
            // }
        }
        mx1=INT_MIN;
        for (auto i:mp1){
            if (mx1<i.second){
                mx1=i.second;
                e=i.first;
            }
            else if (mx1==i.second){
                e=max(e,i.first);
            }
        }
        // cout<<"e="<<e<<endl;
        ll flips=0;
        vll res(n);
        loop(i,0,n){
            if (front[i]==e){
                res[i]=front[i];
            }
            else if (back[i]==e){
                res[i]=back[i];
                flips++;
            }
            else{
                if (front[i]<back[i]){
                    res[i]=back[i];
                    flips++;
                }
                else{
                    res[i]=front[i];
                }
            }
        }
        ll sol=res[0];
        for (ll i=1;i<n;i++){
            sol=sol & res[i];
        }
        if (sol==0)
            flips=0;
        cout<<sol<<" "<<flips<<endl;
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