# include <bits/stdc++.h>
# define ll long long int

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		// auto __start = chrono::high_resolution_clock::now(); 
		freopen("input.txt", "r", stdin) ;
  		freopen("output.txt", "w", stdout) ;
	#endif
	ll n=0,x=0;
	cin>>n>>x;
	vector <pair <ll,ll> > a(n);
	for (ll i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i+1;
	}
	sort(a.begin(), a.end());
	ll i=0,j=n-1;
	while(i<j){
		if (a[i].first + a[j].first == x){
			cout<<a[i].second<<" "<<a[j].second<<endl;
			return 0;
		}
		else if (a[i].first + a[j].first < x){
			i++;
		}
		else{
			j--;
		}
	}
	cout<<"IMPOSSIBLE\n";
}