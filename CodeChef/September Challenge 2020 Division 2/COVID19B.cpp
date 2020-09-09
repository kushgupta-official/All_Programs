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
	// if(n==3){ 
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
		//	cout<<i<<endl;
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}
	// for (ll i=1;i<=n;i++){
	// 	cout<<arr[i]<<" ";
	// }cout<<endl;
	cout<<min<<" "<<max<<endl;
	// }
	// else{
	// ll effect[n+1];
	// for (ll i=n;i>0;i--){
	// 	effect[i]=0;
	// 	for (ll j=i-1;j>0;j--){
	// 		if ((i-j)<((i+speed[i]*1)-(j+speed[j]*1))){
	// 			effect[i]++;
	// 		}
	// 	}
	// }
	// ll min=INT_MAX,max=INT_MIN;
	// for (ll i=1;i<=n;i++){
	// 	for (ll j=i+1;j<=n;j++){
	// 		if (((j+speed[j]*1)-(i+speed[i]*1))<(j-i)){
	// 			arr[i]+=effect[j];
	// 			arr[j]++;
	// 		}
	// 	}
	// 	if(arr[i]>max){
	// 		max=arr[i];
	// 	//	cout<<i<<endl;
	// 	}
	// 	if(arr[i]<min){
	// 		min=arr[i];
	// 	}
	// }
	// cout<<min<<" "<<max<<endl;
 //  }
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
/*Failed Test Cases:
5
2 2 2 1 1
5
2 2 1 1 1
5
2 1 1 1 1
4
2 2 1 1
*/
/*
14
3
1 2 3
3
3 2 1
3
0 0 0
3
1 3 2
4
4 2 2 3
5
3 2 4 1 5
5
5 5 0 0 0
5
1 2 3 4 5
4
0 0 0 1
4
0 1 0 1
5
2 2 2 1 1
5
2 2 1 1 1
5
2 1 1 1 1
4
2 2 1 1
*/