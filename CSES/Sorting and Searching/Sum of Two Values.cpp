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
	ll i=0,j=1;
	ll sum=-1;
	while (i<j){
		sum=a[i]+a[j];
		if (sum<x){
			j++;
		}
		else if (sum>x){
			j--;
			i++;
		}
		else{
			break;
		}
	}
	if (i>=j){
		cout<<"IMPOSSIBLE";
	}
	else{
		cout<<i+1<<" "<<j+1;
	}
	return 0;
}