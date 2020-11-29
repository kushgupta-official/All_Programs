# include <bits/stdc++.h>
# define ll long long int
# define f first
# define s second
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
	sort(a.begin(), a.end());
	ll i=0,j=n-1;
	for (ll i=0;i<n;i++){
		for (ll j=i+1;j<n;j++){
			ll desired_sum=x-(a[i].f+a[j].f);
			if (desired_sum<0){
				break;
			}
			ll p=j+1;
			ll q=n-1;
			while(p<q){
				if (a[p].f+a[q].f>desired_sum){
					q--;
				}
				else if(a[p].f+a[q].f<desired_sum){
					p++;
				}
				else{
					cout<<a[i].s<<" "<<a[p].s<<" "<<a[q].s<<" "<<a[j].s;
					return 0;
				}
			}
		}
	}
	cout<<"IMPOSSIBLE";
	return 0;
}