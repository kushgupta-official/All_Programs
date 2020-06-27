# include <bits/stdc++.h>
using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
int main(){
	ll n=0,m=0;
	cin>>n>>m;
	std::vector<pair<ll,ll> > arr1(n);
	std::vector<pair<ll,ll> > arr2(m);

	rep(i,0,n){
		cin>>arr1[i].first;
		arr1[i].second=i;
	}
	rep(i,0,m){
		cin>>arr2[i].first;
		arr2[i].second=i;
	}
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());

	rep(i,0,m){
		cout<<arr1[0].second<<" "<<arr2[i].second<<endl;
	}

	rep(i,1,n){
		cout<<arr1[i].second<<" "<<arr2[m-1].second<<endl;
	}
	return 0;
}