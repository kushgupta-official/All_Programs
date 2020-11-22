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
	for (ll i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i+1;
	}
	if (n!=1){
	sort(a.begin(), a.end());
	for (ll i=0;i<n;i++){
		ll toFind=x-a[i].first;
		ll f=i+1,s=n-1,mid=-1;
		while(f<=s){
			mid=f+(s-f)/2;
			if (a[mid].first==toFind){
				break;
			}
			else if(a[mid].first>toFind){
				s=mid-1;
			}
			else{
				f=mid+1;
			}
		}
		if(a[mid].first==toFind){
			cout<<a[i].second<<" "<<a[mid].second;
			return 0;
		}
	}
	}
	cout<<"IMPOSSIBLE";
	return 0;
}