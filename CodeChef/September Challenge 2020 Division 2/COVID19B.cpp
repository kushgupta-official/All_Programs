# include <bits/stdc++.h>
# define ll long long int
using namespace std;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	ll n=0;
	cin>>n;
	ll arr[n+1];
	ll speed[n+1];
	for (ll i=1;i<=n;i++){
		cin>>speed[i];
		arr[i]=1;
	}
	ll min=INT_MAX,max=INT_MIN;
	for (ll i=1;i<=n;i++){
		for (ll j=i+1;j<=n;j++){
			if (((j+speed[j]*5)-(i+speed[i]*5))<(j-i)){
				arr[i]++;
				arr[j]++;
			}
		}
		if(arr[i]>max){
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}
	cout<<min<<" "<<max<<endl;
}

int main(){
	kush_gupta();
	ll test_cases=0;
	cin>>test_cases;
	while(test_cases--){
		solve();
	}
	return 0;
}