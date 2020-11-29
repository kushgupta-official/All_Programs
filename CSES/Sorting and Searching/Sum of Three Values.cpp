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

int main(){
	kush_gupta();
	ll n=0,x=0;
	cin>>n>>x;
	vector <pair <ll,ll> > a(n);
	// unordered_map <ll,bool> ump;
	for (ll i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i+1;
		// ump[a[i]]=1;
	}
	sort (a.begin(), a.end());
	// for (ll i=0;i<n;i++){
	// 	cout<<a[i].first<<" ";
	// }
	// cout<<endl;
	for (ll i=0;i<n;i++){
		ll size=n-1;
		ll sum_wanted=x-a[i].first;
		if (sum_wanted<0){
			cout<<"IMPOSSIBLE";
			return 0;
		}
		ll j=i+1;
		while (j<size){
			if (a[j].first+a[size].first>sum_wanted){
				size--;
			}
			else if (a[j].first+a[size].first<sum_wanted){
				j++;
			}
			else if (a[j].first+a[size].first==sum_wanted){
				cout<<a[i].second<<" "<<a[j].second<<" "<<a[size].second;
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE";
	return 0;
}