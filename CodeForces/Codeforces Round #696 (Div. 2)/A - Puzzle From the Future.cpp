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
		ll n=0;
		cin>>n;
		string b;
		cin>>b;
		string a;
		// string c;
		a.push_back('1');
		// c.push_back(a[0]+b[0]-'0');
		// cout<<c<<endl;
		for (ll i=1;i<b.length();i++){
			char ch=a[i-1]+b[i-1]-'0';
			if (b[i]=='0'){
				if (ch=='0' || ch=='2'){
					a.push_back('1');
				}
				else{
					a.push_back('0');
				}
			}
			else if (b[i]=='1'){
				if (ch=='0' || ch=='1'){
					a.push_back('1');
				}
				else{
					a.push_back('0');
				}
			}
		}
		cout<<a<<endl;
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