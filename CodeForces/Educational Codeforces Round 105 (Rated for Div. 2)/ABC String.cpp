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
		string a;
		cin>>a;
		char opening=a[0];
		char closing=a[a.size()-1];
		if (opening==closing){
			cout<<"NO";
		}
		else{
			ll x=0;
			ll y=0;
			ll z=0;
			for (ll i=0;i<a.size();i++){
				if (a[i]==opening){
					x++;
				}
				else if (a[i]==closing){
					y++;
				}
				else{
					z++;
				}
			}
			bool flag=0;
			ll mid;
			if (x==y and z==0){
				flag=1;
			}
			else if (x>y and z==x-y){
				flag=1;
				mid=-1; 
			}
			else if (y>x and z==y-x){
				flag=1;
				mid=1;
			}
			if (flag){
				ll sum=0;
				for (ll i=0;i<a.size();i++){
					if (a[i]==opening){
						sum+=1;
					}
					else if (a[i]==closing){
						sum-=1;
					}
					else{
						sum+=mid;
					}
					if (sum<0){
						flag=0;
						break;
					}
				}
				if (flag){
					cout<<"YES";
				}
				else{
					cout<<"NO";
				}
			}
			else{
				cout<<"NO";
			}
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