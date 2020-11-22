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
	vector <ll> a(n);
	for (ll i=0;i<n;i++){
		cin>>a[i];
	}	
	sort(a.begin(), a.end());
	ll res=0,i=0,j=n-1;
	while(i<j){
		if (a[i]+a[j]<=x){
			res++;
			i++;
			j--;
		}
		else{
			res++;
			j--;
		}
	}
	if(i==j)
		cout<<res+1;
	else
		cout<<res;
	return 0;
}