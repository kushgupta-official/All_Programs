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
	ll n=0,m=0,k=0;
	cin>>n>>m>>k;
	vector <ll> a(n),b(m);
	for (ll i=0;i<n;i++){
		cin>>a[i];
	}
	for (ll i=0;i<m;i++){
		cin>>b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll res=0;
	ll i=0,j=0;
	while (i<n && j<m){
		if (b[j]+k>=a[i] && b[j]-k<=a[i]){
			res++;
			i++;
			j++;
		}
		else{
			if (a[i]<b[j]){
				i++;
			}
			else{
				j++;
			}
		}
	}
	cout<<res;
	return 0;
}