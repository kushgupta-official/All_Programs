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
	ll n=0;
	cin>>n;
	ll sum=(n*(n+1))/2;
	if (sum%2!=0){
		cout<<"NO";
	}
	else{
		cout<<"YES\n";
		vector <ll> a(n);
		for (ll i=1;i<=n;i++){
			a[i-1]=i;
		}
		ll total1=sum/2,total2=sum/2;
		vector <ll> arr1,arr2;
		for (ll i=n-1;i>=0;i--){
			// cout<<a[i]<<" ";
			if (a[i]<=total1){
				arr1.push_back(a[i]);
				total1-=a[i];
			}
			else{
				arr2.push_back(a[i]);
				total2-=a[i];
			}
		}
		cout<<arr1.size()<<endl;
		for (int i=0;i<arr1.size();i++){
			cout<<arr1[i]<<" ";
		}
		cout<<endl;
		cout<<arr2.size()<<endl;
		for (int i=0;i<arr2.size();i++){
			cout<<arr2[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}