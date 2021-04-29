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

bool comp(pair <ll,ll> p1,pair <ll,ll> p2){
	if (p1.first==p2.first)
		return p1.second>p2.second;
	return p1.first<p2.first;
}

void kush_gupta_solves(){
	w(t){
		ll n=0;
		cin>>n;
		vp v(n);
		// map <ll,ll> mp;
		ll sum=0;
		loop(i,0,n){
			cin>>v[i].first;
			// mp[v[i].fi]++;
		}
		loop(i,0,n){
			cin>>v[i].second;
			sum+=v[i].second;
		}
		sort(v.begin(), v.end(),comp);
		vvl matrix(n+1);
		loop(i,0,n){
			matrix[v[i].fi].push_back(v[i].se);
		}
		vvl presum;
		for (ll i=1;i<=n;i++){
			vll temp;
			for (ll j=0;j<matrix[i].size();j++){
				if (j==0)
					temp.pb(matrix[i][j]);
				else
					temp.pb(matrix[i][j]+temp[j-1]);
			}
			if (!temp.empty())
				presum.pb(temp);
		}
		ll k=1;
		cout<<sum<<" ";
		loop(i,1,n){
			k++;
			sum=0;
			bool flag=1;
			if (flag){
				for (ll i=0;i<presum.size();i++){
					ll x=presum[i].size()-(presum[i].size()%k)-1;
					if (x>=0)
						sum+=presum[i][x];
				}
				cout<<sum<<" ";
				if (sum==0)
					flag=0;
			}
			else
				cout<<0<<" ";
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