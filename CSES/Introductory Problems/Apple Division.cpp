# include <bits/stdc++.h>
# define ll long long int
using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}
ll res=INT_MAX,x=0;
ll temp_sum1=0,temp_sum2=0;
vector <ll> w1;

ll sum(){
	ll toReturn=0;
	for (ll i=0;i<w1.size();i++){
		toReturn+=w1[i];
	}
	return toReturn;
}

void min_diff(ll n,const vector <ll> &w, ll x){
	if (x==n){
		// cout<<"ji";
		res=min(res,abs(temp_sum2-temp_sum1));
	}
	else{
		w1.push_back(w[x]);
		temp_sum1-=w[x];
		temp_sum2+=w[x];
		// x++;
		res=min(res,abs(temp_sum2-temp_sum1));
		min_diff(n,w,x+1);
		temp_sum1+=w1.back();
		temp_sum2-=w1.back();
		w1.pop_back();
		// x++;
		res=min(res,abs(temp_sum2-temp_sum1));
		min_diff(n,w,x+1);
	}
}

int main(){
	kush_gupta();
	ll n=0;
	cin>>n;
	vector <ll> weights(n);
	for (ll i=0;i<n;i++){
		cin>>weights[i];
		temp_sum1+=weights[i];
	}
		// cout<<"hi";

	min_diff(n,weights,x);
	//cout<<"hi";
	cout<<res;
	return 0;
}