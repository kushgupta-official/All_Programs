# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>

void fastIO(){
	ios::sync_with_stdio(0);
   	cin.tie(0);
    cout.tie(0);
}

int main()
{
	fastIO();
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
   	freopen("output.txt", "w", stdout) ;
   	#endif
	set <ll> inputs;
	ll n=0;
	cin>>n;
	ll temp=0;
	ll sum=0;
	for (ll i=0;i<n;i++){
		cin>>temp;
		inputs.insert(temp);
		if (temp<*(inputs.end()))
			sum+=distance(inputs.upper_bound(temp),inputs.end());
	}
	cout<<sum<<endl;
	return 0;
}