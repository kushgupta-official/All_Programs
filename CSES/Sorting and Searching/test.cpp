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
		ll res=0;
		cin>>n;
		string s;
		cin>>s;
		ll mn=INT_MAX;
		ll prevOne=-1;
		ll cz=0,co=0;
		ll firstOne=-1,sum=0;
		// ll mx=INT_MIN;
		// map <ll,ll> gaps;
		loop(i,0,n){
			if (s[i]=='0'){
				cz++;
			}
			else if (s[i]=='1'){
				co++;
			}
			if (s[i]=='1'){
				if (prevOne==-1){
					prevOne=i;
					firstOne=i;
				}
				else{
					mn=min(mn,i-prevOne);
					// gaps[i-prevOne]++;
					// mx=max(mx,gaps[i-prevOne]);
					sum++;
					prevOne=i;
				}
			}
		}
		// cout<<firstOne<<" "<<prevOne<<endl;
		mn=min(mn,n-(prevOne-firstOne));
		// cout<<mn<<endl;
		if (mn==INT_MAX){
			cout<<1<<endl;
		}
		else if (co==1){
			cout<<0<<endl;
		}
		else if (co==0){
			cout<<1<<endl;
		}
		else{
			// ll i=firstOne+mn;
			ll i;
			for (i=firstOne+mn;i<s.size();i+=mn){
				// cout<<i<<endl;
				// i=i+mn;
				if (s[i]=='0'){
					res++;
					s[i]='1';
				}
			}
			if (s[i%n]=='0'){
				res++;
				s[i]='1';
			}
			prevOne=-1;
			ll mn2=INT_MAX;
			loop(i,0,n){
				if (s[i]=='1'){
					if (prevOne==-1){
						prevOne=i;
						// firstOne=i;
					}
					else{
						mn2=min(mn2,i-prevOne);
						prevOne=i;
					}
				}
			}
			mn2=min(mn2,n-(prevOne-firstOne));
			if (mn2!=mn){
				cout<<min(co-1,cz)<<endl;
			}	
			else{
				cout<<min(co-1,res)<<endl;
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