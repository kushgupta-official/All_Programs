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

bool comp(ll a,ll b){
	return a>b;
}

int main(){
	kush_gupta();
	ll n=0;
	cin>>n;
	ll sum=0;
	vector <ll> arr(n);
	for (ll i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(), arr.end(), comp);
	bool flag=0;
	for (ll i=0;i<n;i++){
		if (arr[i]>0){
			sum+=arr[i];
			flag=1;
		}
		else if (arr[i]<=0 && flag==0){
			sum+=arr[i];
			break;
		}
		else if (arr[i]<=0 && flag==1){
			break;
		}
	}
	cout<<sum;
	return 0;
}