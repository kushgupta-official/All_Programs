# include <bits/stdc++.h>
# define ll long long int

using namespace std;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int main(){
	kush_gupta();
	ll n=0,cnt=0;
	cin>>n;
	vector<ll> v(n);
	multimap <pair<ll,ll> ,ll> mp;
	for (ll i=0;i<n;i++){
		ll x=0,y=0;
		cin>>x>>y;
		mp.insert({{x,y},i});
	}
	priority_queue <pair<ll,ll>,vector <pair<ll,ll> >,greater <pair <ll,ll> >> pq;
	for (auto i=mp.begin();i!=mp.end();i++){
		ll a=0,b=0,c=0;
		a=i->first.first;	//arival
		b=i->first.second;	//departure
		if (pq.empty() || pq.top().first>=a){
			c=++cnt;
		}
		else{
			c=pq.top().second;
			pq.pop();
		}
		pq.push({b,c});
		v[i->second]=c;	//assigning room numbers
	}
	cout<<cnt<<endl;
	for (ll i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}