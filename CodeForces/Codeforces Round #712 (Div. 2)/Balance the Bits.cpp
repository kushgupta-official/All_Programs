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
		ll n=0;
		cin>>n;
		string s;
		cin>>s;
		string a,b;
		if (s[0]=='0' or s[n-1]=='0'){
			cout<<"NO\n";
			continue;
		}
		vll ones,zeroes;
		loop(i,1,n-1){
			if (s[i]=='1')
				ones.push_back(i);
			else
				zeroes.push_back(i);
		}
		if (ones.size()%2 or zeroes.size()%2){
			cout<<"NO\n";
			continue;
		}
		a=s;
		b=s;
		a[0]='('; a[n-1]=')';
		b[0]='('; b[n-1]=')';
		bool alter=0;
		loop(i,0,zeroes.size()){
			if (alter==0){
				a[zeroes[i]]='(' ;
				b[zeroes[i]]=')' ;
			}
			else{
			   b[zeroes[i]]='(' ;
			   a[zeroes[i]]=')' ;
			}
			alter=!alter;
		}
		loop(i,0,ones.size()/2){
			a[ones[i]]='(';
			b[ones[i]]='(';
		}
		loop(i,ones.size()/2,ones.size()){
			a[ones[i]]=')';
			b[ones[i]]=')';
		}
		cout<<"YES\n";
		cout<<a<<endl;
		cout<<b<<endl;
		
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