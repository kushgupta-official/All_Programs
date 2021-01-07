# include <bits/stdc++.h>

using namespace std;
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

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif

	w(t){
		ll n=0, q=0;
		cin>>n>>q;
		string s;
		cin>>s;

		vector <ll> subs(n,0);
		vector <ll> check(n,0);
		for (ll i=0;i+2<n;i++){
			if (s[i]==s[i+1] || s[i]==s[i+2] || s[i+1]==s[i+2]){
				subs[i]=1;
			}
		} 
		// if (s.size()%3!=0){
		// 	ll i=s.size()-3;
		// 	if (s[i]==s[i+1] || s[i]==s[i+2] || s[i+1]==s[i+2]){
		// 		subs[i]=1;
		// 	}
		// }
		check[0]=subs[0];
		loop(i,1,n){
			check[i]=check[i-1]+subs[i];
			// cout<<check[i]<<" ";
		}
		// cout<<endl;
		while(q--){
			ll x=0, y=0;
			cin>>x>>y;
			if ((y-x+1)<3){
				cout<<"NO\n";
			}
			else{
				bool flag=0;
				x--;y--;
				// for (ll i=x;i<=y-2;i++){
				// 	if (subs[i]==1){
				// 		cout<<"YES\n";
				// 		flag=1;
				// 		break;
				// 	}
				// }
				if (check[y-2]-(x-1>=0?check[x-1]:0)){
					cout<<"YES\n";
				}
				else{
					cout<<"NO\n";
				}
				// if (!flag){
				// 	cout<<"NO\n";
				// }
			}
		}
	}	

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif
	return 0;
}