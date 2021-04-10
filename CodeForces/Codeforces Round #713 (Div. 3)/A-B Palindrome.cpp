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
		ll a=0,b=0;
		cin>>a>>b;
		string s;
		cin>>s;
		ll n=s.length();
		loop(i,0,n){
			if (s[i]=='0')
				a--;
			else if (s[i]=='1')
				b--;
		}
		vll v;
		ll m=n%2==0 ? n/2-1 : n/2;
		for (ll i=0;i<=m;i++){
			if (s[i]!=s[n-i-1]){
				if (s[i]=='?'){
					s[i]=s[n-i-1];
					s[n-i-1]=='0' ? a-- : b--;
				}
				else if (s[n-i-1]=='?'){
					s[n-i-1]=s[i];
					s[i]=='0' ? a-- : b--;
				}
				else{
					a=-1;
					b=-1;
					break;
				}
			}
			else if (s[i]=='?' and s[n-i-1]=='?'){
				v.push_back(i);
			}
		}
		if (a<0 or b<0){
			cout<<-1<<endl;
		}
		else{
			loop(i,0,v.size()){
				if (v[i]==n-v[i]-1){
					if (a>0){
						a--;
						s[v[i]]='0';
					}
					else{
						b--;
						s[v[i]]='1';
					}
				}
				else if (a>1){
					s[v[i]]='0';
					s[n-v[i]-1]='0';
					a-=2;
				}
				else if (b>1){
					s[v[i]]='1';
					s[n-v[i]-1]='1';
					b-=2;
				}
			}
			if (a!=0 or b!=0){
				cout<<-1<<endl;
			}
			else{
				cout<<s<<endl;
			}
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